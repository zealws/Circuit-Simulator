TEX = pdflatex
BIB = bibtex
TITLE = circuit-simulator
.PHONY: clean realclean

$(TITLE).pdf: $(TITLE).bib $(TITLE).tex $(TITLE).cls imgs/*.pdf
	$(TEX) $(TITLE).tex
	$(BIB) $(TITLE)
	$(TEX) $(TITLE).tex
	$(TEX) $(TITLE).tex

$(TITLE).bib:

$(TITLE).tex:

$(TITLE).cls:

imgs/*.pdf:

clean:
	rm -f $(TITLE).{aux,bbl,blg,log,out}

realclean: clean
	rm -f $(TITLE).{pdf,dvi}