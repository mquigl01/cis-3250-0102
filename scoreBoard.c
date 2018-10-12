#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "scoreBoard.h"

/*
 * Finds and returns a pointer to the User in the linked list beginning with
 * head which has the name name_to_find. If such a User is not in the Linked
 * List, it will return NULL. Helper function to increment_score.
 *
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

User* findUserWithName ( User* head, char* nameToFind ) {
    
	if ( head == NULL ) {
        
		return head;
	}
    
    User *current = head;
    
	while ( current != NULL ) {
        
		if ( strcmp ( current->name, nameToFind ) == 0 ) {
            
			return current;
            
		}
        
		current = ( current ) -> next;
	}
    
	return NULL;
}

/* frees every element of the linked list
 *
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

void freeAll ( User* head ) {
    
	if ( head -> next == NULL ) {
        
		free( head );
        
	}

	else {
        
            User *current = head->next;
            User *previous = head;
        
            while ( current != NULL ) {
            
                free( previous );
                previous = current;
                current = ( current ) -> next;
            
            }
	}
}

/*
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

User* getUserAtIndex ( User* head, int index ) {
    
	if ( head == NULL ) {
        
		return NULL;
        
	}
    
	User *current = head;
	int count = 0;
    
	while ( current != NULL ) {
        
		if ( count == index + 1 ) {
            
			return current;
            
		}
        
		current = ( current ) -> next;
		count++;
        
	}
    
	return NULL;
}

/*
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

int getIndexOfUserWithName ( User* head, char* nameToFind ) {
    
	if ( head == NULL && head->name != nameToFind ) {
        
		return -1;
        
	}
    
	User *current = head;
	int count = 0;
    
	while ( current != NULL ) {
        
        if ( strcmp ( current -> name, nameToFind ) ) {
            
                return count;
            
        }
        
        current = ( current ) -> next;
		count++;
        
	}
    
	return -1;
}

/*
 * Finds whether or not a an existing user is already in the list. Of they are,
 * returns 1. If not, returns 0.
 *
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

int userIsInList ( User* head, char* nameToFind ) {
    
	User *current = head;
    
	while ( current != NULL ) {
        
		if ( strcmp ( current -> name, nameToFind ) == 0) {
            
			return 1;
            
		}
        
		current = ( current ) -> next;
	}
    
	return 0;
}

/*
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

int getLength ( User* head ) {
    
	if ( head == NULL ) {
        
		return 0;
        
	}
    
	User *current = head;
	int count = 0;
    
	while ( current != NULL ) {
        
		count++;
        
		if ( current -> next == NULL ) {
            
			return count;
            
		}
        
		current = ( current ) -> next;
	}
    
	return 0;
}

/*
 * Helper function. Finds the last node in the linked list and returns it.
 * Returns NULL if called with an empty head, although such a case is not used
 * in the main function add_node.
 *
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

User* getLastNode ( User *head ) {
    
	if ( head == NULL ) {
        
		return head;
        
	}
    
	User *current = head;
    
	while ( current != NULL ) {
        
		if ( current->next == NULL ) {
            
			return current;
		}
        
		current = ( current ) -> next;
	}
    
	return NULL;
}

/*
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

void printScoreBoard ( User *head ) {
    
        fprintf( stdout, "\n" );
        fprintf( stdout, "---- SCORE BOARD ---- \n" );
    
	if ( head -> next != NULL ) {
        
		User *current = head->next;
        
		while ( current != NULL ) {
            
			printf( "\n" );
			printf( "Player name: %s \n", current -> name );
			printf( "High score: %d \n", current -> maxScore );
			printf( "Games played: %d \n", current -> totalGames );
			printf( "Total score: %d \n", current -> totalScore );
			printf( "\n" );
			printf( "--------------------- \n" );

			if ( current -> next == NULL ) {
                
				break;
			}
            
			current = ( current ) -> next;
		}
	}
}

/*
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

void addNode ( User *head, char* name, int maxScore ) {
    
	User *userPtr = NULL;
    
	if ( head != NULL ) {
        
		 userPtr = malloc( sizeof ( struct user ) );
        
	}
    
	strcpy( userPtr -> name, name );
	userPtr -> maxScore = maxScore;
	userPtr -> totalGames = 1;
	userPtr -> totalScore = maxScore;
	userPtr -> next = NULL;

	if ( head == NULL ) {
        
		head = userPtr;
	}
    
	else {
        
		getLastNode( head ) -> next = userPtr;
	}
    
}

/*
 * Last Modified by Mehak Bedi & Danielle on October 6th
 */

void updateNodeWithName (User *head, char* name, int currentScore) {
    
	if ( userIsInList( head, name ) == 1 ) {
        
		User *userPtr = findUserWithName( head, name );
        
		if ( currentScore > ( userPtr -> maxScore ) ) {
            
			userPtr -> maxScore = currentScore;
            
		}
        
		userPtr -> totalGames += 1;
		userPtr -> totalScore += currentScore;
	}
}
