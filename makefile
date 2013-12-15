CC = gcc
CFLAGS = -g -std=c99 
OBJ = matrique.o beautify.o
CIBLE = 

windows: CIBLE := WINDOZE
windows: $(OBJ) windoze.o
	$(CC)  $(CFLAGS)  $^ -o matrique.exe

	
linux: CIBLE := LOONIX
linux: $(OBJ) loonix.o
	$(CC) $(CFLAGS) $^ -o matrique.out
	


64: CFLAGS += -m64 
32: CFLAGS += -m32

64 32: all

all: clean linux
	
matrique.o: matrique.c beautify.h
	$(CC) -D $(CIBLE) $(CFLAGS) -c $^


	
beautify.o: beautify.c beautify.h

windoze.o: windoze.c windoze.h beautify.h

loonix.o: loonix.c loonix.h beautify.h


clean:
	rm *.o matrique.exe matrique.out
