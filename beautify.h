#ifndef BEAUTIFY
#define BEAUTIFY

#define MAX_ARROW_SIZE 16

#define RED     "\x1b[0;31m"
#define GREEN   "\x1b[0;32m"
#define GREEN_BRIGHT   "\x1b[1;32m"
#define YELLOW  "\x1b[0;33m"
#define BLUE    "\x1b[0;34m"
#define MAGENTA "\x1b[0;35m"
#define CYAN    "\x1b[0;36m"
#define RESET   "\x1b[0;0m"

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
