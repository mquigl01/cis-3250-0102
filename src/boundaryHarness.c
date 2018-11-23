/*
* Description:
* Authors: Mackenzie Quigley,
* Version: 0.1
* Last modifications: created this file
* Last modified November 23rd by Mackenzie Quigley
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void incrementTotalScore ( int *userScore, char *word );
void boundaryTest(int userScore, int expected, char *word);

int main(){
  //Tests for below max value (word length is 5)
  char *word1;
  word1 = malloc(sizeof(char)*5);

  //Tests for max value (word length is 8)
  char *word2;
  word2 = malloc(sizeof(char)*8);

  //Tests for above max value (word length is above 8)
  char *word3;
  word3 = malloc(sizeof(char)*14);

  //copy value into words
  strcpy(word1, "abcde");
  strcpy(word2, "abcdefgh");
  strcpy(word3, "abcdefghijklmn");

  printf("Test for below max value:\n");
  boundaryTest(0, 2, word1);

  printf("Test for at max value:\n");
  boundaryTest(0, 11, word2);

  printf("Test for above max value:\n");
  boundaryTest(0, 11, word3);

  return 0;
}

/*
* Description: This function tests incrementTotalScore. The paramaters are a
* pointer to the user score, the expected score for that word, and then the
* word. It sets the user score back to zero after it runs.
* Last modified November 23rd by Mackenzie Quigley
*/
void boundaryTest( int userScore, int expected, char *word ){

  incrementTotalScore( &userScore, word );
  printf("Expected: %d, Result: %d\n\n", expected, userScore);
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
