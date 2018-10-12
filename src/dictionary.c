/*
*	Description: Looks up the word to see if it exists in the dictionary
*	@authors MacKenzie Quigley, Ali El-Cheikh Ali
*	@version 0.1
*	Modifications: added comments, followed coding conventions document and changed
*	all variables to have meaning, used camel case for naming, and changed loop and if
*	statement spacing
*	Last modified Oct 12th by Ali El-Cheikh Ali
*/

#include <string.h>
#include <stdio.h>

#include "dictionary.h"



/*
*	Function: unsigned formHashValue
*	Description: Forms a hashvalue for string passed through function parameters
*	which essentially produces a starting value
*	Modifications: fixed and updated comments to follow coding conventions
*	in the dictionary array
*	Last modified Oct 12th by Mackenzie Quigley
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
*	Function: dictionaryStruct *lookupWord
*	Description: Checks to see if the string that is passed through the Function
*	parameters is already in the dictionary. If it is: it returns the word, if not:
*	it returns NULL
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
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
*	Function: dictionaryStruct *instertWord
*	Description: Inserts and returns a new word into the dictionary if the word
*	does not already exist when using the function lookUpWord
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
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
*	Function: void freeDictionary
*	Description: Frees the temporary string in the dictionary by iterating through
*	the dictionary until reaching the specified hash size and freeing any nodes
*	that do not equal NULL
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
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
*	Function: char *copyString
*	Description: Makes and returns a duplicate of the string passed through
*	the function parameters
*	Modifications: fixed and updated comments to follow coding conventions
*	Last modified Oct 12th by MacKenzie Quigley
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
