#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"

using namespace std;

/******************************************************
** Class: Game
** Purpose: A class to hold all of the relevant 
** variables that make up a game object, as well as
** all of its necessary functionality.
******************************************************/

class Game {
    private:
        int cards_left = 51;
        Deck cards;
        Player players[2];
        Card active_card;
    public:
        /******************************************************
        ** Function: Game
        ** Description: Constructor to create a game of crazy
        ** eights.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        *****************************************************/

        Game(); //TODO// Code this constructor

        /******************************************************
        ** Function: play_the_game
        ** Description: Driving function for the loop that 
        ** plays the game.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        *****************************************************/

        void play_the_game();
        
        /******************************************************
        ** Function: get_active_card_rank
        ** Description: Simple accessor for the int value of
        ** the active card's rank.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Returns the active card's rank.
        *****************************************************/

        int get_active_card_rank();
        
        /******************************************************
        ** Function: get_active_card_suit
        ** Description: Simple accessor for the int value of 
        ** the active card's suit.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Returns the active card's suit.
        *****************************************************/

        int get_active_card_suit();
        
        /******************************************************
        ** Function: set_active_card_rank
        ** Description: Simple mutator for the active card's
        ** rank.
        ** Parameters: int
        ** Pre-conditions: Take in an int value.
        ** Post-conditions: Unchanged.
        *****************************************************/
        
        void set_active_card_rank(int);
        
        /******************************************************
        ** Function: set_active_card_suit
        ** Description: Simple mutator for the active card's
        ** suit.
        ** Parameters: int
        ** Pre-conditions: Take in an int value.
        ** Post-conditions: Unchanged.
        *****************************************************/

        void set_active_card_suit(int);
        
        /******************************************************
        ** Function: ~Game()
        ** Description: Destructor for the game object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        *****************************************************/
        
        ~Game(); //TODO// Code this destructor
        
        /******************************************************
        ** Function: print_deck
        ** Description: Prints the deck, used only for
        ** debugging, the deck remains hidden in game.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        *****************************************************/
        
        void print_deck();
        
        /******************************************************
        ** Function: is_winner
        ** Description: Determines if there is a winner in the
        ** game at any given time.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Returns a boolean value to
        ** represent the presence of a winner.
        *****************************************************/
        
        bool is_winner();
        
        //?// Might need accessors and mutators for private variables
};

#endif