
#line 1 "cmmap.re"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

#define	ADDEQ	257
#define	ANDAND	258
#define	ANDEQ	259
#define	ARRAY	260
#define	ASM	261
#define	AUTO	262
#define	BREAK	263
#define	CASE	264
#define	CHAR	265
#define	CONST	266
#define	CONTINUE	267
#define	DECR	268
#define	DEFAULT	269
#define	DEREF	270
#define	DIVEQ	271
#define	DO	272
#define	DOUBLE	273
#define	ELLIPSIS	274
#define	ELSE	275
#define	ENUM	276
#define	EQL	277
#define	EXTERN	278
#define	FCON	279
#define	FLOAT	280
#define	FOR	281
#define	FUNCTION	282
#define	GEQ	283
#define	GOTO	284
#define	ICON	285
#define	ID	286
#define	IF	287
#define	INCR	288
#define	INT	289
#define	LEQ	290
#define	LONG	291
#define	LSHIFT	292
#define	LSHIFTEQ	293
#define	MODEQ	294
#define	MULEQ	295
#define	NEQ	296
#define	OREQ	297
#define	OROR	298
#define	POINTER	299
#define	REGISTER	300
#define	RETURN	301
#define	RSHIFT	302
#define	RSHIFTEQ	303
#define	SCON	304
#define	SHORT	305
#define	SIGNED	306
#define	SIZEOF	307
#define	STATIC	308
#define	STRUCT	309
#define	SUBEQ	310
#define	SWITCH	311
#define	TYPEDEF	312
#define	UNION	313
#define	UNSIGNED	314
#define	VOID	315
#define	VOLATILE	316
#define	WHILE	317
#define	XOREQ	318
#define	EOI	319

typedef unsigned int unint;
typedef unsigned char uchar;

#define	YYCTYPE		uchar
#define	YYCURSOR	cursor
#define	YYLIMIT		s->lim
#define	YYMARKER	s->ptr
#define	YYFILL(n)	{cursor = fill(s, cursor);}

#define	RET(i)	{s->cur = cursor; return i;}

typedef struct Scanner {
    uchar		*tok, *ptr, *cur, *pos, *lim, *eof;
    unint		line;
} Scanner;

uchar *fill(Scanner *s, uchar *cursor){
    if(!s->eof){
	unint cnt = s->lim - s->tok;
	uchar *buf = malloc((cnt + 1)*sizeof(uchar));
	memcpy(buf, s->tok, cnt);
	cursor = &buf[cursor - s->tok];
	s->pos = &buf[s->pos - s->tok];
	s->ptr = &buf[s->ptr - s->tok];
	s->lim = &buf[cnt];
	s->eof = s->lim; *(s->eof)++ = '\n';
	s->tok = buf;
    }
    return cursor;
}

int scan(Scanner *s){
	uchar *cursor = s->cur;
std:
	s->tok = cursor;
#line 116 "cmmap.re"



#line 7 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy0;
	++YYCURSOR;
yy0:
	if((YYLIMIT - YYCURSOR) < 9) YYFILL(9);
	yych = *YYCURSOR;
	switch(yych){
	case 0x09:	case 0x0B:
	case 0x0C:	case ' ':	goto yy73;
	case 0x0A:	goto yy75;
	case '!':	goto yy49;
	case '"':	goto yy28;
	case '%':	goto yy39;
	case '&':	goto yy41;
	case '\'':	goto yy24;
	case '(':	goto yy61;
	case ')':	goto yy63;
	case '*':	goto yy37;
	case '+':	goto yy33;
	case ',':	goto yy57;
	case '-':	goto yy35;
	case '.':	goto yy26;
	case '/':	goto yy2;
	case '0':	goto yy21;
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy23;
	case ':':	goto yy59;
	case ';':	goto yy51;
	case '<':	goto yy31;
	case '=':	goto yy47;
	case '>':	goto yy29;
	case '?':	goto yy71;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'h':	case 'j':
	case 'k':	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':	case 'x':
	case 'y':
	case 'z':	goto yy20;
	case '[':	goto yy65;
	case ']':	goto yy67;
	case '^':	goto yy43;
	case 'a':	goto yy4;
	case 'b':	goto yy6;
	case 'c':	goto yy7;
	case 'd':	goto yy8;
	case 'e':	goto yy9;
	case 'f':	goto yy10;
	case 'g':	goto yy11;
	case 'i':	goto yy12;
	case 'l':	goto yy13;
	case 'r':	goto yy14;
	case 's':	goto yy15;
	case 't':	goto yy16;
	case 'u':	goto yy17;
	case 'v':	goto yy18;
	case 'w':	goto yy19;
	case '{':	goto yy53;
	case '|':	goto yy45;
	case '}':	goto yy55;
	case '~':	goto yy69;
	default:	goto yy77;
	}
yy2:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '*':	goto yy341;
	case '=':	goto yy339;
	default:	goto yy3;
	}
