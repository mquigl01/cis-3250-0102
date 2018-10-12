#include <stdio.h>
#include <string.h>
#include "wordChecker.h"
#include <ctype.h>

/* Revised by Josh Aidelman and Jaden Walt on October 4th at 3:59 PM */
char getLetter( int i, int j, struct rolledDice **gameBoard ){
  return gameBoard[ i ][ j ].character;
}

/* Revised by Josh Aidelman and Jaden Walt on October 4th at 4:11 PM */
int abidesRules(  int i, int j, char *word, struct rolledDice** gameBoard, int subLen, int **visited  ){

  int adjCell;
  int newX;
  int newY;
  char findLetter;

  // right, digUpRight, up, digUpLeft, left, digDownLeft, down, digDownRight
  int allX[ ] = { 0, -1, -1, -1, 0, 1, 1, 1 };
  int allY[ ] = { 1, 1, 0, -1, -1, -1, 0, 1 };

  if(  subLen == (  strlen(  word  ) -1  )  ){

    return 1;
  }

  findLetter = word[ subLen + 1 ];
  int result = 0;

  for( adjCell = 0; adjCell < 8; adjCell++ ){

    newX = i + allX[ adjCell ];
    newY = j + allY[ adjCell ];

    if( ( newX >= 0 ) && ( newX < 4 ) && ( newY >=0 ) && ( newY < 4 )
    && toupper( findLetter ) == getLetter( newX, newY, gameBoard ) && !visited[ newX ][ newY ] ){

      visited[ newX ][ newY ] = 1;
      ++subLen;
      result = abidesRules( newX, newY, word, gameBoard, subLen, visited );

      if( result ){
        return 1;
      }
      else{
        --subLen;
      }

    }

  }

  return 0;
}

/* Revised by Josh Aidelman and Jaden Walt on October 5th at 2:53 PM */
int wordChecker( struct rolledDice **gameBoard, char *word ){

  int m;
  int n;
  int **visited;

  visited = malloc( sizeof( int *  ) * 4 );

  visited[ 0 ] = malloc( sizeof( int ) * 4 );
  visited[ 1 ] = malloc( sizeof( int ) * 4 );
  visited[ 2 ] = malloc( sizeof( int ) * 4 );
  visited[ 3 ] = malloc( sizeof( int ) * 4 );

  for( m = 0; m < 4; m++ ){

    for( n = 0; n < 4; n++ ){

      if( m == 0 && n == 0 ){

        visited[ m ][ n ] = 1;
      }
      else{
        visited[ m ][ n ] = 0;
      }

    }

  }

  for( int row = 0; row < 4; row++ ){

    for ( int col = 0; col < 4; col++ ) {

      if( abidesRules( row, col, word, gameBoard, 0, visited ) ){

        free( visited[ 0 ] );
        free( visited[ 1 ] );
        free( visited[ 2 ] );
        free( visited[ 3 ] );
        return 1;
      }

    }

  }

  free( visited[ 0 ] );
  free( visited[ 1 ] );
  free( visited[ 2 ] );
  free( visited[ 3 ] );

  return 0;

}

/* Revised by Josh Aidelman and Jaden Walt on October 4th at 4:18 PM */
char testGetLetter( int i, int j, char **boggle ){
  return boggle[ i ][ j ];
}


/* Revised by Josh Aidelman and Jaden Walt on October 4th at 4:22 PM */
int testAbidesRules( int i, int j, char *word, char **gameBoard, int subLen, int **visited ){

  int adjCell;
  int result;
  int newX;
  int newY;
  int allX[ ] = { 0, -1, -1, -1, 0, 1, 1, 1 };
  int allY[ ] = { 1, 1, 0, -1, -1, -1, 0, 1 };
  char findLetter;

  // use subLen as index to see what letter to find
  char currentLetter = word[ subLen ];

  if( subLen == ( strlen( word )-1 ) ){

    return 1;

  }

  if( toupper( currentLetter ) == 'Q' && toupper( word[ subLen + 2 ] ) == testGetLetter( i,j,gameBoard ) ){
    findLetter = word[ subLen + 3 ];
    subLen++;
    subLen++;
    currentLetter = word[ subLen ];
  }

  else{
    findLetter = word[ subLen + 1 ];
  }

  result = 0;

  for( adjCell = 0; adjCell < 8; adjCell++ ){

    newX = i + allX[ adjCell ];
    newY = j + allY[ adjCell ];

    if( ( newX >= 0 ) && ( newX < 4 ) && ( newY >=0 ) && ( newY < 4 )
    && toupper( findLetter ) == testGetLetter( newX, newY, gameBoard )
    && !visited[ newX ][ newY ] ){

      visited[ newX ][ newY ] = 1;
      ++subLen;
      result = testAbidesRules( newX, newY, word, gameBoard, subLen, visited );

      if( result ){

        return 1;
      }

      else{
        --subLen;
      }

    }

  }

  return 0;
}

