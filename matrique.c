#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <sys/ioctl.h>

#include <X11/Xlib.h>

#include "beautify.h"

void getTerminalDimensions(int *row, int *col);

int main(int argc, char *argv[]){
	srand(time(NULL));

	const struct timespec sleep_time = {0, 75*1000*1000}; // 75ms

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

		nanosleep(&sleep_time, NULL);
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
