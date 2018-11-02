/**
 - edited by Scott Csordas, Oct 31, 3:00PM
 - set up board,
 - set up dictionary,
 - ensured all coding conventions are met

  - edited by Josh Aidelman, Oct 5th, 2:58PM
  - changed function names to camel case

   -edited by Scott Csordas, Oct 16, 3:15PM
   -added comments explaining functionality
 **/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#include "boardGenerator.h"
#include "wordChecker.h"
#include "scoreBoard.h"

#define MAX_LINE 100


void incrementTotalScore ( int *userScore, char *word );

/*
*  Function Description:frees the current board and resets all elements
* Last Modified:Oct 31
* Last Modifier: Scott Csordas
*/

void freeAndResetBoard ( struct rolledDice** gameBoard,
	struct presetDice* inputArrayOfDice ) {

	int numPlayers = 4;
	for ( int count = 0; count < numPlayers; count++ ) {

		free( gameBoard[count] );
	}
	rollDice( gameBoard, inputArrayOfDice );
}

/*
*  Function Description:converts a lower case character to an upper case character
* Last Modified:Oct 31
* Last Modifier: Scott Csordas
*/
char *convertToUpper ( char **upper ){

	char *upperDeref = *upper;
	for( int count = 0; upperDeref[count]; count++ ){

		upperDeref[count] = toupper( upperDeref[count] );
	}
	return upperDeref;
}

/*
*  Function Description:same as convertToUpper except does not use a double pointer
* Last Modified:Oct 31
* Last Modifier: Scott Csordas
*/
char *convertToUpper2 ( char ( *upper )[] ){

	char *upperDeref = *upper;
	for( int count = 0; upperDeref[count]; count++ ){

		upperDeref[count] = toupper( upperDeref[count] );
	}
	return upperDeref;
}

/*
*  Function Description:changes the score of the player
* Last Modified:Oct 31
* Last Modifier: Scott Csordas
*/
void incrementTotalScore ( int *userScore, char *word ){

	int wordLen = strlen( word );
	fprintf( stdout, "wordLen: %d\n",wordLen );
	if( wordLen == 3 || wordLen == 4 ){

		*userScore += 1;
	}
	else if( wordLen == 5 ){

		*userScore += 2;
	}
	else if( wordLen == 6 ){

		*userScore += 3;
	}
	else if( wordLen == 7 ){

		*userScore+=5;
	}
	else if( wordLen >= 8 ){

		*userScore += 11;
	}
}

