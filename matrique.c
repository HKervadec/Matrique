#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#include <X11/Xlib.h>

// #include "vroot.h"


#include "beautify.h"


#define ARROW_NUMBER 64


void getTerminalDimensions(int *row, int *col);

int main(int argc, char *argv[]){
	srand(time(NULL));

	int row, col;
	getTerminalDimensions(&row, &col);

	int arrow_number = row;

	FL *fL = initFLArray(row, row, col);


	emptyScreen();
	while(true){
		getTerminalDimensions(&row, &col);

		emptyLastLine(row, col);

		for(int j = 0 ; j < arrow_number ; j++){
			updateFL(&(fL[j]), row, col);
			printFL(&fL[j], row, col);
		}

		usleep(150 * 1000);
		// while(getchar() != '\n'); // For step by step progression
	}

	


	return EXIT_SUCCESS;
}

void getTerminalDimensions(int *row, int *col){
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	*row = w.ws_row;
	*col = w.ws_col;
}
