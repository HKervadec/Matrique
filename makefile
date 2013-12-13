CC = gcc
CFLAGS = -g -std=c99 -m32
OBJ = matrique.o beautify.o

matrique: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o matrique

all: clean matrique
	
	
beautify.o: beautify.c beautify.h

matrique.o: matrique.c beautify.h

clean:
	rm *.o matrique
