#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"

using namespace std;

/******************************************************
** Class: Player
** Purpose: A class to hold all of the relevant 
** variables that make up a player object, as well as
** all of its necessary functionality.
******************************************************/

class Player {
    private:
        Hand hand;
        string name;
    public:

        /******************************************************
        ** Function: Player
        ** Description: Simple constructor for a player object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        Player(); //TODO// Code this constructor

        /******************************************************
        ** Function: ~Player
        ** Description: Simple destructor for a player object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        ~Player(); //TODO// Code this destructor

        /******************************************************
        ** Function: get_name
        ** Description: Simple accessor for the player's name.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Return a string of the player's 
        ** name.
        ******************************************************/

        string get_name(); //TODO// Code this accessor

        /******************************************************
        ** Function: print_hand
        ** Description: Prints the player's hand.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void print_hand();

        /******************************************************
        ** Function: play_card
        ** Description: Header function for a player to play a
        ** card.
        ** Parameters: Card &, int &, Deck
        ** Pre-conditions: Take in a reference to the active
        ** card, a reference to the cards left in the deck, and
        ** a deck object to draw from.
        ** Post-conditions: All remain unchanged by this
        ** function.
        ******************************************************/

        void play_card(Card &, int &, Deck);

        /******************************************************
        ** Function: is_winner
        ** Description: Determines if there is a winner in the
        ** game.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Returns a boolean value to show
        ** if the player is a winner.
        ******************************************************/

        bool is_winner();

        /******************************************************
        ** Function: set_name
        ** Description: Simple mutator for the name of a player
        ** object.
        ** Parameters: string
        ** Pre-conditions: Take in a string to represent the
        ** new name.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void set_name(string); //TODO// Code this mutator
        ////string get_name();

        /******************************************************
        ** Function: ai_play
        ** Description: Header file for executing an ai play.
        ** Parameters: Card &, int &, Deck
        ** Pre-conditions: Take in a reference to the active
        ** card object, a reference to the number of cards left
        ** in the deck, and the deck object.
        ** Post-conditions: Will eventually change the active
        ** card objects member variables.
        ******************************************************/

        void ai_play(Card &, int &, Deck);

        /******************************************************
        ** Function: is_possible_play
        ** Description: Tests if there is a possible play in a
        ** player's hand and which card is possible.
        ** Parameters: Card &
        ** Pre-conditions: Take in a reference to the active
        ** card object.
        ** Post-conditions: Return an integer value to show
        ** which card in the hand is viable to play.
        ******************************************************/

        int is_possible_play(Card &);

        /******************************************************
        ** Function: is_int
        ** Description: Simple error handling function to test
        ** if a given string is an integer value. Only used
        ** within this class.
        ** Parameters: string
        ** Pre-conditions: Take in a string to test.
        ** Post-conditions: Return a boolean value to represent
        ** if the string is an integer or not.
        ******************************************************/

        bool is_int(string);

        /******************************************************
        ** Function: choose_card
        ** Description: Simple driving function for choosing a
        ** card.
        ** Parameters: Card &
        ** Pre-conditions: Take in a reference to the active
        ** card object.
        ** Post-conditions: Return a string to show which card
        ** they chose.
        ******************************************************/

        string choose_card(Card &);

        /******************************************************
        ** Function: display_active_card
        ** Description: Simply outputs the active card rank and
        ** suit to the string.
        ** Parameters: Card &
        ** Pre-conditions: Take in a reference to the active
        ** card object.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void display_active_card(Card &);

        /******************************************************
        ** Function: fill_player_hand
        ** Description: Fills the players hand with cards.
        ** Parameters: int &, Deck
        ** Pre-conditions: Take in a reference to the cards left
        ** in the deck as well as the literal deck object.
        ** Post-conditions: Draw cards from the deck and change
        ** the cards_left accordingly.
        ******************************************************/

        void fill_player_hand(int & cards_left, Deck game_deck);

        /******************************************************
        ** Function: get_n_cards
        ** Description: Simple accessor to retrieve the value
        ** of n_cards.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Return an integer value to show
        ** what n_cards is equal to.
        ******************************************************/

        int get_n_cards();
        
        //?// Might need mutator and accessor for Hand class hand

};

#endif