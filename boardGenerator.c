/*
* Description: This programs code is to generate the board for the game. This is used to make the dice, roll the dice, generate the board, and converts the board from a string to a 2D array.
* @authors Mackenzie Quigley, Ali El Cheikh Ali
* @version 0.1
*	Modifications: fixed and updated comments to follow coding conventions
* Last modified Oct 12th by MacKenzie Quigley
*/

#include "boardGenerator.h"

/*
* Function: void initializePresetDice
*	Description: Initializes the dice in the list of pre-set dice. Call once at program start.
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
*/
void initializePresetDice(struct presetDice *inputArrayOfDice) {

	for ( int currentPosition = 0; currentPosition < 16; currentPosition++ ) {	//goes through every character underneath

		inputArrayOfDice[ currentPosition ].position = 0;

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
* Function: void rollNoShuffleDice
*	Description: Rolls the dice without shuffling the chars for each dice roll.
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified october 11th by Ali El Cheikh Ali
*/
void rollNoShuffleDice ( struct rolledDice *gameDice, struct presetDice *inputArrayOfDice ) {
	int gameDiceSize = 16;
	srand( time( NULL ) );

	for ( int gameDicePosition = 0; gameDicePosition < gameDiceSize; gameDicePosition++ ) {

		int randomNumber = rand( ) % 6;
		gameDice[ gameDicePosition ].character = inputArrayOfDice[ gameDicePosition ].configurations[ randomNumber ];

	}

}

/*
* Function: void shuffleRolledDicePositions
*	Description: Shuffles an array of rolled dice. Helper function.
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
*/
void shuffleRolledDicePositions( struct rolledDice* gameDice ) {
	int gameDiceSize = 16;
	struct rolledDice newGameDice[ gameDiceSize ];
	int shufflePostition = 0;

	for ( int gameDicePosition = 0; gameDicePosition < gameDiceSize; gameDicePosition++ ) {

		srand( time( NULL ) );

		if ( gameDice[ shufflePostition ].position == -1 ) {

			shufflePostition = ( int ) ( rand() % gameDiceSize );

		}

		newGameDice[ gameDicePosition ] = gameDice[ shufflePostition ];
		gameDice[ shufflePostition ].position = -1;

	}

	for ( int gameDicePosition = 0; gameDicePosition < gameDiceSize; gameDicePosition++ ) {

		gameDice[ gameDicePosition ] = newGameDice[ gameDicePosition ];
		gameDice[ gameDicePosition ].position = gameDicePosition + 1;

	}

}

/*
* Function: void rollDice
*	Description: Rolls the dice to be used at the start of the game and shuffles
* them, putting the dice into the 2D array gameDice. Call once at the start of
* every game.
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
*/
void rollDice ( struct rolledDice **gameBoard, struct presetDice *inputArrayOfDice ) {

	int boardSize = 4;
	struct rolledDice adjustedDiceArray[ boardSize * boardSize ];

	gameBoard[ 0 ] = malloc( sizeof ( struct rolledDice ) * boardSize);
	gameBoard[ 1 ] = malloc(sizeof ( struct rolledDice ) * boardSize);
	gameBoard[ 2 ] = malloc(sizeof ( struct rolledDice ) * boardSize);
	gameBoard[ 3 ] = malloc(sizeof ( struct rolledDice ) * boardSize);

	rollNoShuffleDice ( adjustedDiceArray, inputArrayOfDice );
	shuffleRolledDicePositions (adjustedDiceArray );

	for ( int horizontalPosition = 0; horizontalPosition < boardSize; horizontalPosition++ ) {

		for ( int verticalPosition = 0; verticalPosition < boardSize; verticalPosition++) {

			gameBoard[ horizontalPosition ][ verticalPosition ] = adjustedDiceArray[ horizontalPosition * boardSize + verticalPosition ];

		}

	}

}

/*
* Function: void printGameBoard
*	Description: Prints a visualization of the input array of rolledDice.
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
*/
void printGameBoard ( struct rolledDice **gameBoard ) {
	int boardSize = 4;
	int lastVerticalPosition = 3;

	for ( int horizontalPosition = 0; horizontalPosition < boardSize; horizontalPosition++ ) {

		for ( int verticalPosition = 0; verticalPosition < boardSize; verticalPosition++ ) {

			if ( verticalPosition != lastVerticalPosition ) {

				printf("%c \t", gameBoard[ horizontalPosition ][ verticalPosition ].character);

			}
			else {

				printf("%c \n", gameBoard[ horizontalPosition ][ verticalPosition ].character);

			}

		}

	}

}

/*
* Function: void printBoard
*	Description: prints the board to the screen based on a two dimensional array
* passed through the functions paramenters.
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
*/
void printBoard ( char boggle[ ][ 4 ] ) {

	int boardSize = 4;
	int lastVerticalPosition = 3;

	for ( int horizontalPosition = 0; horizontalPosition < boardSize; horizontalPosition++ ) {

		for ( int verticalPosition = 0; verticalPosition < boardSize; verticalPosition++ ) {

			if ( verticalPosition != lastVerticalPosition ) {

				printf( "%c \t", boggle[ horizontalPosition ][ verticalPosition ] );

			}
			else {

				printf( "%c \n", boggle[ horizontalPosition ][ verticalPosition ] );

			}

		}

	}

}

/*
* Function: void convertToBoard
*	Description: Converts a string of letters that is passed through parameters
* to a two dimensional array called boardArray that is used to form the 4x4
* board
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
*/
void convertToBoard ( char *letters, char ***board ) {

	int lettersIndex = 0;
	int boardSize = 4;
	int lastVerticalPosition = 3;

	*board = malloc ( sizeof( char * ) * boardSize );
	char **boardArray = *board;

	boardArray[ 0 ] = malloc ( sizeof(char) * boardSize );
	boardArray[ 1 ] = malloc ( sizeof(char) * boardSize );
	boardArray[ 2 ] = malloc ( sizeof(char) * boardSize );
	boardArray[ 3 ] = malloc ( sizeof(char) * boardSize );

	for ( int horizontalPosition = 0; horizontalPosition < boardSize; horizontalPosition++ ) {

		for ( int verticalPosition = 0; verticalPosition < boardSize; verticalPosition++ ) {

			if ( verticalPosition != lastVerticalPosition ) {

				boardArray[ horizontalPosition ][ verticalPosition ] = letters[ lettersIndex ];
				lettersIndex++;

			}
			else {

				boardArray[ horizontalPosition ][ verticalPosition ] = letters[ lettersIndex ];
				lettersIndex++;

			}

		}

	}

}
