#include "bats.h"
#include "cave.h"
#include "event.h"
#include "gold.h"
#include "pit.h"
#include "room.h"
#include "wumpus.h"
#include "implementation.h"

using namespace std;

//TODO// Code for percept of gold after picking up
//TODO// Code for movement of player
//TODO// Code for firing an arrow
//TODO!// Bug where if you die, play again on the same map, die again, and try to quit it plays another for some reason.
//TODO// Code for all encounters
//TODO// Code for win condition and loss condition
//TODO// Code for replay, new map, or quit
//TODO// Code for moving wumpus
//TODO// Error handle inputs
//TODO Create function documentation
//TODO// Code for memory freeing
//TODO Check over rubric

/******************************************************
** Program: wumpus_hunt
** Author: Jacob Reger
** Date: 02/28/2020
** Description: This program will play the wumpus hunt
** game. The player will spawn in an empty room in a 
** square cave. In other rooms the wumpus will spawn, 
** the bats, the pit, and the gold will spawn as well.
** The user will be able to move around in the cave and
** fire arrows in any direction. They will recieve 
** percepts if they are near any of these events. The 
** game is played according to all the rules. The goal is
** to leave with the gold through the escape rope.
** Input: Inputs include the command line for the size
** of the map and debug mode settings. Along with that,
** inputs will be movement around the map, firing arrows,
** and basic user choice when it comes to playing the
** game again and such.
** Output: Outputs include basic interface outputs, the
** the map, the percepts, and the encounters.
******************************************************/

int main (int argc, char * argv[]){
bool again = false;
string size= argv[1];
string debug = argv[2];
error_handle_cmd_line(size, debug);
    do{
        Cave active_cave(stoi(size), debug);
        again = active_cave.play_the_game();
    }while(again == true);
    cout << "Quitting now. Thanks for playing!" << endl;

    return 0;
}