/*
*  Function Description:executes the entire program
* Last Modified:Oct 31
* Last Modifier: Scott Csordas
*/
int main ( int argc, char ** argv ) {

	int testPoints = 0;
	int numPlayers = 4;
	char inputWord[100];
	char originalInputWord[100];

	FILE *inputFP;
	char line [MAX_LINE];
	char *fileName;

	//the dictionary that will be read from the file to check if a users inputted word exists
	
 	const char * DICT_NAME = "EnglishWords.txt";
	dictionaryStruct* checkEnglish;
	dictionaryStruct* checkSubmitted;
	static dictionaryStruct* englishDictionary [BIG_HASH_SIZE];
	static dictionaryStruct* guessedWords [SMALL_HASH_SIZE];

	int currentScore = 0;
	int turnCount = 0;

	User* head = NULL;
	head = ( User* )malloc( sizeof( User ) );

	PresetDice globalDice[16];
	RolledDice *gameBoard[4];

	FILE *outputFP;
	//ensures the file exists and can be read
	if( !( inputFP = fopen ( DICT_NAME , "r" ) ) )    {

		fprintf( stderr,"Could not open file \"%s\" for reading dictionary words\n", DICT_NAME );
        return 1;
    }

    //reads from the dictionary from the file
	while( fgets ( line, MAX_LINE, inputFP )!=NULL ) {

		line[strcspn( line, "\r\n" )] = '\0';  /*trim new line characters*/
		insertWord( englishDictionary, BIG_HASH_SIZE, convertToUpper2( &line ) );
	}
	fclose ( inputFP );

	//checks what game mode is being played and sets up the game
	if ( argc == 1 ){

		fprintf(stdout, "playing in normal mode\n\n");

		system( "clear" );

		initializePresetDice( globalDice );

		rollDice( gameBoard, globalDice );

		while ( turnCount >= 0 ) {

			strcpy( originalInputWord, inputWord );

			convertToUpper2( &inputWord );

			char inputName[100];

			if ( strcmp( originalInputWord, "q" ) == 0 ) {

				//"q" prints the scores and quits the game
				printScoreBoard( head );
				break;
			}
			//"n" is the input, adds user to/changes user in linked list and resets game
			
			if ( strcmp( originalInputWord, "n" ) == 0 ) {

				printScoreBoard(head);
				fprintf( stdout, "Your current score: %d \n", currentScore );
				fprintf( stdout, "What is your name? \n" );
				scanf( "%s", inputName );

				if ( userIsInList( head, inputName ) == 0 ){

					addNode( head, inputName, currentScore );
				}
				else {

					updateNodeWithName( head, inputName, currentScore );
				}

				currentScore = 0;

				strcpy( inputWord, "" );

				freeAndResetBoard( gameBoard, globalDice );
				turnCount = 0;
				system( "clear" );
				continue;
			}

			printGameBoard( gameBoard );

			checkEnglish = lookupWord( englishDictionary, BIG_HASH_SIZE, inputWord );
			//ensures that the word is exists
			if ( checkEnglish != NULL ) {

				checkSubmitted = lookupWord( guessedWords, SMALL_HASH_SIZE, inputWord );

				if ( checkSubmitted == NULL ) {

					if( strlen( inputWord ) > 2 ){

						if( wordChecker( gameBoard, inputWord ) ){

							insertWord( guessedWords, SMALL_HASH_SIZE, inputWord );
							incrementTotalScore( &currentScore, inputWord );
							fprintf ( stdout, "Correct! You current score is now: %d \n", currentScore );

						}
						else{

							fprintf ( stderr, "The submitted word: \'%s\'' does not abide game rules. Try again!\n", originalInputWord );
						}
					}
					else{

						fprintf ( stderr, "The submitted word: \'%s\'' must be at least 3 letters long. Try again!\n", originalInputWord );
					}

				}
				else{

					fprintf ( stderr, "You have already submitted the word: \'%s\'' Try again!\n", originalInputWord );
				}

		 	}
		 	else if ( turnCount > 0 ){

		 		fprintf ( stderr, "Incorrect word: \'%s\' is not in the English Dictionary. Try again!\n", originalInputWord );
			}
			fprintf( stdout, "Submit a word you found:\n" );
	       	scanf( "%s", inputWord );
	        turnCount++;
	        system( "clear" );
   		}
		for ( int count = 0; count < numPlayers; count++ ) {

			free( gameBoard[count] );
		}
		freeAll( head );
	//does the second game mode which is for testing the program
	}
	else if ( argc == 2 ){

		fileName =  argv[1];
		fprintf( stdout, "playing in test mode with file: %s\n", fileName );
		FILE *testFileFP;
		char testLine [MAX_LINE];
		char **testBoard;
		int fileLineCounter = 1;
		int count,testCounter;
		int begin = 0;

		// (1) read first line which is the board
		if( !( testFileFP = fopen ( fileName , "r" ) ) )    {

		    fprintf( stderr,"Could not open test file \'%s\' for reading\n", fileName );
		    return 1;
		}
		else if( !( outputFP = fopen( "result.txt", "w" ) ) ){

			fprintf( stderr,"Could not open result file \'%s\' for writing\n", "result.txt" );
		    return 1;
		}

		while ( fgets ( testLine, MAX_LINE, testFileFP )!=NULL ) {

			testLine[strcspn( testLine, "\r\n" )] = '\0';  
			//trim new line characters

			if( fileLineCounter == 1 ){

				convertToBoard( testLine, &testBoard );

				// this can be removed, its just for testing purposes
				for ( count = 0; count < numPlayers; count++ ) {

					for ( testCounter = 0; testCounter < numPlayers; testCounter++ ) {

						if ( testCounter != 3 ) {

							fprintf( stdout, "%c \t", testBoard[count][testCounter] );
						}
						else {

							fprintf( stdout, "%c \n", testBoard[count][testCounter] );
						}
					}
				}

			}
			else if ( fileLineCounter >= 2 ){

				for ( char *p = strtok( testLine,"," ); p != NULL; p = strtok( NULL, "," ) ){

					checkEnglish = lookupWord( englishDictionary, BIG_HASH_SIZE, convertToUpper( &p ) );

					if ( checkEnglish != NULL ) {

						checkSubmitted = lookupWord( guessedWords, SMALL_HASH_SIZE, p );

						if ( checkSubmitted == NULL ) {

							if( testWordChecker( testBoard, p ) ){

								insertWord( guessedWords, SMALL_HASH_SIZE, p );
								incrementTotalScore( &testPoints, p );
								fprintf( stdout,"Correct! You total score is now: %d \n",testPoints );

							}
							else{

								if( begin == 0 ){

									fprintf( outputFP, "%s", p );
									begin++;

								}
								else{

									fprintf( outputFP, ",%s", p );
								}

								fprintf( stderr,"The submitted word: \'%s\'' does not abide game rules. Try again!\n", p );
							}

						}
						else{

								if( begin == 0 ){

									fprintf( outputFP, "%s", p );
									begin++;
								}
								else{

									fprintf( outputFP, ",%s", p );
								}
							fprintf( stderr,"You have already submitted the word: \'%s\'' Try again!\n", p );
						}
					}
					else{

						if( begin == 0 ){

							fprintf( outputFP, "%s", p );
							begin++;
						}
						else{

							fprintf( outputFP, ",%s", p );
						}

				 		fprintf( stderr,"Incorrect word: \'%s\'' is not in the English Dictionary. Try again!\n", p );
					}
				}
			}
			fileLineCounter++;
		}

		fprintf( outputFP, "\n" );
		fprintf( outputFP, "%d\n", testPoints );

		fclose ( testFileFP );

		for ( int count = 0; count < numPlayers; count++ ) {

			free( testBoard[count] );
		}
		free( testBoard );

		fclose( outputFP );

	}

	freeDictionary( englishDictionary, BIG_HASH_SIZE );
	freeDictionary( guessedWords, SMALL_HASH_SIZE );

	return 0;
}
