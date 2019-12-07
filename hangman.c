#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD '~'
#define SPACE ' '
#define VERT '|'
#define HORZ '_'

const int size = 10;
const char *word;
const char *four[10] = {"CATS", "SLAP", "CLAW", "PUSH", "FORD", "IPAD", "BEER", "MILK", "FIRE", "DOGS"};
const char *five[10] = {"KITTY", "CABLE", "FLAME", "TREES", "STACK", "ARRAY", "PEPSI", "MORTY", "LOOSE", "SANDY"};
const char *six[10] = {"PARKER", "BANANA", "ROCKET", "QUEUES", "LOTION", "TWELVE", "COUGAR", "LIGHTS", "SWORDS", "SWITCH"};
const char *eight[10] = {"ABSOLUTE", "TRACTORS", "FIREFLYS", "PEACOCKS", "BLANKETS", "RECLINERS", "PENGUINS", "EYEBROWS", "FIREWORK", "KEYBOARD"};
const char *ten[10] = {"PINEAPPLES", "SEMITRUCKS", "LIGHTHOUSE", "HANDWARMER", "THUMBTACKS", "SAXOPHONES", "TAMBORINES", "BASKETBALL", "CHARLESTON", "INTESTINES"};

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

int setDif() {
	int dif;

	printf("Enter difficulty level (1-5):\n");
	scanf("%d", &dif);

	if (dif < 1 || dif > 5) {
		printf("Your game has been set to hard for trying to be difficult.\n");
		dif = 5;
	}
	else {
		printf("Your game difficulty has been set to %d. Good luck.\n", dif);
	}

	return dif;
}

int setWordSize(char *pSpace) {
	int dif = setDif();

	pSpace[228] = HORZ;
	pSpace[230] = HORZ;
	pSpace[232] = HORZ;
	pSpace[234] = HORZ;
	
	switch (dif) {
		case 2: pSpace[236] = HORZ;
			break;
		case 3: pSpace[236] = HORZ;
			pSpace[238] = HORZ;
			break;
		case 4: pSpace[236] = HORZ;
			pSpace[238] = HORZ;
			pSpace[240] = HORZ;
			pSpace[242] = HORZ;
			break;
		case 5: pSpace[236] = HORZ;
			pSpace[238] = HORZ;
			pSpace[240] = HORZ;
			pSpace[242] = HORZ;
			pSpace[244] = HORZ;
			pSpace[246] = HORZ;
			break;
	}

	return dif; 
}

int random() {
	int pos;

	srand(time(NULL));

	pos = 1 + rand() % 10;

	return pos;
}

void buildGame() {
	char pSpace[300];
	createPlayingSpace(&pSpace[0]);
	int dif = setWordSize(&pSpace[0]);
	int pos = random();

	switch (dif) {
		case 1: word = four[pos]; break;
		case 2: word = five[pos]; break;
		case 3: word = six[pos]; break;
		case 4: word = eight[pos]; break;
		case 5: word = ten[pos]; break;
	}

	printPlayingSpace(&pSpace[0]);
	
}

int main() {

	buildGame();
	return 0;
}
