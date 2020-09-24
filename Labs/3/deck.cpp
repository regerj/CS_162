#include "deck.h"
#include <cstdlib>
#include <iostream>

using namespace std;

deck::deck(){
    //card cards [52];
    cout << "Deck created." << endl;
    int card_num = 0;
    for (int i = 1; i < 14; i++){
        for (int j = 1; j < 5; j++){
            cards[card_num].set_card_rank(i);
            if(j == 1){
                cards[card_num].set_card_suit("Diamonds");
            }
            if(j == 2){
                cards[card_num].set_card_suit("Clubs");
            }
            if(j == 3){
                cards[card_num].set_card_suit("Hearts");
            }
            if(j == 4){
                cards[card_num].set_card_suit("Spades");
            }
            card_num = card_num + 1;
        }
    }
}

deck::~deck(){
    cout << "Deck destroyed." << endl;
}

void deck::shuffle_deck(){
    srand(time(0));
    for (int i = 0; i < 52; i++){
        int remaining = i +(rand() % (52 - i));
        swap(cards[remaining], cards[i]);
    }
}

void deck::print_deck(){
    for(int i = 0; i < 52; i++){
        cout << "Card #" << i + 1 << endl;
        cout << "\tCard Suit: " << cards[i].get_card_suit() << endl;
        cout << "\tCard Rank: " << cards[i].get_card_rank() << endl << endl;
    }
}