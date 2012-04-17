TEX = pdflatex
BIB = bibtex
TITLE = circuit-simulator
.PHONY: clean realclean

circuit-simulator.pdf: circuit-simulator.bib circuit-simulator.tex circuit-simulator.cls imgs/*.pdf
	$(TEX) circuit-simulator.tex
	$(BIB) circuit-simulator
	$(TEX) circuit-simulator.tex
	$(TEX) circuit-simulator.tex

circuit-simulator.bib:

circuit-simulator.tex:

circuit-simulator.cls:

imgs/*.pdf:

clean:
	rm -f circuit-simulator.{aux,bbl,blg,log,out}

realclean: clean
	rm -f circuit-simulator.pdf