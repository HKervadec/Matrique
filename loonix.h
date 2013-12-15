#ifndef LOONIX_H
#define LOONIX_H

	#include <sys/ioctl.h>
	#include <unistd.h>
	
	#include "beautify.h"

	#define PREP 
	#define END


	#define CALL_EMPTY_LAST_LINE emptyLastLine(row, col); 
	#define CALL_PRINT printFL(&fL[j], row, col);

	void getTerminalDimensions(int *row, int *col);
	void emptyLastLine(int row, int col);
	void emptyLine(int line, int col);
	void printFL(FL *fL, int row, int col);
	
#endif