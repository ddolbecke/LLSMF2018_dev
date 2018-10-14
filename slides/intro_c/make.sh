pandoc intro_c.md --slide-level 2 -t beamer -o intro_c.tex
pdflatex beamer.tex
pdflatex beamer.tex
rm *.aux *.nav *.snm *.log *.toc