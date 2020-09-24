#include <iostream>
#include "hand.h"

using namespace std;

int main(){
    Hand hand1;
    hand1.set_cards();
    hand1.get_cards();
    ////for(int i = 0; i < 7; i++){
        ////hand1.cards[i] = i;
    ////}
    Hand hand2 = hand1;
    hand2.get_cards();
    Hand hand3;
    hand3 = hand2;
    hand3.get_cards();
    return 0;
}