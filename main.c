// Name: Alistair Chambers
//Date Completed: 11/28/2023
//Subject: CS1714
//Project # 3
//Overview: The project is to create a turn-based role-playing game between two (computer) players in which they battle each other with a list of champions. 

/*•	The program will accept one additional command line argument, which is the number of Champions each player will start with. Your program must determine if there is this command line argument:
o	If the command line argument does not exist, print an error, and end the program.
o	If the command line argument, check to see if it is a number greater than 0. If it is not, print an error and end the program.
•	Build each player’s Champion linked list based on the size passed in through the command line argument.
•	Start the game loop. The game continues so long as both players have Champions to battle with. In each turn (iteration of the loop):
o	Print out the round number starting at 1.
o	Print out each player's Champions using printChampionList().
o	Implement the outcomes for each permutation of Champion roles. There are 16 permutations of (MM, MF, MS, MT, FM, FF, FS, FT, SM, SF, SS, ST, TM, TF, TS, TT).
	Using the table for battle outcomes, decide who wins / losses, and implement the reward / punishment on both players. For this, you will need to use the functions createChampion(), addChampion(), and removeChampion().
	Remember that at the end of each turn, the champions already deployed in the battle will be removed from the players’ lists BEFORE implementing the reward / punishment based on the battle outcome.
o	Print the outcome for the battle and move to the next round.
•	At the end of the loop, there will be either a tie (i.e., no player has any champions left) or one player who wins (i.e., still has champions). Determine and print this final outcome of the game.
•	Remember to empty the entire list of champions for the players by freeing the memory for the linked list, before ending the program.
*/

