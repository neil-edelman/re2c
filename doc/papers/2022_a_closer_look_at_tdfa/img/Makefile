%.pdf : %.tex
	lualatex -shell-escape $< </dev/null > $<.build_log

PDFS := \
    tnfa_construction.pdf \
    tdfa_construction.pdf \
    tdfa_optimized.pdf \
    tdfa_opttagfix.pdf

all : $(PDFS)

clean:
	rm *.log *.build_log *.aux *.pdf *.pag
