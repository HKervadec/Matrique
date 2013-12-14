CC = gcc
CFLAGS = -g -std=c99 
OBJ = matrique.o beautify.o

matrique.out: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

64: CFLAGS += -m64 
32: CFLAGS += -m32

64 32: all

all: clean matrique.out
	
	
beautify.o: beautify.c beautify.h

matrique.o: matrique.c beautify.h

clean:
	rm *.o matrique.out
