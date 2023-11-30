# project3
CS1714 -Project 3 UTSA
Overview
The project is to create a turn-based role-playing game between two (computer) players in which they battle each other with a list of champions. 
Gameplay
The game starts with 2 players having a list of random number of champions, as decided by the user.
Each champion will be assigned a “role” and “level” based on some random probability. 
Each player has the same number of champions in the beginning. 
For both players, all the champions will always (at the start or any point in the gameplay) be sorted in the descending order of their “level”.
In each turn, both the players will battle each other by deploying in their arena their best champion who is in the front of the list sorted according to the “level”. 
The outcome of the battle will be determined by the “role” and “level” of the two champions currently in the arena. 
After each turn, the current champion will be discarded from their list of champions and play the next champion. 
The battle can have different outcomes such as one or both players may gain extra (one or two) champions, or one or both players may lose extra (one or two) champions.
Please see the table below on what the outcome is for a battle with two champions of the same or different “role”. 
The game continues until one player has lost all their champions. The player with any remaining champion wins.
Battle Outcome Possibilities

MAGE vs. MAGE:
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
