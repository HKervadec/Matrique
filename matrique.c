#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <ncurses.h>

#include <X11/Xlib.h>

#include "beautify.h"

int main(int argc, char *argv[]){
	srand(time(NULL));
	initscr();
	if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	use_default_colors();
	start_color();
	init_pair(1, COLOR_GREEN, -1);

	const struct timespec sleep_time = {0, 100*1000*1000}; // 75ms

	int row, col;
	getmaxyx(stdscr, row, col);

	int arrow_number = row;

	FL *fL = initFLArray(arrow_number, row, col);

	while(true){
		getmaxyx(stdscr, row, col);
		clear(); // Causes flicker but does not work yet with the erasing

		emptyLastLine(row, col);

		for(int j = 0 ; j < arrow_number ; j++){
			updateFL(&(fL[j]), row, col);
			printFL(&fL[j], row, col);
		}

		refresh();
		nanosleep(&sleep_time, NULL);
		// while(getchar() != '\n'); // For step by step progression
	}

	endwin();
	return EXIT_SUCCESS;
}