yy3:
#line 205 "cmmap.re"
{ RET('/'); }
#line 115 "<stdout>"
yy4:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case 'u':	goto yy335;
	default:	goto yy180;
	}
yy5:
#line 154 "cmmap.re"
{ RET(ID); }
#line 124 "<stdout>"
yy6:	yych = *++YYCURSOR;
	switch(yych){
	case 'r':	goto yy330;
	default:	goto yy180;
	}
yy7:	yych = *++YYCURSOR;
	switch(yych){
	case 'a':	goto yy311;
	case 'h':	goto yy312;
	case 'o':	goto yy313;
	default:	goto yy180;
	}
yy8:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy297;
	case 'o':	goto yy298;
	default:	goto yy180;
	}
yy9:	yych = *++YYCURSOR;
	switch(yych){
	case 'l':	goto yy283;
	case 'n':	goto yy284;
	case 'x':	goto yy285;
	default:	goto yy180;
	}
yy10:	yych = *++YYCURSOR;
	switch(yych){
	case 'l':	goto yy275;
	case 'o':	goto yy276;
	default:	goto yy180;
	}
yy11:	yych = *++YYCURSOR;
	switch(yych){
	case 'o':	goto yy271;
	default:	goto yy180;
	}
yy12:	yych = *++YYCURSOR;
	switch(yych){
	case 'f':	goto yy266;
	case 'n':	goto yy268;
	default:	goto yy180;
	}
yy13:	yych = *++YYCURSOR;
	switch(yych){
	case 'o':	goto yy262;
	default:	goto yy180;
	}
yy14:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy249;
	default:	goto yy180;
	}
yy15:	yych = *++YYCURSOR;
	switch(yych){
	case 'h':	goto yy216;
	case 'i':	goto yy217;
	case 't':	goto yy218;
	case 'w':	goto yy219;
	default:	goto yy180;
	}
yy16:	yych = *++YYCURSOR;
	switch(yych){
	case 'y':	goto yy209;
	default:	goto yy180;
	}
yy17:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy197;
	default:	goto yy180;
	}
yy18:	yych = *++YYCURSOR;
	switch(yych){
	case 'o':	goto yy186;
	default:	goto yy180;
	}
yy19:	yych = *++YYCURSOR;
	switch(yych){
	case 'h':	goto yy181;
	default:	goto yy180;
	}
yy20:	yych = *++YYCURSOR;
	goto yy180;
yy21:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 'L':	case 'U':	case 'l':	case 'u':	goto yy155;
	case 'X':	case 'x':	goto yy172;
	default:	goto yy171;
	}
yy22:
#line 158 "cmmap.re"
{ RET(ICON); }
#line 217 "<stdout>"
yy23:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	goto yy153;
yy24:	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 0x0A:	goto yy25;
	default:	goto yy143;
	}
yy25:
#line 224 "cmmap.re"
{
		printf("unexpected character: %c\n", *s->tok);
		goto std;
	    }
#line 233 "<stdout>"
yy26:	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case '.':	goto yy131;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy132;
	default:	goto yy27;
	}
yy27:
#line 198 "cmmap.re"
{ RET('.'); }
#line 253 "<stdout>"
yy28:	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 0x0A:	goto yy25;
	default:	goto yy121;
	}
yy29:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy114;
	case '>':	goto yy116;
	default:	goto yy30;
	}
yy30:
#line 208 "cmmap.re"
{ RET('>'); }
#line 269 "<stdout>"
yy31:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '<':	goto yy110;
	case '=':	goto yy108;
	default:	goto yy32;
	}
yy32:
#line 207 "cmmap.re"
{ RET('<'); }
#line 279 "<stdout>"
yy33:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '+':	goto yy104;
	case '=':	goto yy106;
	default:	goto yy34;
	}
yy34:
#line 203 "cmmap.re"
{ RET('+'); }
#line 289 "<stdout>"
yy35:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '-':	goto yy100;
	case '=':	goto yy102;
	case '>':	goto yy98;
	default:	goto yy36;
	}
yy36:
#line 202 "cmmap.re"
{ RET('-'); }
#line 300 "<stdout>"
yy37:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy96;
	default:	goto yy38;
	}
yy38:
#line 204 "cmmap.re"
{ RET('*'); }
#line 309 "<stdout>"
yy39:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy94;
	default:	goto yy40;
	}
yy40:
#line 206 "cmmap.re"
{ RET('%'); }
#line 318 "<stdout>"
yy41:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '&':	goto yy90;
	case '=':	goto yy92;
	default:	goto yy42;
	}
yy42:
#line 199 "cmmap.re"
{ RET('&'); }
#line 328 "<stdout>"
yy43:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy88;
	default:	goto yy44;
	}
yy44:
#line 209 "cmmap.re"
{ RET('^'); }
#line 337 "<stdout>"
yy45:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy86;
	case '|':	goto yy84;
	default:	goto yy46;
	}
yy46:
#line 210 "cmmap.re"
{ RET('|'); }
#line 347 "<stdout>"
yy47:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy82;
	default:	goto yy48;
	}
