// Name: Alistair Chambers
//Date Completed: 11/28/2023
//Subject: CS1714
//Project # 3

/*•	Create a struct named Champion that will hold information about a champion and will act as a node in a linked list.
 Each Champion will have the following information:
o	“role” of type ChampionRole (see enum below)
o	“level” of  type integer
o	“next” champion for the linked list
•	Create an enum for ChampionRole which can be one of the following four roles:
         MAGE (M), FIGHTER (F), SUPPORT (S), TANK (T)
•	Declare all prototypes for the required functions (see Task 2) as well as the Header Guard.
*/

#ifndef CHAMPION_H
#define CHAMPION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum ChampionRole
{
    MAGE = 'M',
    FIGHTER = 'F',
    SUPPORT = 'S',
    TANK = 'T'
} ChampionRole;

typedef struct Champion
{
    ChampionRole role;
    int level;
    struct Champion *next;
} Champion;

Champion* createChampion();

Champion* addChampion(Champion *head, Champion *c);
Champion* buildChampionList(int n);
void printChampionList(Champion *head);
Champion* removeChampion(Champion *head);
Champion* destroyChampionList(Champion *head);




#endif
