pandoc periph.md --slide-level 2 -t beamer -o periph.tex
pdflatex beamer.tex
pdflatex beamer.tex
rm *.aux *.nav *.snm *.log *.toc