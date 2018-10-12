/*Last modified october 4th by Mackenzie Quigley*/
#ifndef BOARD_GEN
#define BOARD_GEN

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


// The pre-set dice which keep their values between games.
/* Last modified oct 5th by Mackenzie Quigley*/
typedef struct presetDice {

	char *configurations;
	int position;
	
} PresetDice;


// The rolled dice which do not keep their values between games.
/* Last modified oct 5th by Mackenzie Quigley*/
typedef struct rolledDice {

	char character;
	int position;

} RolledDice;

/* Last modified oct 5th by Mackenzie Quigley*/
void initializePresetDice ( struct presetDice *inputArrayOfDice );
void rollNoShuffleDice ( struct rolledDice *gameDice, struct presetDice *inputArrayOfDice );
void shuffleRolledDicePositions ( struct rolledDice *gameDice );
void printGameBoard ( struct rolledDice **gameBoard );
void rollDice ( struct rolledDice **gameBoard, struct presetDice *inputArrayOfDice );
void convertToBoard ( char *letters, char ***board );
void printBoard ( char boggle[ ][ 4 ] );

#endif
