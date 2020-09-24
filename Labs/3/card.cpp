#include "card.h"
#include <cstdlib>

using namespace std;

string card::get_card_suit(){
    return suit;
}
int card::get_card_rank(){
    return rank;
}
void card::set_card_suit(string card_suit){
    suit = card_suit;
}
void card::set_card_rank(int card_rank){
    rank = card_rank;
}