yy48:
#line 193 "cmmap.re"
{ RET('='); }
#line 356 "<stdout>"
yy49:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy80;
	default:	goto yy50;
	}
yy50:
#line 200 "cmmap.re"
{ RET('!'); }
#line 365 "<stdout>"
yy51:	++YYCURSOR;
	goto yy52;
yy52:
#line 188 "cmmap.re"
{ RET(';'); }
#line 371 "<stdout>"
yy53:	++YYCURSOR;
	goto yy54;
yy54:
#line 189 "cmmap.re"
{ RET('{'); }
#line 377 "<stdout>"
yy55:	++YYCURSOR;
	goto yy56;
yy56:
#line 190 "cmmap.re"
{ RET('}'); }
#line 383 "<stdout>"
yy57:	++YYCURSOR;
	goto yy58;
yy58:
#line 191 "cmmap.re"
{ RET(','); }
#line 389 "<stdout>"
yy59:	++YYCURSOR;
	goto yy60;
yy60:
#line 192 "cmmap.re"
{ RET(':'); }
#line 395 "<stdout>"
yy61:	++YYCURSOR;
	goto yy62;
yy62:
#line 194 "cmmap.re"
{ RET('('); }
#line 401 "<stdout>"
yy63:	++YYCURSOR;
	goto yy64;
yy64:
#line 195 "cmmap.re"
{ RET(')'); }
#line 407 "<stdout>"
yy65:	++YYCURSOR;
	goto yy66;
yy66:
#line 196 "cmmap.re"
{ RET('['); }
#line 413 "<stdout>"
yy67:	++YYCURSOR;
	goto yy68;
yy68:
#line 197 "cmmap.re"
{ RET(']'); }
#line 419 "<stdout>"
yy69:	++YYCURSOR;
	goto yy70;
yy70:
#line 201 "cmmap.re"
{ RET('~'); }
#line 425 "<stdout>"
yy71:	++YYCURSOR;
	goto yy72;
yy72:
#line 211 "cmmap.re"
{ RET('?'); }
#line 431 "<stdout>"
yy73:	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy79;
yy74:
#line 214 "cmmap.re"
{ goto std; }
#line 437 "<stdout>"
yy75:	++YYCURSOR;
	goto yy76;
yy76:
#line 217 "cmmap.re"
{
		if(cursor == s->eof) RET(EOI);
		s->pos = cursor; s->line++;
		goto std;
	    }
#line 447 "<stdout>"
yy77:	yych = *++YYCURSOR;
	goto yy25;
yy78:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy79;
yy79:	switch(yych){
	case 0x09:	case 0x0B:
	case 0x0C:	case ' ':	goto yy78;
	default:	goto yy74;
	}
yy80:	++YYCURSOR;
	goto yy81;
yy81:
#line 187 "cmmap.re"
{ RET(NEQ); }
#line 465 "<stdout>"
yy82:	++YYCURSOR;
	goto yy83;
yy83:
#line 186 "cmmap.re"
{ RET(EQL); }
#line 471 "<stdout>"
yy84:	++YYCURSOR;
	goto yy85;
yy85:
#line 183 "cmmap.re"
{ RET(OROR); }
#line 477 "<stdout>"
yy86:	++YYCURSOR;
	goto yy87;
yy87:
#line 176 "cmmap.re"
{ RET(OREQ); }
#line 483 "<stdout>"
yy88:	++YYCURSOR;
	goto yy89;
yy89:
#line 175 "cmmap.re"
{ RET(XOREQ); }
#line 489 "<stdout>"
yy90:	++YYCURSOR;
	goto yy91;
yy91:
#line 182 "cmmap.re"
{ RET(ANDAND); }
#line 495 "<stdout>"
yy92:	++YYCURSOR;
	goto yy93;
yy93:
#line 174 "cmmap.re"
{ RET(ANDEQ); }
#line 501 "<stdout>"
yy94:	++YYCURSOR;
	goto yy95;
yy95:
#line 173 "cmmap.re"
{ RET(MODEQ); }
#line 507 "<stdout>"
yy96:	++YYCURSOR;
	goto yy97;
yy97:
#line 171 "cmmap.re"
{ RET(MULEQ); }
#line 513 "<stdout>"
yy98:	++YYCURSOR;
	goto yy99;
yy99:
#line 181 "cmmap.re"
{ RET(DEREF); }
#line 519 "<stdout>"
yy100:	++YYCURSOR;
	goto yy101;
yy101:
#line 180 "cmmap.re"
{ RET(DECR); }
#line 525 "<stdout>"
yy102:	++YYCURSOR;
	goto yy103;
yy103:
#line 170 "cmmap.re"
{ RET(SUBEQ); }
#line 531 "<stdout>"
yy104:	++YYCURSOR;
	goto yy105;
yy105:
#line 179 "cmmap.re"
{ RET(INCR); }
#line 537 "<stdout>"
yy106:	++YYCURSOR;
	goto yy107;
