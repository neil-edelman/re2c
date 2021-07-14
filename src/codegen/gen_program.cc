#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>

#include "config.h"
#include "src/codegen/code.h"
#include "src/codegen/helpers.h"
#include "src/msg/msg.h"
#include "src/msg/warn.h"
#include "src/options/opt.h"
#include "src/encoding/enc.h"
#include "src/util/file_utils.h"
#include "src/util/string_utils.h"
#include "src/util/temp_file.h"
#include "src/util/uniq_vector.h"


namespace re2c {

static uint32_t write_converting_newlines(const std::string &str, FILE *f)
{
    const char *s = str.c_str(), *e = s + str.length();
    uint32_t lines = 0;

    // In order to maintain consistency we convert all newlines to LF when
    // writing output to file. Some newlines originate in user-defined code
    // (including semantic actions and code fragments in configurations and
    // directives), and some are generated by re2c itself.
    for (const char *p = s;; ++p) {
        size_t l = static_cast<size_t>(p - s);
        if (p == e) {
            fwrite(s, 1, l, f);
            break;
        } else if (*p == '\n') {
            ++lines;
            if (p > s && p[-1] == '\r') --l;
            fwrite(s, 1, l, f);
            s = p;
        }
    }

    return lines;
}

OutputBlock::OutputBlock(InputBlockKind kind, const std::string &name,
    const loc_t &loc)
    : kind(kind)
    , name(name)
    , loc(loc)
    , fragments()
    , used_yyaccept(false)
    , have_user_code(false)
    , conds()
    , stags()
    , mtags()
    , opts(NULL)
    , max_fill(1)
    , max_nmatch(1)
    , start_label(NULL)
    , fill_index_start(0)
    , fill_index_end(0)
    , fill_goto()
{}

OutputBlock::~OutputBlock ()
{
    delete opts;
}

Output::Output(Msg &msg)
    : cblocks()
    , hblocks()
    , pblocks(&cblocks)
    , label_counter(0)
    , state_goto(false)
    , cond_enum_in_hdr(false)
    , cond_goto(false)
    , warn_condition_order(true)
    , need_header(false)
    , done_mtag_defs(false)
    , msg(msg)
    , skeletons()
    , allocator()
    , scratchbuf(allocator)
    , total_fill_index(0)
    , total_opts(NULL)
{}

Output::~Output ()
{
    for (uint32_t i = 0; i < cblocks.size(); ++i) delete cblocks[i];
    for (uint32_t i = 0; i < hblocks.size(); ++i) delete hblocks[i];
}

void Output::header_mode(bool on)
{
    pblocks = on ? &hblocks : &cblocks;
}

bool Output::in_header() const
{
    return pblocks == &hblocks;
}

OutputBlock& Output::block()
{
    return *pblocks->back();
}

void Output::wraw(const char *s, const char *e, bool newline)
{
    if (s != e && block().opts->target == TARGET_CODE) {
        // scan for non-whitespace characters
        bool &code = block().have_user_code;
        for (const char *p = s; !code && p < e; ++p) {
            code = !isspace(*p);
        }
        wdelay_stmt(0, code_raw(allocator, s, static_cast<size_t>(e - s)));
    }
    if (newline && e > s && e[-1] != '\n') {
        // Insert newline unless the block ends in a newline.
        wdelay_stmt(0, code_newline(allocator));
    }
}

void Output::wversion_time()
{
    output_version_time(scratchbuf.stream(), block().opts);
    wdelay_stmt(0, code_textraw(allocator, scratchbuf.flush()));
}

void Output::wdelay_stmt(uint32_t ind, Code *stmt)
{
    OutputFragment f = {stmt, ind};
    block().fragments.push_back(f);
}

void Output::new_block(Opt &opts, InputBlockKind kind, const std::string &name,
    const loc_t &loc)
{
    OutputBlock *b = new OutputBlock(kind, name, loc);

    // Prefix autogenerated names with a special symbol to avoid collision with
    // user-defined names. Embed line information in the autogenerated name to
    // make it easier to correlate names with source code.
    if (kind == INPUT_USE) {
        // `use:re2c` blocks have autogenerated names that differ from the name
        // of the `rules:re2c` block that they are using, so the user cannot
        // reference a `use:re2c` block in any way. (They can easily achieve the
        // same goal with the help of the `!use` directive in a normal block.)
        b->name = "#line_" + to_string(loc.line) + "_block_use_" + name;
    } else if (name.empty()) {
        // Append block number, as the line may be non-unique (it is possible to
        // have multiple blocks on the same line, included files may define
        // blocks at the same line, and line directives may reset line number).
        b->name = "#line_" + to_string(loc.line) + "_block_" + to_string(pblocks->size());
    }

    // Check that the new block has a unique name.
    for (size_t i = 0; i < pblocks->size(); ++i) {
        if ((*pblocks)[i]->name == b->name) {
            msg.error(loc, "block named '%s' is already defined on line %u",
                b->name.c_str(), (*pblocks)[i]->loc.line);
            exit(1);
        }
    }

    b->opts = opts.snapshot();

    b->fill_index_start = total_fill_index;
    b->fill_index_end   = total_fill_index;

    pblocks->push_back(b);

    // start label hapens to be the only option
    // that must be reset for each new block
    opts.reset_group_startlabel();
}

void Output::gather_info_from_block()
{
    DASSERT(!pblocks->empty());
    const OutputBlock *b = pblocks->back();
    total_fill_index = b->fill_index_end;
}

static void fix_first_block_opts(const blocks_t &blocks)
{
    // If the initial block contains only whitespace and no user code,
    // then re2c options specified in the first re2c block are also
    // applied to the initial block.
    if (blocks.size() >= 2) {
        const OutputBlock *fst = blocks[0], *snd = blocks[1];
        if (!fst->have_user_code) {
            *const_cast<opt_t*>(fst->opts) = *snd->opts;
        }
    }
}

bool Output::emit_blocks(const std::string &fname, const CodegenCtxGlobal &globalctx)
{
    FILE *file = NULL, *temp = NULL;
    std::string filename = fname, tempname = fname;

    if (filename.empty()) {
        filename = "<stdout>";
        file = stdout;
    }
    else if ((temp = temp_file(tempname))) {
        file = temp;
    }
    else if (!(file = fopen(filename.c_str(), "w"))) {
        error("cannot open output file %s", filename.c_str());
        return false;
    }
    filename = escape_backslashes(filename);

    const blocks_t &blocks = *globalctx.pblocks;

    fix_first_block_opts(blocks);

    // First code generation pass: expand all delayed code blocks except labels.
    // Labels need to wait until the next pass because the first pass may add
    // transitions to previously unused labels (e.g. start label of a block that
    // is specified in a `getstate:re2c` directive).
    for (unsigned int j = 0; j < blocks.size(); ++j) {
        OutputBlock *b = blocks[j];
        CodegenCtxPass1 gctx = {&globalctx, b};

        for (size_t i = 0; i < b->fragments.size(); ++i) {
            expand_pass_1(gctx, b->fragments[i].code);
        }
    }

    // Second code generation pass: expand labels, combine/simplify statements,
    // convert newlines, write the generated code to a file.
    unsigned int line_count = 1;
    for (unsigned int j = 0; j < blocks.size(); ++j) {
        OutputBlock &b = *blocks[j];

        CodegenCtxPass2 gctx =
            { allocator
            , scratchbuf
            , b.opts
            };

        for (size_t i = 0; i < b.fragments.size(); ++i) {
            OutputFragment &f = b.fragments[i];
            std::ostringstream os;

            RenderContext rctx =
                { os
                , b.opts
                , msg
                , f.indent
                , filename.c_str()
                , line_count
                };

            expand_pass_2(gctx, f.code);
            combine(gctx, f.code);
            render(rctx, f.code);
            write_converting_newlines(os.str(), file);
        }
    }

    fclose(file);
    if (temp && !overwrite_file(tempname.c_str(), fname.c_str())) {
        error("cannot rename or write temporary file %s to output file %s"
            , tempname.c_str(), fname.c_str());
        remove(tempname.c_str());
        return false;
    }
    return true;
}

static void add_symbols(const OutputBlock &block, CodegenCtxGlobal &ctx)
{
    DASSERT(!block.name.empty());

    const std::string &condenumprefix = block.opts->condEnumPrefix;
    for (size_t j = 0; j < block.conds.size(); ++j) {
        ctx.conds.find_or_add(condenumprefix + block.conds[j]);
    }

    const tagnames_t &st = block.stags, &mt = block.mtags;
    ctx.stags.insert(st.begin(), st.end());
    ctx.mtags.insert(mt.begin(), mt.end());

    ctx.max_fill = std::max(ctx.max_fill, block.max_fill);
    ctx.max_nmatch = std::max(ctx.max_nmatch, block.max_nmatch);
}

bool Output::emit()
{
    if (msg.warn.error()) return false;

    CodegenCtxGlobal ctx =
        { allocator
        , scratchbuf
        , msg
        , total_opts
        , /*pblocks*/ NULL
        , /*conditions*/ uniq_vector_t<std::string>()
        , /*stags*/ tagnames_t()
        , /*mtags*/ tagnames_t()
        , /*max_fill*/ 1
        , /*max_nmatch*/ 1
        , warn_condition_order
        };

    // gather global data accumulated across all blocks and files
    for (uint32_t i = 0; i < cblocks.size(); ++i) {
        add_symbols (*cblocks[i], ctx);
    }
    for (uint32_t i = 0; i < hblocks.size(); ++i) {
        add_symbols (*hblocks[i], ctx);
    }

    // global options are last block's options
    const opt_t *opts = block().opts;
    bool ok = true;

    // emit .h file
    if (!opts->header_file.empty() || need_header) {
        // old-style -t, --type-headers usage implies condition generation
        if (!ctx.conds.empty() && !this->cond_enum_in_hdr) {
            header_mode(true);
            wdelay_stmt(0, code_newline(allocator));
            wdelay_stmt(0, code_fmt(allocator, CODE_COND_ENUM, NULL, NULL, NULL));
            header_mode(false);
        }

        ctx.pblocks = &hblocks;
        ok &= emit_blocks(opts->header_file, ctx);
    }

    // emit .c file
    ctx.pblocks = &cblocks;
    ok &= emit_blocks(opts->output_file, ctx);

    return ok;
}

void output_version_time(std::ostream &os, const opt_t *opts)
{
    os << (opts->lang == LANG_GO ? "// Code generated" : "/* Generated") << " by re2c";
    if (opts->version) {
        os << " " << PACKAGE_VERSION;
    }
    if (!opts->bNoGenerationDate) {
        os << " on ";
        time_t now = time(NULL);
        os.write(ctime(&now), 24);
    }
    os << (opts->lang == LANG_GO ? ", DO NOT EDIT." : " */");
}

Scratchbuf& Scratchbuf::yybm_char(uint32_t u, const opt_t *opts, int width)
{
    if (opts->yybmHexTable) {
        prtHex(os, u, opts->encoding.szCodeUnit());
    }
    else {
        u32_width(u, width);
    }
    return *this;
}

Scratchbuf& Scratchbuf::u32_width(uint32_t u, int width)
{
    os << std::setw(width);
    os << u;
    return *this;
}

Scratchbuf& Scratchbuf::exact_uint(size_t width)
{
    if (width == sizeof(char)) {
        os << "unsigned char";
    }
    else if (width == sizeof(short)) {
        os << "unsigned short";
    }
    else if (width == sizeof(int)) {
        os << "unsigned int";
    }
    else if (width == sizeof(long)) {
        os << "unsigned long";
    }
    else {
        os << "uint" << width * 8 << "_t";
    }
    return *this;
}

const char *Scratchbuf::flush()
{
    const size_t len = os.str().length();
    char *e = alc.alloct<char>(len + 1);
    memcpy(e, os.str().c_str(), len);
    e[len] = 0;
    os.str("");
    return e;
}

} // namespace re2c
