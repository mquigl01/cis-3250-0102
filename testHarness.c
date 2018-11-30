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
  char word[20];
  char expected[20];
  char *upper = malloc(sizeof(char) * 20);

  /*****/
  printf("Structured Basis Testing\n");
  strcpy(word, "123456789");
  testIncrementTotalScore(&userScore, 11, word);

  strcpy(word, "123");
  testIncrementTotalScore(&userScore, 1, word);

  strcpy(word, "12");
  testIncrementTotalScore(&userScore, 0, word);

  strcpy(upper, "u");
  strcpy(expected, "U");
  testconvertToUpper(&upper, expected);

  strcpy(upper, "U");
  strcpy(expected, "U");
  testconvertToUpper(&upper, expected);

  /*****/
  printf("Boundary Analysis Testing\n");
  strcpy(word, "abcd");
  testIncrementTotalScore(&userScore, 1, word);

  strcpy(word, "abcde");
  testIncrementTotalScore(&userScore, 2, word);

  strcpy(word, "abcdef");
  testIncrementTotalScore(&userScore, 3, word);

  strcpy(word, "abcdefg");
  testIncrementTotalScore(&userScore, 5, word);

  strcpy(word, "abcdefgh");
  testIncrementTotalScore(&userScore, 11, word);

  strcpy(word, "ab");
  testIncrementTotalScore(&userScore, 0, word);

  strcpy(word, "abcdefghijklmn");
  testIncrementTotalScore(&userScore, 11, word);

  strcpy(upper, "A");
  strcpy(expected, "A");
  testconvertToUpper(&upper, expected);

  strcpy(upper, "a");
  strcpy(expected, "A");
  testconvertToUpper(&upper, expected);

  strcpy(upper, "?");
  strcpy(expected, "?");
  testconvertToUpper(&upper, expected);

  return 0;
}

/* This function tests incrementTotalScore. The paramaters are a pointer to
the user score, the expected score for that word, and then the word. It
sets the user score back to zero after it runs.                      */
void testIncrementTotalScore(int *userScore, int expected, char *word){

  incrementTotalScore(userScore, word);

  if(*userScore == expected){
    printf("SUCCESS!\n");
  }
  else{
    printf("ERROR!\n");
  }
  printf("Expected: %d\nResult: %d\n\n", expected, *userScore);
  *userScore = 0;
}

void incrementTotalScore ( int *userScore, char *word ){

  int wordLen = strlen( word );

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
    printf("SUCCESS!\n");
  }
  else{
    printf("ERROR!\n");
  }
  printf("Expected: %s\nResult: %s\n\n", expected, *upper);
}

char *convertToUpper ( char **upper ){

  char *upperDeref = *upper;
  for( int count = 0; upperDeref[count]; count++ ){

    upperDeref[count] = toupper( upperDeref[count] );
  }
  return upperDeref;
}