yy107:
#line 169 "cmmap.re"
{ RET(ADDEQ); }
#line 543 "<stdout>"
yy108:	++YYCURSOR;
	goto yy109;
yy109:
#line 184 "cmmap.re"
{ RET(LEQ); }
#line 549 "<stdout>"
yy110:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy112;
	default:	goto yy111;
	}
yy111:
#line 178 "cmmap.re"
{ RET(LSHIFT); }
#line 558 "<stdout>"
yy112:	++YYCURSOR;
	goto yy113;
yy113:
#line 168 "cmmap.re"
{ RET(LSHIFTEQ); }
#line 564 "<stdout>"
yy114:	++YYCURSOR;
	goto yy115;
yy115:
#line 185 "cmmap.re"
{ RET(GEQ); }
#line 570 "<stdout>"
yy116:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy118;
	default:	goto yy117;
	}
yy117:
#line 177 "cmmap.re"
{ RET(RSHIFT); }
#line 579 "<stdout>"
yy118:	++YYCURSOR;
	goto yy119;
yy119:
#line 167 "cmmap.re"
{ RET(RSHIFTEQ); }
#line 585 "<stdout>"
yy120:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy121;
yy121:	switch(yych){
	case 0x0A:	goto yy122;
	case '"':	goto yy124;
	case '\\':	goto yy123;
	default:	goto yy120;
	}
yy122:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy22;
	case 3:	goto yy134;
	case 2:	goto yy27;
	case 1:	goto yy25;
	}
yy123:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case '"':	case '\'':	case '?':	case '\\':	case 'a':
	case 'b':	case 'f':	case 'n':	case 'r':	case 't':	case 'v':	goto yy120;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy127;
	case 'x':	goto yy126;
	default:	goto yy122;
	}
yy124:	++YYCURSOR;
	goto yy125;
yy125:
#line 164 "cmmap.re"
{ RET(SCON); }
#line 627 "<stdout>"
yy126:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy129;
	default:	goto yy122;
	}
yy127:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy128;
yy128:	switch(yych){
	case 0x0A:	goto yy122;
	case '"':	goto yy124;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy127;
	case '\\':	goto yy123;
	default:	goto yy120;
	}
yy129:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy130;
yy130:	switch(yych){
	case 0x0A:	goto yy122;
	case '"':	goto yy124;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy129;
	case '\\':	goto yy123;
	default:	goto yy120;
	}
yy131:	yych = *++YYCURSOR;
	switch(yych){
	case '.':	goto yy140;
	default:	goto yy122;
	}
yy132:	yyaccept = 3;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	goto yy133;
yy133:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy132;
	case 'E':	case 'e':	goto yy135;
	case 'F':	case 'L':	case 'f':	case 'l':	goto yy136;
	default:	goto yy134;
	}
yy134:
#line 161 "cmmap.re"
{ RET(FCON); }
#line 733 "<stdout>"
yy135:	yych = *++YYCURSOR;
	switch(yych){
	case '+':	case '-':	goto yy137;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy138;
	default:	goto yy122;
	}
yy136:	yych = *++YYCURSOR;
	goto yy134;
yy137:	yych = *++YYCURSOR;
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy138;
	default:	goto yy122;
	}
yy138:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy139;
yy139:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy138;
	case 'F':	case 'L':	case 'f':	case 'l':	goto yy136;
	default:	goto yy134;
	}
yy140:	++YYCURSOR;
	goto yy141;
yy141:
#line 166 "cmmap.re"
{ RET(ELLIPSIS); }
#line 789 "<stdout>"
yy142:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy143;
yy143:	switch(yych){
	case 0x0A:	goto yy122;
	case '\'':	goto yy145;
	case '\\':	goto yy144;
	default:	goto yy142;
	}
yy144:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case '"':	case '\'':	case '?':	case '\\':	case 'a':
	case 'b':	case 'f':	case 'n':	case 'r':	case 't':	case 'v':	goto yy142;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy147;
	case 'x':	goto yy146;
	default:	goto yy122;
	}
yy145:	yych = *++YYCURSOR;
	goto yy22;
yy146:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy149;
	default:	goto yy122;
	}
yy147:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy148;
yy148:	switch(yych){
	case 0x0A:	goto yy122;
	case '\'':	goto yy145;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy147;
	case '\\':	goto yy144;
	default:	goto yy142;
	}
yy149:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy150;
yy150:	switch(yych){
	case 0x0A:	goto yy122;
	case '\'':	goto yy145;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy149;
	case '\\':	goto yy144;
	default:	goto yy142;
	}
yy151:	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 'E':	case 'e':	goto yy162;
	default:	goto yy161;
	}
yy152:	yyaccept = 0;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	goto yy153;
yy153:	switch(yych){
	case '.':	goto yy151;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy152;
	case 'E':	case 'e':	goto yy154;
	case 'L':	case 'U':	case 'l':	case 'u':	goto yy155;
	default:	goto yy22;
	}
