all:
	gcc -o m main.c
	./m

clean : 
		rm edit main.o