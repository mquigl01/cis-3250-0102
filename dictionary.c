/*
*	Description: The dictionary of the game, this file contains the words, inserted into the dictionary and the words that are looked up in the dictionary by the user. 
*	@authors MacKenzie Quigley, Ali El Cheikh Ali
*	@version 0.1
*	Last modified Oct 11th by Ali El Cheikh Ali
*/

#include <string.h>
#include <stdio.h>

#include "dictionary.h"



/*	Function unsigned formHashValue
*	Forms a hashvalue for string s
*	This produces a starting value in the dictionary array
*
*	Last modified Oct 11th by Ali El Cheikh Ali
*/
unsigned formHashValue ( const char *string ) {

	unsigned hashValue = 0;

	while ( *string != '\0' ) {

		hashValue = *string + 31 * hashValue;	 
		string++;

	}

	return hashValue; 

}

/*	Function dictionaryStruct *lookupWord
*	Checks to see if the word is already in the dictionary
*
*	Last modified Oct 11th by Ali El Cheikh Ali
*/
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

/*	Function dictionaryStruct *instertWord
*	Inserts word into the dictionary 
*
*	Last modified Oct 11th by Ali El Cheikh Ali
*/
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

/*	Function void freeDictionary 
*	Frees the temporary string in the dictionary
*
*	Last modified Oct 11th by Ali El Cheikh Ali 
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

/*	Function char *copyString
*	Makes a duplicate of string s
*
*	Last modified Oct 11th by Ali El Cheikh Ali
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
