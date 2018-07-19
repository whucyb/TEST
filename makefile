name = main

pdf:
	pdflatex $(name) 

full:
	make clean
	pdflatex $(name)
# 	makeglossaries $(name)        
	bibtex $(name)
	pdflatex $(name)
	pdflatex $(name)

clean:
	rm -f *.aux chap/*.aux *.toc *.bbl *.blg *.log *.pdf *.lof *.lot *.out *.acn *.acr *.alg *.glg *.glo *.gls *.ist *.dvi
