#ifndef HAND_H
#define HAND_H
#include "card.h"
#include "deck.h"
#include <iostream>

using namespace std;

/******************************************************
** Class: Hand
** Purpose: A class to hold all of the relevant 
** variables that make up a hand object, as well as
** all of its necessary functionality.
******************************************************/

class Hand {
    private:
        Card * cards;
        int n_cards;
        string ranks_of_cards[13];
    public:

        /******************************************************
        ** Function: Hand
        ** Description: Simple constructor for a hand object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        Hand(); //TODO// Code this constructor

        /******************************************************
        ** Function: ~Hand
        ** Description: Simple destructor for a hand object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        ~Hand(); //TODO// Code this destructor

        /******************************************************
        ** Function: increment_hand
        ** Description: Draws one card from the deck and places 
        ** it in the players hand.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void increment_hand(int &, Deck);

        /******************************************************
        ** Function: get_n_cards
        ** Description: Simple accessor for n_cards.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Returns an integer representing 
        ** n_cards.
        ******************************************************/

        int get_n_cards(); //TODO// Code this accessor

        /******************************************************
        ** Function: print_hand
        ** Description: Prints the player's hand to the screen.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void print_hand();

        /******************************************************
        ** Function: decrement_hand
        ** Description: Plays the card from the hand that the 
        ** player selects and removes that card object from the
        ** hand.
        ** Parameters: int, Card &
        ** Pre-conditions: Take in an integer choice and a 
        ** reference to the active card object.
        ** Post-conditions: Change the active card to the
        ** played card.
        ******************************************************/

        void decrement_hand(int, Card &);

        /******************************************************
        ** Function: test_if_valid
        ** Description: Tests if a card is valid to play onto
        ** the current active card.
        ** Parameters: int, Card &, int
        ** Pre-conditions: Take in an integer for the choice,
        ** the active card object, and an integer to represent 
        ** who is playing.
        ** Post-conditions: No change to the parameters.
        ******************************************************/

        bool test_if_valid(int, Card &, int);

        /******************************************************
        ** Function: get_hand_card_rank
        ** Description: Simple accessor for an individual card
        ** rank in the hand.
        ** Parameters: int
        ** Pre-conditions: Take in an integer value to 
        ** represent which card to get the rank of.
        ** Post-conditions: Unchanged.
        ******************************************************/

        int get_hand_card_rank(int);

        /******************************************************
        ** Function: get_hand_card_suit
        ** Description: simple accessor for an individual card
        ** suit in the hand.
        ** Parameters: int
        ** Pre-conditions: Take in an integer value to 
        ** represent which card to get the rank of.
        ** Post-conditions: Unchanged.
        ******************************************************/

        int get_hand_card_suit(int);

        /******************************************************
        ** Function: set_n_cards
        ** Description: Simple mutator for n_cards.
        ** Parameters: int
        ** Pre-conditions: Takes in an integer value to
        ** represent what the new card count is.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void set_n_cards(int); //TODO// Code this mutator

        /******************************************************
        ** Function: remake_hand
        ** Description: Makes the hand properly initialize with
        ** the top 7 cards on the deck.
        ** Parameters: int &. Deck
        ** Pre-conditions: Take in a reference to the cards_left
        ** and the game_deck Deck object.
        ** Post-conditions: Draw from the game deck and change
        ** the cards_left value to represent that.
        ******************************************************/

        void remake_hand(int & cards_left, Deck game_deck);
        ////Hand & operator=(const Hand & og_hand);
};

#endif