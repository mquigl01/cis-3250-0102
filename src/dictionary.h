/* Last modified Nov 1st by Ali El-Cheikh Ali*/
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdlib.h>
#define BIG_HASH_SIZE 20000
#define SMALL_HASH_SIZE 100

/* Last modified Nov 1st by Ali El-Cheikh Ali*/
typedef struct node{

	char *key;
  struct node *next;

}dictionaryStruct;

/* Last modified Nov 1st by Ali El-Cheikh Ali*/
char *copyString( const char *string );
unsigned formHashValue( const char *string );
dictionaryStruct *lookupWord( dictionaryStruct **dictionary, int hashSize, const char *key );
dictionaryStruct *insertWord( dictionaryStruct **dictionary, int hashSize, const char *key );
void freeDictionary( dictionaryStruct **dictionary, int hashSize );

#endif
