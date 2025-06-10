all:
	gcc main.c -o caesar-cipher

clean:
	rm *.o
	rm caesar-cipher
