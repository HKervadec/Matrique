#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "beautify.h"

void emptyScreen(){
	printf("\033[2J");
}

void emptyLastLine(int row, int col){
	emptyLine(row, col);
}

void emptyLine(int line, int col){
	for(int i = 0 ; i < col ; i++){
		printf("\033[%d;%dH ", line, i);
	}
}

void initFL(FL *fL, int row, int col, int length){
	fL->x = rand() % (row + length) - row ;
	fL->y = rand() % col;

	fL->size = length;
	fL->arrow = malloc(fL->size * sizeof(char));

	fL->status = rand() % fL->size;



	for(int i = 0 ; i < fL->status ; i++){
		fL->arrow[i] = randomChar();
	}
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
