MD=pandoc
FLAGS=-t beamer -H header_pagenrs.tex
THEME=-V theme:Madrid
# Add INC to pause for each bullet point
INC=-i
slides:
	$(MD) $(FLAGS) $(THEME) $@.md -o $@.pdf
clean:
	rm slides.pdf
