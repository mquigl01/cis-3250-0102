/*
* Description:
* @authors Mackenzie Quigley
* @version 0.1
* Last modified Oct 5th by MacKenzie Quigley
*/

#include "boardGenerator.h"

// Initializes the dice in the list of pre-set dice. Call once at program start.
/*
*
*
* Last modified Oct 5th by MacKenzie Quigley
*/
void initializePresetDice(struct presetDice *inputArrayOfDice) {

	for ( int currentPosition = 0; currentPosition < 16; currentPosition++ ) {

		inputArrayOfDice[currentPosition].position = 0;

	}

	// initializes individual potential chars for each dice
	inputArrayOfDice[ 0 ].configurations = "RIFOBX";
	inputArrayOfDice[ 1 ].configurations = "IFEHEY";
	inputArrayOfDice[ 2 ].configurations = "DENOWS";
	inputArrayOfDice[ 3 ].configurations = "UTOKND";
	inputArrayOfDice[ 4 ].configurations = "HMSRAO";
	inputArrayOfDice[ 5 ].configurations = "LUPETS";
	inputArrayOfDice[ 6 ].configurations = "ACITOA";
	inputArrayOfDice[ 7 ].configurations = "YLGKUE";
	inputArrayOfDice[ 8 ].configurations = "QBMJOA";
	inputArrayOfDice[ 9 ].configurations = "EHISPN";
	inputArrayOfDice[ 10 ].configurations = "VETIGN";
	inputArrayOfDice[ 11 ].configurations = "BALIYT";
	inputArrayOfDice[ 12 ].configurations = "EZAVND";
	inputArrayOfDice[ 13 ].configurations = "RALESC";
	inputArrayOfDice[ 14 ].configurations = "UWILRG";
	inputArrayOfDice[ 15 ].configurations = "PACEMD";

}


/*
*
*
* Last modified october 5th by MacKenzie Quigley
*/
void rollNoShuffleDice ( struct rolledDice *gameDice, struct presetDice *inputArrayOfDice ) {

	srand( time( NULL ) );

	for ( int index = 0; index < 16; index++ ) {

		int randomNumber = rand( ) % 6;
		gameDice[ index ].character = inputArrayOfDice[ index ].configurations[ randomNumber ];

	}

}

// Shuffles an array of rolled dice. Helper function.
/*
*
*
* Last modified Oct 5th by MacKenzie Quigley
*/
void shuffleRolledDicePositions( struct rolledDice* gameDice ) {

	struct rolledDice newGameDice[ 16 ];
	int shufflePostition = 0;

	for ( int index = 0; index < 16; index++ ) {

		srand( time( NULL ) );

		if ( gameDice[ shufflePostition ].position == -1 ) {

			shufflePostition = ( int ) ( rand() %16 );

		}

		newGameDice[ index ] = gameDice[ shufflePostition ];
		gameDice[ shufflePostition ].position = -1;

	}

	for ( int index = 0; index < 16; index++ ) {

		gameDice[ index ] = newGameDice[ index ];
		gameDice[ index ].position = index + 1;

	}

}


// Rolls the dice to be used at the start of the game and shuffles them, putting
// the dice into the 2D array gameDice. Call once at the start of every game.
/*
*
*
* Last modified Oct 5th by MacKenzie Quigley
*/
void rollDice ( struct rolledDice **gameBoard, struct presetDice *inputArrayOfDice ) {

	gameBoard[ 0 ] = malloc( sizeof ( struct rolledDice ) * 4);
	gameBoard[ 1 ] = malloc(sizeof ( struct rolledDice ) * 4);
	gameBoard[ 2 ] = malloc(sizeof ( struct rolledDice ) * 4);
	gameBoard[ 3 ] = malloc(sizeof ( struct rolledDice ) * 4);

	// temporary array of structs to contain adjusted 1D array of dice.
	struct rolledDice adjustedDiceArray[ 16 ];

	rollNoShuffleDice ( adjustedDiceArray, inputArrayOfDice );
	shuffleRolledDicePositions (adjustedDiceArray );

	for ( int index = 0; index < 4; index++ ) {

		for ( int secondIndex = 0; secondIndex < 4; secondIndex++) {

			gameBoard[ index ][ secondIndex ] = adjustedDiceArray[ index * 4 + secondIndex ];

		}

	}

}

// Prints a visualization of the input array of rolledDice.
/*
*
*
* Last modified Oct 5th by MacKenzie Quigley
*/
void printGameBoard ( struct rolledDice **gameBoard ) {

	for ( int index = 0; index < 4; index++ ) {

			for ( int secondIndex = 0; secondIndex < 4; secondIndex++ ) {

				if ( secondIndex != 3 ) {

					printf("%c \t", gameBoard[ index ][ secondIndex ].character);

				}
				else {

					printf("%c \n", gameBoard[ index ][ secondIndex ].character);

				}

			}

		}

}

/*
*
*
* Last modified Oct 5th by MacKenzie Quigley
*/
void printBoard ( char boggle[ ][ 4 ] ) {

	for ( int index = 0; index < 4; index++ ) {

			for ( int secondIndex = 0; secondIndex < 4; secondIndex++ ) {

				if ( secondIndex != 3 ) {

					printf( "%c \t", boggle[ index ][ secondIndex ] );

				}
				else {

					printf( "%c \n", boggle[ index ][ secondIndex ] );

				}

			}

		}

}

/** Converts board from a string version to 2D array. Used in test mode**/
/*
*
*
* Last modified Oct 10th by MacKenzie Quigley
*/
void convertToBoard ( char *letters, char ***board ) {

	// allocate space for boggle board on heap in order to access it in main.
	int lettersIndex = 0;

	*board = malloc ( sizeof( char * ) * 4 );
	char **boardArray = *board;

	boardArray[ 0 ] = malloc ( sizeof(char) * 4 );
	boardArray[ 1 ] = malloc ( sizeof(char) * 4 );
	boardArray[ 2 ] = malloc ( sizeof(char) * 4 );
	boardArray[ 3 ] = malloc ( sizeof(char) * 4 );

	for ( int index = 0; index < 4; index++ ) {

		for ( int secondIndex = 0; secondIndex < 4; secondIndex++ ) {

			if ( secondIndex != 3 ) {

				boardArray[ index ][ secondIndex ] = letters[ lettersIndex ];
				lettersIndex++;

			}
			else {

				boardArray[ index ][ secondIndex ] = letters[ lettersIndex ];
				lettersIndex++;

			}

		}

	}

}
