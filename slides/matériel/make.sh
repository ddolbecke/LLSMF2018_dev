pandoc presentation.md --slide-level 2 -t beamer -o presentation.tex
pdflatex beamer.tex
pdflatex beamer.tex
rm *.aux *.nav *.snm *.log *.toc