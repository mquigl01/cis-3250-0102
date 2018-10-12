#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <stdlib.h>

typedef struct user{
    
	char name[100];
	int maxScore;
	int totalGames;
	int totalScore;
	struct user *next;

} User;

User* findUserWithName ( User* head, char* nameToFind );

User* getUserAtIndex ( User* head, int index );

int getIndexOfUserWithName ( User* head, char* nameToFind );

int getLength ( User* head );

User* getLastNode ( User *head );

void printScoreBoard ( User *head );

void freeAll ( User* head );

void addNode ( User *head, char* name, int maxScore );

int userIsInList ( User* head, char* nameToFind );

void updateNodeWithName ( User *head, char* name, int currentScore );

#endif
