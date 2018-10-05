#include <string.h>
#include <stdio.h>

#include "dictionary.h"


//form hash value for string s
//this produces a starting value in the dictionary array
/* Last modified Oct 4th by MacKenzie Quigley*/
unsigned formHashValue ( const char *string ) {

	unsigned hashValue = 0;

	while ( *string != '\0' ) {

		hashValue = *string + 31 * hashValue;
		string++;

	}

	return hashValue;

}

/* Checks to see if the word is in the dictionary */
/* Last modified Oct 4th by MacKenzie Quigley*/
dictionaryStruct *lookupWord ( dictionaryStruct **dictionary, int hashSize, const char *key ) {

	dictionaryStruct *np;
	unsigned int hashValue = formHashValue( key );

	for ( np = dictionary[ hashValue % hashSize ]; np != NULL; np = np->next ) {

		if ( strcmp( key, np->key ) == 0 ) {
			return np;
		}

	}

	return NULL;

}

/* Last modified Oct 4th by MacKenzie Quigley*/
dictionaryStruct *insertWord ( dictionaryStruct **dictionary, int hashSize,  const char *key ) {

	unsigned int hashValue;
	dictionaryStruct *np;

	if ( ( np = lookupWord(dictionary, hashSize, key ) ) == NULL ) {

		np = ( dictionaryStruct * ) malloc ( sizeof( *np ) );

		if ( np == NULL || ( np->key = copyString( key ) ) == NULL ) {

			return NULL;

		}

		hashValue = formHashValue( key ) % hashSize;
		np->next = dictionary [ hashValue ];
		dictionary[ hashValue ] = np;

	}

	return np;

}

/* Last modified Oct 5th by MacKenzie Quigley*/
void freeDictionary ( dictionaryStruct **dictionary, int hashSize ) {

	for ( int sizeIndex = 0; sizeIndex < hashSize; sizeIndex++ ) {

		if ( dictionary[ sizeIndex ] != NULL ) {

			dictionaryStruct *head = dictionary[ sizeIndex ];
			dictionaryStruct *current = head;

			while ( current != NULL ) {

				dictionaryStruct *temp = current;
				current = current->next;
				free( temp );

			}

			dictionary[ sizeIndex ] = NULL;

		}

	}

}

/* make a duplicate of s */
/* Last modified Oct 5th by MacKenzie Quigley*/
char *copyString ( const char *string ) {

	char *duplicate;
	int length = strlen( string );
	duplicate = ( char * ) malloc( length + 1 );

	if ( duplicate != NULL ) {

		strncpy( duplicate, string, length );

	}

	duplicate[ length ] = '\0';
	return duplicate;

}
