#ifndef CARD_H
#define CARD_H
#include <cstdlib>
#include <iostream>

using namespace std;

/******************************************************
** Class: Card
** Purpose: A class to hold all of the relevant 
** variables that make up a card object, as well as
** all of its necessary functionality.
******************************************************/

class Card{
    private:
        int suit;
        int rank;
    public:
        //TODO// Create constructor, destructor, accessor, and mutator

        /******************************************************
        ** Function: Card
        ** Description: Simple constructor for a card object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        Card(); //TODO// Code constructor

        /******************************************************
        ** Function: ~Card
        ** Description: Simple destructor for a card object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        ~Card(); //TODO// Code destructor

        /******************************************************
        ** Function: get_card_suit
        ** Description: Simple accessor for a card's suit.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Return an integer for the card's
        ** suit.
        ******************************************************/

        int get_card_suit();

        /******************************************************
        ** Function: get_card_rank
        ** Description: Simple accessor for a card's rank.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Returna an integer for the card's 
        ** suit.
        ******************************************************/

        int get_card_rank();

        /******************************************************
        ** Function: set_card_suit
        ** Description: Simple mutator for a card's suit.
        ** Parameters: int
        ** Pre-conditions: Take in an integer for the new suit.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void set_card_suit(int);

        /******************************************************
        ** Function: set_card_rank
        ** Description: Simple mutator for a card's rank.
        ** Parameters: int
        ** Pre-conditions: Take in an integer for the new rank.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void set_card_rank(int);
};

#endif