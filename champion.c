// Name: Alistair Chambers
//Date Completed: 11/28/2023
//Subject: CS1714
//Project # 3


/*Write the following functions which are typical linked list functions adapted for this game:
•	Champion* createChampion() - This function dynamically allocates a new Champion struct object and returns a pointer to that struct object which will later be used to insert into a linked list. 
o	The  champion’s “role” will be assigned randomly with a 25% probability each for MAGE (M), FIGHTER (F), SUPPORT (S), TANK (T).
o	The champion’s “level” will be assigned based on these random chances:
	MAGE (M) -  “level” is a random number between 5 and 8 inclusive. 
	FIGHTER (F) -  “level” is a random number between 1 and 4 inclusive. 
	SUPPORT (S) -  “level” is a random number between 3 and 6 inclusive. 
	TANK (T) -  “level” is a random number between 1 and 8 inclusive.
•	Champion* addChampion( Champion *head, Champion *c ) - This function adds a new Champion struct object to the linked list that head is pointing at. It is assumed that a new Champion struct object is being passed into this function as parameter c. This function will add the new node in descending (decreasing) order of the champion’s “level” value regardless of the “role”.
•	Champion* buildChampionList( int n ) - This function builds a list of champions using a linked list. The parameter n determines how many champions are created. It will use createChampion() and addChampion() to create and return the head of the new linked list.
•	void printChampionList( Champion *head ) - This function traverses the linked list that head is pointing at and will print out the entire list of champions for a given player. Example:  S6 M5 F4 S4 T3
•	Champion* removeChampion( Champion *head ) - This function removes and deallocates the first node in the linked list that head is pointing at. It returns the new head of the linked list.
•	Champion* destroyChampionList( Champion *head ) - This function is the destructor for a linked list that head is pointing at. It will remove all the champions from the player’s list and return NULL.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "champion.h"

Champion* createChampion() {
    Champion* c = (Champion*)malloc(sizeof(Champion));
    /*	MAGE (M) -  “level” is a random number between 5 and 8 inclusive. 
	FIGHTER (F) -  “level” is a random number between 1 and 4 inclusive. 
	SUPPORT (S) -  “level” is a random number between 3 and 6 inclusive. 
	TANK (T) -  “level” is a random number between 1 and 8 inclusive.
*/
    int r = rand() % 4;
    if (r == 0) {
        c->role = 'M';
        c->level = rand() % 4 + 5;
    }
    else if (r == 1) {
        c->role = 'F';
        c->level = rand() % 4 + 1;
    }
    else if (r == 2) {
        c->role = 'S';
        c->level = rand() % 4 + 3;
    }
    else {
        c->role = 'T';
        c->level = rand() % 8 + 1;
    }
    c->next = NULL;
    return c;
}

Champion* addChampion(Champion* head, Champion* c) {
    if (head == NULL) {
        head = c;
        return head;
    }
    Champion* temp = head;
    if (c->level > head->level) {
        c->next = head;
        head = c;
        return head;
    }
    while (temp->next != NULL) {
        if (c->level > temp->next->level) {
            c->next = temp->next;
            temp->next = c;
            return head;
        }
        temp = temp->next;
    }
    temp->next = c;
    return head;
}

Champion *buildChampionList(int n) {
    Champion* head = NULL;
    for (int i = 0; i < n; i++) {
        Champion* c = createChampion();
        head = addChampion(head, c);
    }
    return head;
}

void printChampionList(Champion* head) {
    Champion* temp = head;
    while (temp != NULL) {
        printf("%c%d ", temp->role, temp->level);
        temp = temp->next;
    }
    printf("\n");
}

Champion* removeChampion(Champion* head) {
    if (head == NULL) {
        return NULL;
    }
    Champion* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Champion* destroyChampionList(Champion* head) {
    while (head != NULL) {
        head = removeChampion(head);
    }
    return NULL;
}


