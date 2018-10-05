#include "boardGenerator.h"

// Initializes the dice in the list of pre-set dice. Call once at program start.
/*Last modified october 4th by MacKenzie Quigley */
void initializePresetDice(struct presetDice* inputArrayOfDice) {
	for ( int currentPosition = 0; currentPosition < 16; currentPosition++ ) {
		inputArrayOfDice[currentPosition].position = 0;
	}

	// initializes individual potential chars for each dice
	inputArrayOfDice[0].configurations = "RIFOBX";
	inputArrayOfDice[1].configurations = "IFEHEY";
	inputArrayOfDice[2].configurations = "DENOWS";
	inputArrayOfDice[3].configurations = "UTOKND";
	inputArrayOfDice[4].configurations = "HMSRAO";
	inputArrayOfDice[5].configurations = "LUPETS";
	inputArrayOfDice[6].configurations = "ACITOA";
	inputArrayOfDice[7].configurations = "YLGKUE";
	inputArrayOfDice[8].configurations = "QBMJOA";
	inputArrayOfDice[9].configurations = "EHISPN";
	inputArrayOfDice[10].configurations = "VETIGN";
	inputArrayOfDice[11].configurations = "BALIYT";
	inputArrayOfDice[12].configurations = "EZAVND";
	inputArrayOfDice[13].configurations = "RALESC";
	inputArrayOfDice[14].configurations = "UWILRG";
	inputArrayOfDice[15].configurations = "PACEMD";
}

// Rolls the dice to be used at the start of each game. Puts the rolled dice in
// gameDice. Does not shuffle the dice. Helper function.
/*Last modified october 4th by MacKenzie Quigley */
void rollNoShuffleDice(struct rolledDice* gameDice, struct presetDice* inputArrayOfDice) {
	srand(time(NULL));

	for ( int i = 0; i < 16; i++ ) {
		
		int r = rand()%6;
		gameDice[i].character = inputArrayOfDice[i].configurations[r];

	}
}

// Shuffles an array of rolled dice. Helper function.
/*Last modified october 4th by MacKenzie Quigley */
void shuffleRolledDicePositions(struct rolledDice* gameDice) {

	struct rolledDice newGameDice[16];

	int shufflePostition = 0;
	for ( int i = 0; i < 16; i++ ) {

		srand(time(NULL));
		if ( gameDice[shufflePostition].position == -1 ) {

			shufflePostition = (int) (rand()%16);

		}

		newGameDice[i] = gameDice[shufflePostition];
		gameDice[shufflePostition].position = -1;

	}

	for ( int i = 0; i < 16; i++ ) {

		gameDice[i] = newGameDice[i];
		gameDice[i].position = i+1;

	}
}


// Rolls the dice to be used at the start of the game and shuffles them, putting
// the dice into the 2D array gameDice. Call once at the start of every game.
void rollDice(struct rolledDice** game_board,
		struct presetDice* inputArrayOfDice){

	game_board[0] = malloc(sizeof(struct rolledDice) * 4);
	game_board[1] = malloc(sizeof(struct rolledDice) * 4);
	game_board[2] = malloc(sizeof(struct rolledDice) * 4);
	game_board[3] = malloc(sizeof(struct rolledDice) * 4);

	// temporary array of structs to contain adjusted 1D array of dice.
	struct rolledDice adjusted_dice_array[16];

	rollNoShuffleDice(adjusted_dice_array, inputArrayOfDice);
	shuffleRolledDicePositions(adjusted_dice_array);

	for ( int i = 0; i < 4; i++ ) {

		for ( int j = 0; j < 4; j++) {

			game_board[i][j] = adjusted_dice_array[i*4 + j];

		}

	}
}
// Prints a visualization of the input array of rolledDice.
void printGameBoard(struct rolledDice** game_board) {

	for ( int i = 0; i < 4; i++ ) {

			for ( int j = 0; j < 4; j++ ) {

				if ( j != 3 ) {

					printf("%c \t", game_board[i][j].character);

				}
				else {

					printf("%c \n", game_board[i][j].character);

				}

			}

		}
}

void printBoard(char boggle[][4]) {

	for ( int i = 0; i < 4; i++ ) {

			for ( int j = 0; j < 4; j++ ) {

				if ( j != 3 ) {

					printf("%c \t", boggle[i][j]);

				}
				else {

					printf("%c \n", boggle[i][j]);

				}

			}

		}
}

/** Converts board from a string version to 2D array. Used in test mode**/
void convertToBoard(char *letters, char ***board){
	// allocate space for boggle board on heap in order to access it in main.
	char *word;
	int i, j, t = 0;

	*board = malloc(sizeof(char * ) * 4);
	char **board_deref = *board;

	board_deref[0] = malloc(sizeof(char) * 4);
	board_deref[1] = malloc(sizeof(char) * 4);
	board_deref[2] = malloc(sizeof(char) * 4);
	board_deref[3] = malloc(sizeof(char) * 4);

	for ( i = 0; i < 4; i++ ) {

		for ( j = 0; j < 4; j++ ) {

			if ( j != 3 ) {

				board_deref[i][j] = letters[t];
				t++;

			}
			else {

				board_deref[i][j] = letters[t];
				t++;

			}

		}

	}
}
