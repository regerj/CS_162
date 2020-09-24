#ifndef CAVE_H
#define CAVE_H
#include "room.h"
#include "player.h"
#include <vector>
#include <iostream>

using namespace std;

class Cave {
    private:
        int gold_index;
        int wumpus_index;
        int spawn_index;
        int bats_index;
        int pit_index;
        int size;
        bool wumpus_alive = true;
        bool debugging;
        int player_position;
        vector<Room> game_board;
        Player * player;
    protected:
    public: 

        //! Template for function header, DO NOT TOUCH
        /******************************************************
        ** Function: 
        ** Description: 
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        //! FUNCTIONS OF THE CLASS

        /******************************************************
        ** Function: Cave
        ** Description: Parameterized constructor for the cave
        ** class object.
        ** Parameters: int, string
        ** Pre-conditions: Take in an integer to represent the
        ** length of the cave sides and a string to represent
        ** the debug settings.
        ** Post-conditions: Create a cave object, a player 
        ** object, and all relevant values are initialized.
        ******************************************************/

        Cave(int, string);

        /******************************************************
        ** Function: ~Cave
        ** Description: Basic destructor for the cave class
        ** object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Frees the dynamic memory found in 
        ** the player object as well as the event objects.
        ******************************************************/

        ~Cave();

        //! FUNCTIONS OF THE GAME

        /******************************************************
        ** Function: turn
        ** Description: A hub function for a player's turn.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Executes all necessary other
        ** functions to compute a single turn.
        ******************************************************/

        void turn();

        /******************************************************
        ** Function: construct_events
        ** Description: Implemented function to construct all 
        ** of the events in the cave.
        ** Parameters: int
        ** Pre-conditions: Take in an integer to represent the
        ** size of the cave.
        ** Post-conditions: Change some random rooms to contain
        ** the events.
        ******************************************************/

        void construct_events(int);

        /******************************************************
        ** Function: hit_wumpus
        ** Description: Function for computing the result of 
        ** a fired arrow striking the wumpus.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Kill the wumpus and inform the user
        ** that this has happened.
        ******************************************************/

        void hit_wumpus();

        /******************************************************
        ** Function: miss_arrow
        ** Description: Function to execute the result of a
        ** fired arrow missing the wumpus.
        ** Parameters: int
        ** Pre-conditions: Take in a random integer 0-3 and with
        ** that wake the wumpus up at 75% rate and move him.
        ** Post-conditions: Moves the wumpus 75% of the time to
        ** another empty room.
        ******************************************************/

        void miss_arrow(int);

        /******************************************************
        ** Function: fire_arrow_a_cont
        ** Description: Function to execute the conditionals to
        ** test for the outcome of firing an arrow in the left
        ** direction.
        ** Parameters: int, int
        ** Pre-conditions: Take in a random integer to represent
        ** the chance the wumpus moves if you miss and an int
        ** to represent the length of the cave.
        ** Post-conditions: Call the correct result of firing
        ** the arrow via other functions.
        ******************************************************/

        void fire_arrow_a_cont(int, int);

        /******************************************************
        ** Function: fire_arrow_d_cont
        ** Description: Function to execute the conditionals to
        ** test for the outcome of firing an arrow in the right
        ** direction.
        ** Parameters: int, int
        ** Pre-conditions: Take in a random integer to represent
        ** the chance the wumpus moves if you miss and an int
        ** to represent the length of the cave.
        ** Post-conditions: Call the correct result of firing
        ** the arrow via other functions.
        ******************************************************/

        void fire_arrow_d_cont(int, int);

        /******************************************************
        ** Function: wumpus_move
        ** Description: Function to move the wumpus if it wakes
        ** up and clean up the memory.
        ** Parameters: int
        ** Pre-conditions: Take in an integer to represent the
        ** move chance.
        ** Post-conditions: Calculate the wumpus movement to 
        ** a random room and clean memory.
        ******************************************************/

        void wumpus_move(int);

        /******************************************************
        ** Function: fire_arrow
        ** Description: Hub function for firing an arrow.
        ** Parameters: string
        ** Pre-conditions: Take in a string to represent the
        ** direction that the user wants to fire in.
        ** Post-conditions: Call the appropriate functions to
        ** fire the arrow and all of its consequences.
        ******************************************************/

        void fire_arrow(string);

        /******************************************************
        ** Function: is_encounter
        ** Description: Tests for an encounter and calls the
        ** appropriate functions if an encounter is found to 
        ** occur.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Alert the user of the encounter
        ** that has occured if one has, and call the appropriate
        ** changes based on that encounter.
        ******************************************************/

        void is_encounter();

        /******************************************************
        ** Function: play_the_game
        ** Description: Hub function for playing the game.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Plays the game and calls all other
        ** necessary functions.
        ******************************************************/

        bool play_the_game();

        /******************************************************
        ** Function: print_cave
        ** Description: Prints the current state of the cave, 
        ** accounts for debugging mode.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Print out the cave.
        ******************************************************/

        void print_cave();

        /******************************************************
        ** Function: move_player
        ** Description: Implementation function to make the 
        ** player move in the appropriate direction if possible.
        ** Parameters: string
        ** Pre-conditions: Take in a string to represent the 
        ** direction to move the player.
        ** Post-conditions: Move the player in that direction
        ** if possible.
        ******************************************************/

        void move_player(string);

        /******************************************************
        ** Function: move_player_choice
        ** Description: Interface function to get the user to 
        ** choose a direction to move in or fire.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Interface with the user and get the
        ** move from the user.
        ******************************************************/

        void move_player_choice();
        
};

#endif