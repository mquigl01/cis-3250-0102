#include <string.h>
#include "boardGenerator.h"
#include <stdlib.h>

/* Revised by Josh Aidelman and Jaden Walt on October 4th at 4:00 PM */
/* Comments added by Josh Aidelman on October 17th at 12:08 AM */

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
