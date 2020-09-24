#ifndef CARD_H
#define CARD_H
#include <cstdlib>
#include <iostream>

using namespace std;

class Card{
    private:
        int suit;
        int rank;
    public:
        string get_card_suit();
        int get_card_rank();
        void set_card_suit(string);
        void set_card_rank(int);
};

#endif