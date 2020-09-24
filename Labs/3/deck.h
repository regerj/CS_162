#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <cstdlib>
#include "card.h"

using namespace std;

class deck{
    private:
        Card cards[52];
        int n_cards;
    public:
        deck();
        ~deck();
        void shuffle_deck();
        void print_deck();
};

#endif

