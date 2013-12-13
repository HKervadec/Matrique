#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#include "beautify.h"

#define ARROW_NUMBER 64


void getTerminalDimensions(int *row, int *col);

int main(int argc, char *argv[]){
	srand(time(NULL));
	printf("Hello, world!\n");


	int row, col;
	getTerminalDimensions(&row, &col);

	FL fL[ARROW_NUMBER];
	initFLArray(fL, ARROW_NUMBER, row, col);

	// printf("%d %d %d %d\n", fL[0].x, fL[0].y, fL[0].status, fL[0].size);

	emptyScreen();
	while(true){
		getTerminalDimensions(&row, &col);

		emptyLastLine(row, col);

		for(int j = 0 ; j < ARROW_NUMBER ; j++){
			updateFL(&fL[j], row, col);
			printFL(&fL[j], row, col);
		}

		usleep(150 * 1000);
		// while(getchar() != '\n');
	}


	return EXIT_SUCCESS;
}

void getTerminalDimensions(int *row, int *col){
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	*row = w.ws_row;
	*col = w.ws_col;
}
