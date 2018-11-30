#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void incrementTotalScore ( int *userScore, char *word );
void testIncrementTotalScore( int *userScore, int expected, char *word );
char *convertToUpper ( char **upper);
void testconvertToUpper ( char **upper, char *expected);

int main(){

  	int userScore = 0;
  	char word[10];
	char expected[10];
	char *upper = malloc(sizeof(char) * 10);

	strcpy(upper, "hello");
	strcpy(expected, "HELLO");
	testconvertToUpper(&upper, expected);

  	//This is how you run a test
  	strcpy(word, "2 ");
  
  	//Parameters: userScore, expectedScore, word
  	testIncrementTotalScore(&userScore, 0, word);

  	strcpy(word, "3  ");
  	testIncrementTotalScore(&userScore, 1, word);

  	return 0;
}

/* This function tests incrementTotalScore. The paramaters are a pointer to
   the user score, the expected score for that word, and then the word. It
   sets the user score back to zero after it runs.                      */
void testIncrementTotalScore(int *userScore, int expected, char *word){

  incrementTotalScore(userScore, word);

  if(*userScore == expected){
    printf("SUCCESS!\n\n");
  }
  else{
    printf("Expected: %d\nResult: %d\n\n", expected, *userScore);
  }
  *userScore = 0;
}

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

void testconvertToUpper ( char **upper, char *expected){

	*upper = convertToUpper(upper);
	
	if (strcmp(*upper, expected) == 0){
		printf("SUCCESS!\n\n");
	}
	else{
		printf("Expected: %s\nResult: %s\n\n", expected, *upper);
	}

}

char *convertToUpper ( char **upper ){

	char *upperDeref = *upper;
	for( int count = 0; upperDeref[count]; count++ ){

		upperDeref[count] = toupper( upperDeref[count] );
	}
	return upperDeref;
}


