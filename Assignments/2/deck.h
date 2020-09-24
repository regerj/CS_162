#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <cstdlib>
#include "card.h"

using namespace std;

/******************************************************
** Class: Deck
** Purpose: A class to hold all of the relevant 
** variables that make up a deck object, as well as
** all of its necessary functionality.
******************************************************/

class Deck{
    private:
        Card cards[52];
        int n_cards;
    public:
        //TODO// Create constructor, destructor, accessor, and mutator

        /******************************************************
        ** Function: Deck
        ** Description: Simple constructor for the deck object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        Deck(); //?// May need editing for use case

        /******************************************************
        ** Function: ~Deck
        ** Description: Simple destructor for the deck object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        ~Deck(); //?// May need editing for use case

        /******************************************************
        ** Function: get_deck_n_cards
        ** Description: Simple accessor for the deck_n_cards.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Return an integer value to show
        ** the value of n_cards.
        ******************************************************/

        int get_deck_n_cards(); //TODO// Code this accessor

        /******************************************************
        ** Function: set_deck_n_cards
        ** Description: Simple mutator for the deck_n_cards
        ** Parameters: int
        ** Pre-conditions: Take in an integer value of the new
        ** n_cards.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void set_deck_n_cards(int); //TODO// Code this mutator

        /******************************************************
        ** Function: get_card_info
        ** Description: Complex accessor driver to get the info
        ** of a card in the deck object.
        ** Parameters: int, int
        ** Pre-conditions: Take in integer values to represent 
        ** which value to retrieve and which card to retrieve
        ** it from.
        ** Post-conditions: Return the value requested.
        ******************************************************/

        int get_card_info(int, int);

        /******************************************************
        ** Function: shuffle_deck
        ** Description: Shuffles the deck after it has been
        ** created.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void shuffle_deck();

        /******************************************************
        ** Function: print_deck
        ** Description: Prints the deck, only used for debug.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void print_deck(); //!// Probably wont need this function for the use case
};

#endif