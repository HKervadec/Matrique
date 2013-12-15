#ifndef WINDOZE_H
#define WINDOZE_H
	
	#include <windows.h>
	
	#include "beautify.h"

	#define PREP  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
						CONSOLE_SCREEN_BUFFER_INFO consoleInfo;\
						WORD saved_attributes;\
						GetConsoleScreenBufferInfo(hConsole, &consoleInfo);\
						saved_attributes = consoleInfo.wAttributes;\
						SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	#define END SetConsoleTextAttribute(hConsole, saved_attributes);
	
	#define CALL_EMPTY_LAST_LINE emptyLastLine(row, col, (&consoleInfo).dwCursorPosition); 
	#define CALL_PRINT printFL(&fL[j], row, col, (&consoleInfo).dwCursorPosition);

	void getTerminalDimensions(int *row, int *col);
	void emptyLastLine(int row, int col, COORD *coord);
	void emptyLine(int line, int col, COORD *coord);
	void printFL(FL *fL, int row, int col, COORD *coord);



#endif