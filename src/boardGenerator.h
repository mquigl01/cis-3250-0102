/*
* Program Description: the headerfile for boardGenerator.c
* Author(s): Mackenzie Quigley, Ali El-Cheikh Ali
* Email(s): mquigl01@uoguelph.ca, aelcheik@uoguelph.ca
* Last Modified: Last modified Nov 2st by Mackenzie Quigley
*/

#ifndef BOARD_GEN
#define BOARD_GEN

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct presetDice {

	char *configurations;
	int position;

} PresetDice;

typedef struct rolledDice {

	char character;
	int position;

} RolledDice;

void initializePresetDice ( struct presetDice *inputArrayOfDice );
void rollNoShuffleDice ( struct rolledDice *gameDice, struct presetDice *inputArrayOfDice );
void shuffleRolledDicePositions ( struct rolledDice *gameDice );
void printGameBoard ( struct rolledDice **gameBoard );
void rollDice ( struct rolledDice **gameBoard, struct presetDice *inputArrayOfDice );
void convertToBoard ( char *letters, char ***board );
void printBoard ( char boggle[][4] );

#endif
