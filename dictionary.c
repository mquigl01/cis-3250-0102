/*
* Description: Looks up the word to see if it exists in the dictionary
* @authors MacKenzie Quigley
* @version 0.1
* Modifications: followed coding conventions document and changed all variables to
* have meaning, used camel case for naming, and changed loop and if statement spacing
* Last modified Oct 5th by MacKenzie Quigley
*/

#include <string.h>
#include <stdio.h>

#include "dictionary.h"

/*
*
*
* Last modified Oct 5th by MacKenzie Quigley
*/
unsigned formHashValue ( const char *string ) {

	unsigned hashValue = 0;

	while ( *string != '\0' ) {

		hashValue = *string + 31 * hashValue;
		string++;

	}

	return hashValue;

}

/*
* Description: Checks to see if the word is in the dictionary
* Last modified Oct 5th by MacKenzie Quigley
*/
dictionaryStruct *lookupWord ( dictionaryStruct **dictionary, int hashSize, const char *key ) {

	dictionaryStruct *newWord;
	unsigned int hashValue = formHashValue( key );

	for ( newWord = dictionary[ hashValue % hashSize ]; newWord != NULL; newWord = newWord->next ) {

		if ( strcmp( key, newWord->key ) == 0 ) {

			return newWord;

		}

	}

	return NULL;

}

/*
*
*
* Last modified Oct 5th by MacKenzie Quigley
*/
dictionaryStruct *insertWord ( dictionaryStruct **dictionary, int hashSize,  const char *key ) {

	unsigned int hashValue;
	dictionaryStruct *newWord;

	if ( ( newWord = lookupWord(dictionary, hashSize, key ) ) == NULL ) {

		newWord = ( dictionaryStruct * ) malloc ( sizeof( *newWord ) );

		if ( newWord == NULL || ( newWord->key = copyString( key ) ) == NULL ) {

			return NULL;

		}

		hashValue = formHashValue( key ) % hashSize;
		newWord->next = dictionary [ hashValue ];
		dictionary[ hashValue ] = newWord;

	}

	return newWord;

}

/*
*
*
* Last modified Oct 5th by MacKenzie Quigley
*/
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

/*
*
*
* Last modified Oct 5th by MacKenzie Quigley
*/
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
