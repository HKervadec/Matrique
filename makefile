CC = gcc
CFLAGS = -g -std=c99 -m64
OBJ = matrique.o beautify.o

matrique.out: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

all: clean matrique.out
	
	
beautify.o: beautify.c beautify.h

matrique.o: matrique.c beautify.h vroot.h

clean:
	rm *.o matrique.out
