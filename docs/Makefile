MD=pandoc
FLAGS=-s --toc -c pandoc.css -A footer.html documentation.md -o code_transform.html
# Add INC to pause for each bullet point
slides:
	$(MD) $(FLAGS)
clean:
	rm code_transform.html
