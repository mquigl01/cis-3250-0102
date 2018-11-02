/*
* Description: the headerfile for wordChecker.c
* Modification: restored old comments
* Author(s): Joshua Aidelman, Jaden Walt
* Email(s): jaidelma@uoguelph.ca, waltj@uoguelph.ca
* Last modified: Nov 2nd by Mackenzie Quigley
*/

#include <string.h>
#include "boardGenerator.h"
#include <stdlib.h>

//Checks if the word is on the board and hasn't been visited yet
int wordChecker( struct rolledDice **gameBoard, char *word );

//Makes sure all letters are touching, word is valid
int abidesRules( int i, int j, char *word, struct rolledDice** gameBoard, int subLen, int **visited );

//Gets the letter at the possition gameBoard[i][j]
char getLetter( int i, int j, struct rolledDice **gameBoard );

//Tests all above functions
int testWordChecker( char **boggle, char *word );
int testAbidesRules( int i, int j, char *word, char **gameBoard, int subLen, int **visited );
char testGetLetter( int i, int j, char **boggle );

//Tests all above functions
int hcWordChecker( char boggle[][4], char *word );
char hcGetLetter( int i, int j, char boggle[][4] );
int hcAbidesRules( int i, int j, char *word, char boggle[][4], int subLen, int **visited );
