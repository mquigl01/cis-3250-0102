#include <string.h>
#include <stdio.h>

#include "dictionary.h"


//form hash value for string s
//this produces a starting value in the dictionary array
/* Last modified Oct 1st by MacKenzie Quigley*/
unsigned hash( const char *s ) {
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval ;
}

/* Last modified Oct 1st by MacKenzie Quigley*/
DNode * lookup ( DNode ** dictionary, int hash_size, const char *key ) {
	DNode * np;
	unsigned int hashval = hash(key);
	for ( np = dictionary [hashval % hash_size]; np !=NULL; np = np->next ) {
		if (strcmp (key, np->key) == 0)
		return np;
	}
	return NULL;
}

/* Last modified Oct 1st by MacKenzie Quigley*/
DNode * insert ( DNode ** dictionary, int hash_size,  const char * key ) {
	unsigned int hashval;
	DNode *np;

	if ( (np = lookup (dictionary, hash_size, key)) == NULL ) {
		np = (DNode *) malloc (sizeof (*np));

		if ( np == NULL || (np->key = copystr (key)) == NULL ) {
			return NULL;
		}
		hashval = hash (key) % hash_size;

		np->next = dictionary [hashval];
		dictionary[hashval] = np;
	}
	return np;
}

/* Last modified Oct 1st by MacKenzie Quigley*/
void free_dictionary ( DNode ** dictionary, int hash_size ) {
	for ( int sizeIndex = 0; sizeIndex < hash_size; sizeIndex++ ) {
		if ( dictionary[sizeIndex] != NULL ) {
			DNode *head = dictionary[sizeIndex];
			DNode *current = head;
			while ( current != NULL ) {
				DNode * temp = current;
				current = current->next;
				free(temp);
			}
			dictionary[sizeIndex] = NULL;
		}
	}
}

/* make a duplicate of s */
/* Last modified Oct 1st by MacKenzie Quigley*/
char *copystr ( const char *character ) {
	char *duplicate;
	int length = strlen(character);

	duplicate = (char *) malloc(length + 1); /* +1 for ?\0? */
	if (duplicate != NULL) {
		strncpy(duplicate, character, length);

	}
	duplicate[length] = '\0';

	return duplicate;
}
