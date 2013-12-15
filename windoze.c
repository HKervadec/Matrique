#include <stdlib.h>
#include <stdio.h>

#include <windows.h>

#include "windoze.h"


void getTerminalDimensions(int *row, int *col){
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	
	*col = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	*row = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}


void emptyLastLine(int row, int col, COORD *coord){
	emptyLine(row, col. coord);
}

void emptyLine(int line, int col, COORD *coord){
	coord->X = line;
	coord->Y = 0;
	
	for(int i = 0 ; i < col ; i++){
		printf(" ", line, i);
	}
}


void printFL(FL *fL, int row, int col, COORD *coord){	
	coord->Y = fL->y;
	
	if(fL->x > 0){
		coord->X = fL->x - 1;
		printf(" ");
	}

	int lim = fL->status - 1;
	if(fL->x + lim > 0){
		coord->X = fL->x + lim;
		printf("%c", fL->arrow[lim]);
	}

	for(int i = 0 ; i < lim ; i++){
		if(fL->x + i > 0){
			coord->X = fL->x + i;
			printf("%c", fL->arrow[i]);
		}
	}
}