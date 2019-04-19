#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#include "beautify.h"


void emptyScreen(){
	// printf("\033[2J");
	clear();
}


void emptyLastLine(int row, int col){
	// emptyLine(row - 1, col);
}


void emptyLine(int line, int col){
	for(int i = 0 ; i < col ; i++){
		mvprintw(line, i, " ");
	}
}


void initFL(FL *fL, int row, int col, int length){
	fL->size = length;
	fL->arrow = malloc(fL->size * sizeof(char));

	resetFL(fL, row, col);
}


FL *initFLArray(int size, int row, int col){
	FL *fL = malloc(size * sizeof(FL));

	for(int i = 0 ; i < size ; i++){
		initFL(&fL[i], row, col, MAX_ARROW_SIZE);
	}

	return fL;
}


void resetFL(FL *fL, int row, int col){
	fL->x = rand() % (row + fL->size) - row ;
	fL->y = rand() % col;

	fL->status = rand() % fL->size;

	for(int i = 0 ; i < fL->status ; i++){
		fL->arrow[i] = randomChar();
	}
}


void printFL(FL *fL, int row, int col){
	// if(fL->x > 0){
	// 	mvprintw(fL->x-1, fL->y, " ");
	// }

	int lim = fL->status - 1;
	if(fL->x + lim >= 0){
		attron(COLOR_PAIR(lim+1));
		attron(A_BOLD);
		mvprintw(fL->x + lim, fL->y, "%c", fL->arrow[lim]);
		attroff(A_BOLD);
		attron(COLOR_PAIR(lim+1));
	}

	for(int i = 0 ; i < lim ; i++){
		if(fL->x + i >= 0){
			attron(COLOR_PAIR(i+1));
			mvprintw(fL->x + i, fL->y, "%c", fL->arrow[i]);
			attroff(COLOR_PAIR(i+1));
		}
	}
}


void updateFL(FL *fL, int row, int col){
	fL->x += 1;
	if(fL->x > row){
		resetFL(fL, row, col);
	}


	fL->status = (fL->status >= fL->size) ? fL->size : fL->status+1;


	for(int i = fL->status-1 ; i >= 1 ; i--){
		fL->arrow[i] = fL->arrow[i-1];
	}

	fL->arrow[0] = randomChar();
}


char randomChar(){
	return rand() % (127 - 32) + 32;
}
