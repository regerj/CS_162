#include "deck.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Deck::Deck(){
    ////card cards [52];
    ////cout << "Deck created." << endl;
    int card_num = 0;
    for (int i = 1; i < 14; i++){
        for (int j = 1; j < 5; j++){
            cards[card_num].set_card_rank(i);
            if(j == 1){
                cards[card_num].set_card_suit(3);
            }
            if(j == 2){
                cards[card_num].set_card_suit(2);
            }
            if(j == 3){
                cards[card_num].set_card_suit(1);
            }
            if(j == 4){
                cards[card_num].set_card_suit(0);
            }
            card_num = card_num + 1;
        }
    }
    shuffle_deck();
}

Deck::~Deck(){
    ////cout << "Deck destroyed." << endl;
}

int Deck::get_card_info(int card_num, int rank_suit){
    ////cout << "cards_left as seen in get_card_info is: " << card_num + 1 << endl;
    ////cout << "value of card at " << card_num + 1 << " is rank: " << cards[card_num].get_card_rank() << " and suit: " << cards[card_num].get_card_suit() << endl;
    if(rank_suit == 0){
        return cards[card_num].get_card_rank();
    }
    else if(rank_suit == 1){
        return cards[card_num].get_card_suit();
    }
}

void Deck::shuffle_deck(){
    srand(time(0));
    for (int i = 0; i < 52; i++){
        int remaining = i +(rand() % (52 - i));
        swap(cards[remaining], cards[i]);
    }
}

void Deck::print_deck(){
    for(int i = 0; i < 52; i++){
        cout << "Card #" << i + 1 << endl;
        cout << "\tCard Suit: " << cards[i].get_card_suit() << endl;
        cout << "\tCard Rank: " << cards[i].get_card_rank() << endl << endl;
    }
}