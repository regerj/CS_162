#include "card.h"
#include <cstdlib>

using namespace std;

Card::Card(){
    ////cout << "Card created!" << endl;
}

Card::~Card(){
    ////cout << "Card destroyed!" << endl;
}

int Card::get_card_suit(){
    return suit;
}
int Card::get_card_rank(){
    return rank;
}
void Card::set_card_suit(int card_suit){
    suit = card_suit;
}
void Card::set_card_rank(int card_rank){
    rank = card_rank;
}