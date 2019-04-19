#ifndef BEAUTIFY
#define BEAUTIFY

#define MAX_ARROW_SIZE 24

#define MIN_GREEN 400
#define MAX_GREEN 1000

typedef struct FL{
	int x;
	int y;
	int status;
	int size;
	char *arrow;
} FL;


void emptyScreen();
void emptyLine(int line, int col);
void emptyLastLine(int row, int col);

void initFL(FL *fL, int row, int col, int length);
FL *initFLArray(int size, int row, int col);

void resetFL(FL *fL, int row, int col);
void printFL(FL *fL, int row, int col);
void updateFL(FL *fL, int row, int col);

char randomChar();


#endif
