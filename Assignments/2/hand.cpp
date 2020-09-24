#include "hand.h"
#include "deck.h"
#include <iostream>
#include <string>

using namespace std;

Hand::Hand(){
    ranks_of_cards[0] = "Ace";
    for(int i = 1; i < 10; i++){
        ranks_of_cards[i] = to_string(i+1);
    }
    ranks_of_cards[10] = "Jack";
    ranks_of_cards[11] = "Queen";
    ranks_of_cards[12] = "King";
}

void Hand::remake_hand(int & cards_left, Deck game_deck){
    ////cout << "An instance of new.1 has been called!" << endl;
    ////delete [] cards;
    ////cout << "Hand created" << endl;
    cards = new Card [7];
    n_cards = 7;
    ////cout << "cards left as seen in remake_hand: " << cards_left + 1 << endl;
    for(int i = 0; i < 7; i++){
        cards[i].set_card_rank(game_deck.get_card_info(cards_left, 0));
        cards[i].set_card_suit(game_deck.get_card_info(cards_left, 1));
        cards_left = cards_left - 1;
    }
    
}

bool Hand::test_if_valid(int choice, Card & active_card, int temp){
    if(cards[choice-1].get_card_rank() == 8 && temp == 0){
        string input;
        cout << "You have chosen a CrAzY EiGhT! What suit (spades, diamonds, clubs, or hearts) would you like to change it to: ";
        getline(cin, input);
        while(input != "spades" && input != "diamonds" && input != "clubs" && input != "hearts"){
            cout << "Invalid choice! Please input a choice as they appear here -> (spades, diamonds, clubs, or hearts): ";
            getline(cin, input);
        }
        if(input == "spades"){
            cards[choice - 1].set_card_suit(0);
        }else if(input == "diamonds"){
            cards[choice - 1].set_card_suit(1);
        }else if(input == "clubs"){
            cards[choice - 1].set_card_suit(2);
        }else if(input == "hearts"){
            cards[choice - 1].set_card_suit(3);
        }
        return true;
    }else if(cards[choice - 1].get_card_rank() == active_card.get_card_rank() || cards[choice - 1].get_card_suit() == active_card.get_card_suit()){
        return true;
    }else if(cards[choice - 1].get_card_rank() == 8 && temp == 1){
        return true;
    }
    return false;
}

int Hand::get_hand_card_rank(int index){
    return cards[index].get_card_rank();
}

int Hand::get_hand_card_suit(int index){
    return cards[index].get_card_suit();
}

void Hand::decrement_hand(int card_played, Card & active_card){
    Card * temp;
    ////cout << "Calling an instance of new.2" << endl;
    temp = new Card [n_cards - 1];
    for(int i = 0; i < n_cards; i++){
        if(i < card_played - 1){
            temp[i].set_card_suit(cards[i].get_card_suit());
            temp[i].set_card_rank(cards[i].get_card_rank()); 
        }
        else if(i > card_played - 1){
            temp[i - 1].set_card_suit(cards[i].get_card_suit());
            temp[i - 1].set_card_rank(cards[i].get_card_rank());
        }
    }
    active_card.set_card_rank(cards[card_played - 1].get_card_rank());
    active_card.set_card_suit(cards[card_played - 1].get_card_suit());

    ////cout << "Reached delete cards function in decrement" << endl;
    delete [] cards;
    /////cout << "Passed deletion of original cards" << endl;
    cards = temp;
    n_cards = n_cards - 1;
}

void Hand::increment_hand(int & cards_left, Deck game_deck){
    Card * temp;
    temp = new Card [n_cards + 1];
    for(int i = 0; i < n_cards; i++){
        temp[i].set_card_suit(cards[i].get_card_suit());
        temp[i].set_card_rank(cards[i].get_card_rank());
    }
    ////cout << "Reached delete fards function in increment" << endl;
    delete [] cards;
    /////cout << "Passed deletion of original cards" << endl;
    cards = temp;

    cards[n_cards].set_card_rank(game_deck.get_card_info(cards_left, 0));
    cards[n_cards].set_card_suit(game_deck.get_card_info(cards_left, 1));

    cards_left = cards_left - 1;
    n_cards = n_cards + 1;
}

int Hand::get_n_cards(){
    return n_cards;
}

Hand::~Hand(){
    ////cout << "Hand delete function called!" << endl;
    delete [] cards;
    ////cout << "Successfully deleted hand." << endl;
}

void Hand::print_hand(){
    for(int i = 0; i < n_cards; i++){
        cout << "Card #" << i + 1 << endl;
        if(cards[i].get_card_suit() == 0){
            cout << "\t Card Suit: Spades" << endl;
        }
        else if(cards[i].get_card_suit() == 1){
            cout << "\t Card Suit: Diamonds" << endl;
        }
        else if(cards[i].get_card_suit() == 2){
            cout << "\t Card Suit: Clubs" << endl;
        }
        else if(cards[i].get_card_suit() == 3){
            cout << "\t Card Suit: Hearts" << endl;
        }
        ////cout << "\t Card Suit: " << cards[i].get_card_suit() << endl;
        cout << "\t Card Rank: " << ranks_of_cards[cards[i].get_card_rank() - 1] << endl;
        
       //cout << "\t Card Suit: " << cards[i].get_card_suit() << endl;
       //cout << "\t Card Rank: " << cards[i].get_card_rank() << endl;
    }
}