yy154:	yych = *++YYCURSOR;
	switch(yych){
	case '+':	case '-':	goto yy157;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy158;
	default:	goto yy122;
	}
yy155:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy156;
yy156:	switch(yych){
	case 'L':	case 'U':	case 'l':	case 'u':	goto yy155;
	default:	goto yy22;
	}
yy157:	yych = *++YYCURSOR;
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy158;
	default:	goto yy122;
	}
yy158:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy159;
yy159:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy158;
	case 'F':	case 'L':	case 'f':	case 'l':	goto yy136;
	default:	goto yy134;
	}
yy160:	yyaccept = 3;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	goto yy161;
yy161:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy160;
	case 'E':	case 'e':	goto yy166;
	case 'F':	case 'L':	case 'f':	case 'l':	goto yy136;
	default:	goto yy134;
	}
yy162:	yych = *++YYCURSOR;
	switch(yych){
	case '+':	case '-':	goto yy163;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy164;
	default:	goto yy122;
	}
yy163:	yych = *++YYCURSOR;
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy164;
	default:	goto yy122;
	}
yy164:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy165;
yy165:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy164;
	case 'F':	case 'L':	case 'f':	case 'l':	goto yy136;
	default:	goto yy134;
	}
yy166:	yych = *++YYCURSOR;
	switch(yych){
	case '+':	case '-':	goto yy167;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy168;
	default:	goto yy122;
	}
yy167:	yych = *++YYCURSOR;
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy168;
	default:	goto yy122;
	}
yy168:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy169;
yy169:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy168;
	case 'F':	case 'L':	case 'f':	case 'l':	goto yy136;
	default:	goto yy134;
	}
yy170:	yyaccept = 0;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	goto yy171;
yy171:	switch(yych){
	case '.':	goto yy151;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy170;
	case 'E':	case 'e':	goto yy154;
	case 'L':	case 'U':	case 'l':	case 'u':	goto yy177;
	default:	goto yy22;
	}
yy172:	yych = *++YYCURSOR;
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy173;
	default:	goto yy122;
	}
yy173:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy174;
yy174:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':	goto yy173;
	case 'L':	case 'U':	case 'l':	case 'u':	goto yy175;
	default:	goto yy22;
	}
yy175:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy176;
yy176:	switch(yych){
	case 'L':	case 'U':	case 'l':	case 'u':	goto yy175;
	default:	goto yy22;
	}
yy177:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy178;
yy178:	switch(yych){
	case 'L':	case 'U':	case 'l':	case 'u':	goto yy177;
	default:	goto yy22;
	}
yy179:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy180;
yy180:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy5;
	}
yy181:	yych = *++YYCURSOR;
	switch(yych){
	case 'i':	goto yy182;
	default:	goto yy180;
	}
yy182:	yych = *++YYCURSOR;
	switch(yych){
	case 'l':	goto yy183;
	default:	goto yy180;
	}
yy183:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy184;
	default:	goto yy180;
	}
yy184:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy185;
	}
yy185:
#line 152 "cmmap.re"
{ RET(WHILE); }
#line 1340 "<stdout>"
yy186:	yych = *++YYCURSOR;
	switch(yych){
	case 'i':	goto yy187;
	case 'l':	goto yy188;
	default:	goto yy180;
	}
yy187:	yych = *++YYCURSOR;
	switch(yych){
	case 'd':	goto yy195;
	default:	goto yy180;
	}
yy188:	yych = *++YYCURSOR;
	switch(yych){
	case 'a':	goto yy189;
	default:	goto yy180;
	}
yy189:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy190;
	default:	goto yy180;
	}
yy190:	yych = *++YYCURSOR;
	switch(yych){
	case 'i':	goto yy191;
	default:	goto yy180;
	}
yy191:	yych = *++YYCURSOR;
	switch(yych){
	case 'l':	goto yy192;
	default:	goto yy180;
	}
yy192:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy193;
	default:	goto yy180;
	}
yy193:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy194;
	}
yy194:
#line 151 "cmmap.re"
{ RET(VOLATILE); }
#line 1444 "<stdout>"
yy195:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy196;
	}
yy196:
#line 150 "cmmap.re"
{ RET(VOID); }
#line 1512 "<stdout>"
yy197:	yych = *++YYCURSOR;
	switch(yych){
	case 'i':	goto yy198;
	case 's':	goto yy199;
	default:	goto yy180;
	}
yy198:	yych = *++YYCURSOR;
	switch(yych){
	case 'o':	goto yy206;
	default:	goto yy180;
	}
yy199:	yych = *++YYCURSOR;
	switch(yych){
	case 'i':	goto yy200;
	default:	goto yy180;
	}
yy200:	yych = *++YYCURSOR;
	switch(yych){
	case 'g':	goto yy201;
	default:	goto yy180;
	}
yy201:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy202;
	default:	goto yy180;
	}
yy202:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy203;
	default:	goto yy180;
	}
yy203:	yych = *++YYCURSOR;
	switch(yych){
	case 'd':	goto yy204;
	default:	goto yy180;
	}
