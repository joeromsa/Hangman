
#include <stdio.h>
#include <stdlib.h>

#define BOARD '~'
#define SPACE ' '
#define VERT '|'
#define HORZ '_'


void createPlayingSpace(char *pSpace) {

	char title[9] = "HANGMAN!";

	for (int index = 0; index < 300; index++) {
		if (((index <= 25 || index >= 275) && index % 2 == 0) || index % 25 == 0 || (index + 1) % 25 == 0)
		{
			pSpace[index] = BOARD;
		}
		else if ((index >= 55 && index <= 58) || (index == 178 || index == 180)) {
			pSpace[index] = HORZ;
		}
		else if (((index > 74 && index < 199) && ((index - 4) % 25 == 0)) || index == 84) {
			pSpace[index] = VERT;
		}
		else {
			pSpace[index] = SPACE;
		}
	}
	
	int start = 34;
	for (int i = 0; i < 8; i++) {
		pSpace[start] = title[i];
		start++;
	}
}

void printPlayingSpace(const char *pSpace) {

	for (int index = 0; index < 300; index++) {
		if (index != 0 && index % 25 == 0) {
			printf("\n");
		}
		printf("%c", pSpace[index]);
	}
	printf("\n");
}

int main() {
	char pSpace[300];
	createPlayingSpace(&pSpace[0]);
	printPlayingSpace(&pSpace[0]);
	return 0;
}
