#include <stdlib.h>
#include <stdio.h>

#include "loonix.h"

void getTerminalDimensions(int *row, int *col){
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);

	*row = w.ws_row;
	*col = w.ws_col;
}


void emptyLastLine(int row, int col){
	emptyLine(row, col);
}

void emptyLine(int line, int col){
	for(int i = 0 ; i < col ; i++){
		printf("\033[%d;%dH ", line, i);
	}
}



void printFL(FL *fL, int row, int col){
	if(fL->x > 0){
		printf("\033[%d;%dH ", fL->x-1, fL->y);
	}

	int lim = fL->status - 1;
	if(fL->x + lim > 0){
		printf(GREEN_BRIGHT "\033[%d;%dH%c" GREEN
				, fL->x + lim, fL->y, fL->arrow[lim]);
	}

	for(int i = 0 ; i < lim ; i++){
		if(fL->x + i > 0){
			printf("\033[%d;%dH%c"
				, fL->x + i, fL->y, fL->arrow[i]);
		}
	}
}