yy204:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy205;
	}
yy205:
#line 149 "cmmap.re"
{ RET(UNSIGNED); }
#line 1616 "<stdout>"
yy206:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy207;
	default:	goto yy180;
	}
yy207:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy208;
	}
yy208:
#line 148 "cmmap.re"
{ RET(UNION); }
#line 1689 "<stdout>"
yy209:	yych = *++YYCURSOR;
	switch(yych){
	case 'p':	goto yy210;
	default:	goto yy180;
	}
yy210:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy211;
	default:	goto yy180;
	}
yy211:	yych = *++YYCURSOR;
	switch(yych){
	case 'd':	goto yy212;
	default:	goto yy180;
	}
yy212:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy213;
	default:	goto yy180;
	}
yy213:	yych = *++YYCURSOR;
	switch(yych){
	case 'f':	goto yy214;
	default:	goto yy180;
	}
yy214:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy215;
	}
yy215:
#line 147 "cmmap.re"
{ RET(TYPEDEF); }
#line 1782 "<stdout>"
yy216:	yych = *++YYCURSOR;
	switch(yych){
	case 'o':	goto yy245;
	default:	goto yy180;
	}
yy217:	yych = *++YYCURSOR;
	switch(yych){
	case 'g':	goto yy235;
	case 'z':	goto yy236;
	default:	goto yy180;
	}
yy218:	yych = *++YYCURSOR;
	switch(yych){
	case 'a':	goto yy225;
	case 'r':	goto yy226;
	default:	goto yy180;
	}
yy219:	yych = *++YYCURSOR;
	switch(yych){
	case 'i':	goto yy220;
	default:	goto yy180;
	}
yy220:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy221;
	default:	goto yy180;
	}
yy221:	yych = *++YYCURSOR;
	switch(yych){
	case 'c':	goto yy222;
	default:	goto yy180;
	}
yy222:	yych = *++YYCURSOR;
	switch(yych){
	case 'h':	goto yy223;
	default:	goto yy180;
	}
yy223:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy224;
	}
yy224:
#line 146 "cmmap.re"
{ RET(SWITCH); }
#line 1887 "<stdout>"
yy225:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy231;
	default:	goto yy180;
	}
yy226:	yych = *++YYCURSOR;
	switch(yych){
	case 'u':	goto yy227;
	default:	goto yy180;
	}
yy227:	yych = *++YYCURSOR;
	switch(yych){
	case 'c':	goto yy228;
	default:	goto yy180;
	}
yy228:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy229;
	default:	goto yy180;
	}
yy229:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy230;
	}
yy230:
#line 145 "cmmap.re"
{ RET(STRUCT); }
#line 1975 "<stdout>"
yy231:	yych = *++YYCURSOR;
	switch(yych){
	case 'i':	goto yy232;
	default:	goto yy180;
	}
yy232:	yych = *++YYCURSOR;
	switch(yych){
	case 'c':	goto yy233;
	default:	goto yy180;
	}
yy233:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy234;
	}
yy234:
#line 144 "cmmap.re"
{ RET(STATIC); }
#line 2053 "<stdout>"
yy235:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy241;
	default:	goto yy180;
	}
yy236:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy237;
	default:	goto yy180;
	}
yy237:	yych = *++YYCURSOR;
	switch(yych){
	case 'o':	goto yy238;
	default:	goto yy180;
	}
yy238:	yych = *++YYCURSOR;
	switch(yych){
	case 'f':	goto yy239;
	default:	goto yy180;
	}
yy239:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy240;
	}
yy240:
#line 143 "cmmap.re"
{ RET(SIZEOF); }
#line 2141 "<stdout>"
yy241:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy242;
	default:	goto yy180;
	}
yy242:	yych = *++YYCURSOR;
	switch(yych){
	case 'd':	goto yy243;
	default:	goto yy180;
	}
yy243:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy244;
	}
yy244:
#line 142 "cmmap.re"
{ RET(SIGNED); }
#line 2219 "<stdout>"
yy245:	yych = *++YYCURSOR;
	switch(yych){
	case 'r':	goto yy246;
	default:	goto yy180;
	}
yy246:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy247;
	default:	goto yy180;
	}
yy247:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy248;
	}
yy248:
#line 141 "cmmap.re"
{ RET(SHORT); }
#line 2297 "<stdout>"
yy249:	yych = *++YYCURSOR;
	switch(yych){
	case 'g':	goto yy250;
	case 't':	goto yy251;
	default:	goto yy180;
	}
yy250:	yych = *++YYCURSOR;
	switch(yych){
	case 'i':	goto yy256;
	default:	goto yy180;
	}
yy251:	yych = *++YYCURSOR;
	switch(yych){
	case 'u':	goto yy252;
	default:	goto yy180;
	}
yy252:	yych = *++YYCURSOR;
	switch(yych){
	case 'r':	goto yy253;
	default:	goto yy180;
	}
yy253:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy254;
	default:	goto yy180;
	}
yy254:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy255;
	}