/*============= PLAYER 1 V PLAYER 2 SHOWDOWN ============

----- ROUND 1 -----
Player 1: M5 F4 F2 F2 F2
Player 2: M6 T5 T3 F2 T1
Player 1 is a MAGE and Player 2 is a MAGE
Player 1 (MAGE) loses one champion.
Player 2 (MAGE) wins and gains one new champion.

----- ROUND 2 -----
Player 1: F2 F2 F2
Player 2: T5 T3 S3 F2 T1
Player 1 is a FIGHTER and Player 2 is a TANK
Player 1 (FIGHTER) wins and gains a new champion.
Player 2 (TANK) loses but with no penalty.

----- ROUND 3 -----
Player 1: F2 F2 T2
Player 2: T3 S3 F2 T1
Player 1 is a FIGHTER and Player 2 is a TANK
Player 1 (FIGHTER) wins and gains a new champion.
Player 2 (TANK) loses but with no penalty.

----- ROUND 4 -----
Player 1: F4 F2 T2
Player 2: S3 F2 T1
Player 1 is a FIGHTER and Player 2 is a SUPPORT
Player 1 (FIGHTER) wins but gains no reward.
Player 2 (SUPPORT) loses one champion.

----- ROUND 5 -----
Player 1: F2 T2
Player 2: T1
Player 1 is a FIGHTER and Player 2 is a TANK
Player 1 (FIGHTER) wins and gains a new champion.
Player 2 (TANK) loses but with no penalty.

============ GAME OVER  =============

Player 1 ending champion list: M7 T2
Player 2 ending champion list:

Player 2 ran out of champions. Player 1 wins.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "champion.h"


//checks what role the champion is and returns the role
char getRole(char role)
{
    if (role == 'M')
    {
        return MAGE;
    }
    else if (role == 'F')
    {
        return FIGHTER;
    }
    else if (role == 'S')
    {
        return SUPPORT;
    }
    else
    {
        return TANK;
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <number_of_champions>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0)
    {
        printf("Invalid number of champions\n");
        return 1;
    }

    srand(time(NULL));

    Champion *player1 = buildChampionList(n);
    Champion *player2 = buildChampionList(n);

    //============= PLAYER 1 V PLAYER 2 SHOWDOWN ============
    printf("\n\n============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n\n");

    int round = 1;
    while (player1 != NULL && player2 != NULL)
    {
        printf("----- Round %d -----\n", round);
        printf("Player 1: ");
        printChampionList(player1);
        printf("Player 2: ");
        printChampionList(player2);

        char outcome;

        // print the player 1 and player 2 roles
        printf("Player 1 is a ");
        if (player1->role == 'M')
        {
            printf("MAGE");
        }
        else if (player1->role == 'F')
        {
            printf("FIGHTER");
        }
        else if (player1->role == 'S')
        {
            printf("SUPPORT");
        }
        else
        {
            printf("TANK");
        }

        printf(" and Player 2 is a ");
        if (player2->role == 'M')
        {
            printf("MAGE");
        }
        else if (player2->role == 'F')
        {
            printf("FIGHTER");
        }
        else if (player2->role == 'S')
        {
            printf("SUPPORT");
        }
        else
        {
            printf("TANK");
        }
        printf("\n");
/*MAGE vs. MAGE:
Player with the higher "level" wins.
Winning player gains a new champion.
Losing player loses one champion.
In a tie, nothing happens.
MAGE vs. FIGHTER:
Player with the higher "level" wins.
If MAGE wins, they gain a new champion, and the FIGHTER loses with no penalty.
If FIGHTER wins, they gain no reward, but the MAGE loses one champion.
In a tie, nothing happens.
MAGE vs. SUPPORT:
Player with the higher "level" wins.
If MAGE wins, they gain one new champion, and the SUPPORT loses two champions.
If SUPPORT wins, they get two new champions, and the MAGE loses one champion.
In a tie, nothing happens.
MAGE vs. TANK:
TANK loses one champion.
MAGE gains a new champion.
FIGHTER vs. FIGHTER:
Both players gain a new champion.
Player with the higher "level" wins.
If SUPPORT wins, they gain one champion, and the FIGHTER loses but with no penalty.
If FIGHTER wins, they gain no reward, but the SUPPORT loses one champion.
In a tie, nothing happens.
FIGHTER vs. SUPPORT:
Both players lose one champion.
TANK player wins and gets a new champion.
SUPPORT player loses but with no penalty.
FIGHTER vs. TANK:
Player with higher "level" wins.
FIGHTER player wins and gains a new champion.
TANK player loses but with no penalty.
SUPPORT vs. SUPPORT:
Both players lose the next champion.
SUPPORT vs. TANK:
TANK player wins and gets a new champion.
SUPPORT player loses but with no penalty.
TANK vs. TANK:
Nothing happens – no penalty or reward.
*/
        // determine the outcome of the battle
        if(player1->role == 'M'){
            if(player2->role == 'M'){
                if(player1->level > player2->level){
                    outcome = '1';
                }
                else if(player1->level < player2->level){
                    outcome = '2';
                }
                else{
                    outcome = '0';
                }
            }
            else if(player2->role == 'F'){
                if(player1->level > player2->level){
                    outcome = '1';
                }
                else if(player1->level < player2->level){
                    outcome = '2';
                }
                else{
                    outcome = '0';
                }
            }
            else if(player2->role == 'S'){
                if(player1->level > player2->level){
                    outcome = '1';
                }
                else if(player1->level < player2->level){
                    outcome = '2';
                }
                else{
                    outcome = '0';
                }
            }
            else if(player2->role == 'T'){
                outcome = '1';
            }
        }
        else if(player1->role == 'F'){
            if(player2->role == 'M'){
                if(player1->level > player2->level){
                    outcome = '1';
                }
                else if(player1->level < player2->level){
                    outcome = '2';
                }
                else{
                    outcome = '0';
                }
            }
            else if(player2->role == 'F'){
                outcome = '1';
            }
            else if(player2->role == 'S'){
                if(player1->level > player2->level){
                    outcome = '1';
                }
                else if(player1->level < player2->level){
                    outcome = '2';
                }
                else{
                    outcome = '0';
                }
            }
            else if(player2->role == 'T'){
                if(player1->level > player2->level){
                    outcome = '1';
                }
                else if(player1->level < player2->level){
                    outcome = '2';
                }
                else{
                    outcome = '0';
                }
            }
        }
        else if(player1->role == 'S'){
            if(player2->role == 'M'){
                if(player1->level > player2->level){
                    outcome = '1';
                }
                else if(player1->level < player2->level){
                    outcome = '2';
                }
                else{
                    outcome = '0';
                }
            }else if(player2->role == 'F'){
                if(player1->level > player2->level){
                    outcome = '1';
                }
                else if(player1->level < player2->level){
                    outcome = '2';
                }
                else{
                    outcome = '0';
                }
            }
            else if(player2->role == 'S'){
                outcome = '0';
            }
            else if(player2->role == 'T'){
                outcome = '2';
            }

        }
        else if(player1->role == 'T'){
            if(player2->role == 'M'){
                outcome = '2';
            }
            else if(player2->role == 'F'){
                if(player1->level > player2->level){
                    outcome = '1';
                }
                else{
                    outcome = '2';
                }
            }
            else if(player2->role == 'S'){
                outcome = '1';
            }
            else if(player2->role == 'T'){
                outcome = '0';
            }
        }


        // implement the reward / punishment based on the outcome
        if (outcome == '1')
        {
            //get the role of the champion
            char role = getRole(player1->role);

            printf("Player 1 (%c) wins and gains a new champion.\n\n", role);
            Champion *c = createChampion();
            player1 = addChampion(player1, c);
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
        }
        else if (outcome == '2')
        {
            //get the role of the champion
            char role = getRole(player2->role);

            printf("Player 2 (%c) wins and gains a new champion.\n\n", role);
            Champion *c = createChampion();
            player2 = addChampion(player2, c);
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);
        }
        else
        {
            // wasnt given a clear answer on what to do if there is a tie.
            // would assume the tie would be a draw and champions would be removed 
            //from both players otherwise it would be an infinite loop
            printf("In a tie, nothing happens.\n\n");
            player1 = removeChampion(player1);
            player2 = removeChampion(player2);

        }

        round++;
    }
    //============ GAME OVER  =============
    printf("\n============ GAME OVER  =============\n\n");

    //print player lists
    //ex:
    //Player 1 ending champion list: M7 T2
    //Player 2 ending champion list:
    printf("Player 1 ending champion list: ");
    printChampionList(player1);
    printf("Player 2 ending champion list: ");
    printChampionList(player2);
    printf("\n");



    if (player1 == NULL && player2 == NULL)
    {
        printf("TIE -- both players ran out of champions.\n");
    }
    else if (player1 == NULL)
    {
        printf("Player 1 ran out of champions. Player 2 wins.\n");
    }
    else
    {
        printf("Player 2 ran out of champions. Player 1 wins\n");
    }

    // free the memory for the linked lists
    player1 = destroyChampionList(player1);
    player2 = destroyChampionList(player2);

    return 0;
}