/* Revised by Josh Aidelman and Jaden Walt on October 4th at 4:28 PM */
int testWordChecker( char **boggle, char *word ){

  int m;
  int n;
  int **visited;
  visited = malloc( sizeof( int *  ) * 4 );

  visited[ 0 ] = malloc( sizeof( int ) * 4 );
  visited[ 1 ] = malloc( sizeof( int ) * 4 );
  visited[ 2 ] = malloc( sizeof( int ) * 4 );
  visited[ 3 ] = malloc( sizeof( int ) * 4 );

  for( m = 0; m < 4; m++ ){
    for( n = 0; n < 4; n++ ){

      if( m == 0 && n == 0 ){
        visited[ m ][ n ] = 1;
      }

      else{
        visited[ m ][ n ] = 0;
      }
    }
  }
  for ( int row = 0; row < 4; row++ ) {

    for ( int col = 0; col < 4; col++ ) {

      if( testAbidesRules( row, col, word, boggle, 0, visited ) ){
        free( visited[ 0 ] );
        free( visited[ 1 ] );
        free( visited[ 2 ] );
        free( visited[ 3 ] );
        return 1;

      }
    }

  }

  free( visited[ 0 ] );
  free( visited[ 1 ] );
  free( visited[ 2 ] );
  free( visited[ 3 ] );

  return 0;
}

/* Revised by Josh Aidelman and Jaden Walt on October 4th at 4:20 PM */
int hcWordChecker( char boggle[  ] [ 4 ], char *word ){

  int m;
  int n;
  int **visited;

  visited = malloc( sizeof( int *  ) * 4 );
  visited[ 0 ] = malloc( sizeof( int ) * 4 );
  visited[ 1 ] = malloc( sizeof( int ) * 4 );
  visited[ 2 ] = malloc( sizeof( int ) * 4 );
  visited[ 3 ] = malloc( sizeof( int ) * 4 );

  for( m = 0; m < 4; m++ ){
    for( n = 0; n < 4; n++ ){

      if( m == 0 && n == 0 ){
        visited[ m ][ n ] = 1;
      }

      else{
        visited[ m ][ n ] = 0;
      }
    }
  }

  for( int row = 0; row < 4; row++ ) {

    for( int col = 0; col < 4; col++ ) {

      if( hcAbidesRules( row, col, word, boggle, 0, visited ) ){

        free( visited[ 0 ] );
        free( visited[ 1 ] );
        free( visited[ 2 ] );
        free( visited[ 3 ] );

        return 1;
      }

    }

  }
  free( visited[ 0 ] );
  free( visited[ 1 ] );
  free( visited[ 2 ] );
  free( visited[ 3 ] );

  return 0;

}

/* Revised by Josh Aidelman and Jaden Walt on October 4th at 4:16 PM */
int hcAbidesRules( int i, int j, char *word, char boggle[  ][ 4 ], int subLen, int **visited ){

  int adjCell;
  int newX;
  int newY;
  int allX[  ] = {0, -1, -1, -1, 0, 1, 1, 1};
  int allY[  ] = {1, 1, 0, -1, -1, -1, 0, 1};
  char currentLetter = word[ subLen ];
  char findLetter;

  if( subLen == ( strlen( word )-1 ) ){
    return 1;
  }

  if( toupper( currentLetter ) == 'Q' && toupper( word[ subLen + 2 ] ) == hcGetLetter( i,j,boggle ) ){
    findLetter = word[ subLen + 3 ];
    subLen++;
    subLen++;
    currentLetter = word[ subLen ];

  }

  else{
    findLetter = word[ subLen + 1 ];
  }

  int result = 0;

  for( adjCell = 0; adjCell < 8; adjCell++ ){

    newX = i + allX[ adjCell ];
    newY = j + allY[ adjCell ];

    if( ( newX >= 0 ) && ( newX < 4 ) && ( newY >=0 ) && ( newY < 4 )
    && toupper( findLetter ) == hcGetLetter( newX, newY, boggle )
    && !visited[  newX  ][  newY  ] ){

      visited[  newX  ][  newY  ] = 1;
      ++subLen;
      result = hcAbidesRules(  newX, newY, word, boggle, subLen, visited  );

      if(  result  ){
        return 1;
      }

      else{
        --subLen;
      }

    }

  }
  return 0;
}

/* Revised by Josh Aidelman and Jaden Walt on October 4th at 4:08 PM */
char hcGetLetter(  int i, int j, char boggle[   ] [  4  ]  ){
  return boggle[ i ][ j ];
}
