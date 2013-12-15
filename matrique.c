#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#include "beautify.h"

#ifdef WINDOZE
	#include "windoze.h"
#endif

#ifdef LOONIX
	#include "loonix.h"
#endif


void getTerminalDimensions(int *row, int *col);

int main(int argc, char *argv[]){
	srand(time(NULL));

	PREP
	
	int row, col;
	getTerminalDimensions(&row, &col);
	
	printf("%d %d\n", row, col);

	int arrow_number = row;

	FL *fL = initFLArray(row, row, col);


	// emptyScreen();
	while(true){
		getTerminalDimensions(&row, &col);

		CALL_EMPTY_LAST_LINE

		for(int j = 0 ; j < arrow_number ; j++){
			updateFL(&(fL[j]), row, col);
			CALL_PRINT
		}

		// usleep(150 * 1000);
		while(getchar() != '\n'); // For step by step progression
	}

	END


	return EXIT_SUCCESS;
}