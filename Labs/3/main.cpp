#include <iostream>
#include <cstdlib>
#include "deck.h"

using namespace std;

int main(){
    deck Deck;
    Deck.shuffle_deck();
    Deck.print_deck();

    return 0;
}