yy255:
#line 140 "cmmap.re"
{ RET(RETURN); }
#line 2391 "<stdout>"
yy256:	yych = *++YYCURSOR;
	switch(yych){
	case 's':	goto yy257;
	default:	goto yy180;
	}
yy257:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy258;
	default:	goto yy180;
	}
yy258:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy259;
	default:	goto yy180;
	}
yy259:	yych = *++YYCURSOR;
	switch(yych){
	case 'r':	goto yy260;
	default:	goto yy180;
	}
yy260:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy261;
	}
yy261:
#line 139 "cmmap.re"
{ RET(REGISTER); }
#line 2479 "<stdout>"
yy262:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy263;
	default:	goto yy180;
	}
yy263:	yych = *++YYCURSOR;
	switch(yych){
	case 'g':	goto yy264;
	default:	goto yy180;
	}
yy264:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy265;
	}
yy265:
#line 138 "cmmap.re"
{ RET(LONG); }
#line 2557 "<stdout>"
yy266:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy267;
	}
yy267:
#line 136 "cmmap.re"
{ RET(IF); }
#line 2625 "<stdout>"
yy268:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy269;
	default:	goto yy180;
	}
yy269:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy270;
	}
yy270:
#line 137 "cmmap.re"
{ RET(INT); }
#line 2698 "<stdout>"
yy271:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy272;
	default:	goto yy180;
	}
yy272:	yych = *++YYCURSOR;
	switch(yych){
	case 'o':	goto yy273;
	default:	goto yy180;
	}
yy273:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy274;
	}
yy274:
#line 135 "cmmap.re"
{ RET(GOTO); }
#line 2776 "<stdout>"
yy275:	yych = *++YYCURSOR;
	switch(yych){
	case 'o':	goto yy279;
	default:	goto yy180;
	}
yy276:	yych = *++YYCURSOR;
	switch(yych){
	case 'r':	goto yy277;
	default:	goto yy180;
	}
yy277:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy278;
	}
yy278:
#line 134 "cmmap.re"
{ RET(FOR); }
#line 2854 "<stdout>"
yy279:	yych = *++YYCURSOR;
	switch(yych){
	case 'a':	goto yy280;
	default:	goto yy180;
	}
yy280:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy281;
	default:	goto yy180;
	}
yy281:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy282;
	}
yy282:
#line 133 "cmmap.re"
{ RET(FLOAT); }
#line 2932 "<stdout>"
yy283:	yych = *++YYCURSOR;
	switch(yych){
	case 's':	goto yy294;
	default:	goto yy180;
	}
yy284:	yych = *++YYCURSOR;
	switch(yych){
	case 'u':	goto yy291;
	default:	goto yy180;
	}
yy285:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy286;
	default:	goto yy180;
	}
yy286:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy287;
	default:	goto yy180;
	}
yy287:	yych = *++YYCURSOR;
	switch(yych){
	case 'r':	goto yy288;
	default:	goto yy180;
	}
yy288:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy289;
	default:	goto yy180;
	}
yy289:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy290;
	}
yy290:
#line 132 "cmmap.re"
{ RET(EXTERN); }
#line 3030 "<stdout>"
yy291:	yych = *++YYCURSOR;
	switch(yych){
	case 'm':	goto yy292;
	default:	goto yy180;
	}
yy292:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy293;
	}
yy293:
#line 131 "cmmap.re"
{ RET(ENUM); }
#line 3103 "<stdout>"
yy294:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy295;
	default:	goto yy180;
	}
yy295:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy296;
	}
yy296:
#line 130 "cmmap.re"
{ RET(ELSE); }
#line 3176 "<stdout>"
yy297:	yych = *++YYCURSOR;
	switch(yych){
	case 'f':	goto yy305;
	default:	goto yy180;
	}
yy298:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	case 'u':	goto yy300;
	default:	goto yy299;
	}
yy299:
#line 128 "cmmap.re"
{ RET(DO); }
#line 3248 "<stdout>"
yy300:	yych = *++YYCURSOR;
	switch(yych){
	case 'b':	goto yy301;
	default:	goto yy180;
	}
yy301:	yych = *++YYCURSOR;
	switch(yych){
	case 'l':	goto yy302;
	default:	goto yy180;
	}
yy302:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy303;
	default:	goto yy180;
	}
yy303:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy304;
	}
yy304:
#line 129 "cmmap.re"
{ RET(DOUBLE); }
#line 3331 "<stdout>"
yy305:	yych = *++YYCURSOR;
	switch(yych){
	case 'a':	goto yy306;
	default:	goto yy180;
	}
yy306:	yych = *++YYCURSOR;
	switch(yych){
	case 'u':	goto yy307;
	default:	goto yy180;
	}
yy307:	yych = *++YYCURSOR;
	switch(yych){
	case 'l':	goto yy308;
	default:	goto yy180;
	}
yy308:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy309;
	default:	goto yy180;
	}
yy309:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy310;
	}
