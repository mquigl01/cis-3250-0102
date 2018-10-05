/*Last modified october 4th by Mackenzie Quigley*/
#ifndef BOARD_GEN
#define BOARD_GEN

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


// The pre-set dice which keep their values between games.
typedef struct presetDice {
	char *configurations;
	int position;
} PresetDice;

// The rolled dice which do not keep their values between games.
typedef struct rolledDice {
	char character;
	int position;
} RolledDice;


void initializePresetDice(struct presetDice* inputArrayOfDice);
void rollNoShuffleDice(struct rolledDice* gameDice,
		struct presetDice* inputArrayOfDice);

void shuffleRolledDicePositions(struct rolledDice* gameDice);
void printGameBoard(struct rolledDice** game_board);
void rollDice(struct rolledDice** game_board,
		struct presetDice* inputArrayOfDice);

void convertToBoard(char *letters, char ***board);
void printBoard(char boggle[][4]);

#endif
