CC = gcc
CFLAGS = -Wall -pedantic-errors
OBJ = matrique.o beautify.o

all: matrique.out

beautify.o: beautify.c beautify.h
matrique.o: matrique.c beautify.h

matrique.out: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ -lncurses

clean:
	rm *.o matrique.out