yy310:
#line 127 "cmmap.re"
{ RET(DEFAULT); }
#line 3419 "<stdout>"
yy311:	yych = *++YYCURSOR;
	switch(yych){
	case 's':	goto yy327;
	default:	goto yy180;
	}
yy312:	yych = *++YYCURSOR;
	switch(yych){
	case 'a':	goto yy324;
	default:	goto yy180;
	}
yy313:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy314;
	default:	goto yy180;
	}
yy314:	yych = *++YYCURSOR;
	switch(yych){
	case 's':	goto yy315;
	case 't':	goto yy316;
	default:	goto yy180;
	}
yy315:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy322;
	default:	goto yy180;
	}
yy316:	yych = *++YYCURSOR;
	switch(yych){
	case 'i':	goto yy317;
	default:	goto yy180;
	}
yy317:	yych = *++YYCURSOR;
	switch(yych){
	case 'n':	goto yy318;
	default:	goto yy180;
	}
yy318:	yych = *++YYCURSOR;
	switch(yych){
	case 'u':	goto yy319;
	default:	goto yy180;
	}
yy319:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy320;
	default:	goto yy180;
	}
yy320:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy321;
	}
yy321:
#line 126 "cmmap.re"
{ RET(CONTINUE); }
#line 3533 "<stdout>"
yy322:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy323;
	}
yy323:
#line 125 "cmmap.re"
{ RET(CONST); }
#line 3601 "<stdout>"
yy324:	yych = *++YYCURSOR;
	switch(yych){
	case 'r':	goto yy325;
	default:	goto yy180;
	}
yy325:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy326;
	}
yy326:
#line 124 "cmmap.re"
{ RET(CHAR); }
#line 3674 "<stdout>"
yy327:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy328;
	default:	goto yy180;
	}
yy328:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy329;
	}
yy329:
#line 123 "cmmap.re"
{ RET(CASE); }
#line 3747 "<stdout>"
yy330:	yych = *++YYCURSOR;
	switch(yych){
	case 'e':	goto yy331;
	default:	goto yy180;
	}
yy331:	yych = *++YYCURSOR;
	switch(yych){
	case 'a':	goto yy332;
	default:	goto yy180;
	}
yy332:	yych = *++YYCURSOR;
	switch(yych){
	case 'k':	goto yy333;
	default:	goto yy180;
	}
yy333:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy334;
	}
yy334:
#line 122 "cmmap.re"
{ RET(BREAK); }
#line 3830 "<stdout>"
yy335:	yych = *++YYCURSOR;
	switch(yych){
	case 't':	goto yy336;
	default:	goto yy180;
	}
yy336:	yych = *++YYCURSOR;
	switch(yych){
	case 'o':	goto yy337;
	default:	goto yy180;
	}
yy337:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case '_':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy179;
	default:	goto yy338;
	}
yy338:
#line 121 "cmmap.re"
{ RET(AUTO); }
#line 3908 "<stdout>"
yy339:	++YYCURSOR;
	goto yy340;
yy340:
#line 172 "cmmap.re"
{ RET(DIVEQ); }
#line 3914 "<stdout>"
yy341:	++YYCURSOR;
	goto yy342;
yy342:
#line 119 "cmmap.re"
{ goto comment; }
#line 3920 "<stdout>"
}
#line 228 "cmmap.re"


comment:

#line 3924 "<stdout>"
{
	YYCTYPE yych;
	goto yy343;
	++YYCURSOR;
yy343:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy347;
	case '*':	goto yy345;
	default:	goto yy349;
	}
yy345:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '/':	goto yy350;
	default:	goto yy346;
	}
yy346:
#line 239 "cmmap.re"
{ goto comment; }
#line 3945 "<stdout>"
yy347:	++YYCURSOR;
	goto yy348;
yy348:
#line 234 "cmmap.re"
{
		if(cursor == s->eof) RET(EOI);
		s->tok = s->pos = cursor; s->line++;
		goto comment;
	    }
#line 3955 "<stdout>"
yy349:	yych = *++YYCURSOR;
	goto yy346;
yy350:	++YYCURSOR;
	goto yy351;
yy351:
#line 232 "cmmap.re"
{ goto std; }
#line 3963 "<stdout>"
}
#line 240 "cmmap.re"

}

#ifndef	MAP_NORESERVE
#define	MAP_NORESERVE	0
#endif

main(){
    Scanner in;
    struct stat statbuf;
    uchar *buf;
    fstat(0, &statbuf);
    buf = mmap(NULL, statbuf.st_size, PROT_READ, MAP_SHARED|MAP_NORESERVE,
	0, 0);
    if(buf != (uchar*)(-1)){
	int t;
	in.lim = &(in.cur = buf)[statbuf.st_size];
	in.pos = NULL;
	in.eof = NULL;
	while((t = scan(&in)) != EOI){
/*
	    printf("%d\t%.*s\n", t, in.cur - in.tok, in.tok);
	    printf("%d\n", t);
*/
	}
	munmap(buf, statbuf.st_size);
    }
}
