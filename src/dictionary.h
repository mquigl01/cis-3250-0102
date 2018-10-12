/* Last modified Oct 5th by MacKenzie Quigley*/
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>
#define BIG_HASH_SIZE 20000
#define SMALL_HASH_SIZE 100

/* Last modified oct 5th by Mackenzie Quigley*/
typedef struct node {

	char *key;
  struct node *next;

} dictionaryStruct;

/* Last modified oct 5th by Mackenzie Quigley*/
char *copyString ( const char *string );
unsigned formHashValue ( const char *string );
dictionaryStruct *lookupWord ( dictionaryStruct **dictionary, int hashSize, const char *key );
dictionaryStruct *insertWord ( dictionaryStruct **dictionary, int hashSize, const char *key );
void freeDictionary ( dictionaryStruct **dictionary, int hashSize );

#endif
