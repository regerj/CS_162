#include "player.h"
#include <string>

using namespace std;

Player::Player(){
    ////cout << "Player Created!" << endl;
}

Player::~Player(){
    ////cout << "Player Destroyed!" << endl;
    ////delete hand;
}

int Player::get_n_cards(){
    return hand.get_n_cards();
}

int Player::is_possible_play(Card & active_card){
    for(int i = 0; i < hand.get_n_cards(); i++){
        if(hand.get_hand_card_rank(i) == active_card.get_card_rank() || hand.get_hand_card_suit(i) == active_card.get_card_suit()){
            ////cout << "Returning card index (1): " << i << endl;
            return i;
        }
    }
    for(int i = 0; i < hand.get_n_cards(); i++){
        if(hand.get_hand_card_rank(i) == 8){
            ////cout << "Returning card index (2): " << i << endl;
            return i;
        }
    }
    return -1;
}

void Player::ai_play(Card & active_card, int & cards_left, Deck game_deck){
    while(is_possible_play(active_card) == -1){
        hand.increment_hand(cards_left, game_deck);
    }
    hand.decrement_hand(is_possible_play(active_card) + 1, active_card);
}

bool Player::is_int(string num){
    if(num.length() == 0){
        ////cout << "Exiting is_int with 1 at 1" << endl;
        return 0;
    }
    ////cout << "Entered is_int" << endl;
    if(num.at(0) != 45 && (num.at(0) > 57 || num.at(0) < 48)){
        ////cout << "Exiting is_int with 0 at 1" << endl;
        return 0;
    }
    for(int i = 1; i < num.length(); i++){
        ////cout << "Entered the for loop of is_int" << endl;
        if(num.at(i) > 57 || num.at(i) < 48){
            ////cout << "Exiting is_int with 0 at 2" << endl;
            return 0;
        }
    }
    ////cout << "Exiting is_int with 1" << endl;
    return 1; 
}

void Player::display_active_card(Card & active_card){
    system("clear");
    cout << "Active Card: " << endl;
    if(active_card.get_card_suit() == 0){
        cout << "\t Card Suit: Spades" << endl;
    }
    else if(active_card.get_card_suit() == 1){
        cout << "\t Card Suit: Diamonds" << endl;
    }
    else if(active_card.get_card_suit() == 2){
        cout << "\t Card Suit: Clubs" << endl;
    }
    else if(active_card.get_card_suit() == 3){
        cout << "\t Card Suit: Hearts" << endl;
    }

    if(active_card.get_card_rank() == 1){
        cout << "\t Card Rank: Ace" << endl << endl;
    }
    else if(active_card.get_card_rank() == 11){
        cout << "\t Card Rank: Jack" << endl << endl;
    }
    else if(active_card.get_card_rank() == 12){
        cout << "\t Card Rank: Queen" << endl << endl;
    }
    else if(active_card.get_card_rank() == 13){
        cout << "\t Card Rank: King" << endl << endl;
    }
    else{
        cout << "\t Card Rank: " << active_card.get_card_rank() << endl << endl;
    }

}

//TODO// Finish this function to play a card.
void Player::play_card(Card & active_card, int & cards_left, Deck game_deck){
    int draw_count = 0;
    while(is_possible_play(active_card) == -1){
        hand.increment_hand(cards_left, game_deck);
        draw_count = draw_count + 1;
    }
    if(draw_count != 0){
        cout << "You had to draw " << draw_count << " cards until you got a playable one!" << endl << endl;
    }
    string choice;
    cout << "Choose a card to play!" << endl << endl << "This is your hand: " << endl << endl;
    do{
        choice = choose_card(active_card);
    }while(hand.test_if_valid(stoi(choice), active_card, 1) == false);
    hand.decrement_hand(stoi(choice), active_card);
    ////cout << "successfully decremented hand" << endl;
}

string Player::choose_card(Card & active_card){
    string choice;
    hand.print_hand();
    cout << endl << "Select the card you wish to play!" << endl << "Card #";
    getline(cin, choice);
    while(choice.length() > 2){
        cout << "Inputting too many characters! You only need 2!" << endl << "Card #";
        getline(cin, choice);
    }
    while(is_int(choice) == true){
        if(stoi(choice) > hand.get_n_cards() || stoi(choice) <= 0 || hand.test_if_valid(stoi(choice), active_card, 1) == false){
            cout << "Invalid card choice! Please try again." << endl << "Card #";
            getline(cin, choice);
        }
        else if(hand.test_if_valid(stoi(choice), active_card, 0) == true){
                ////cout << "Valid choice!" << endl;
                active_card.set_card_rank(hand.get_hand_card_rank(stoi(choice) - 1));
                active_card.set_card_suit(hand.get_hand_card_suit(stoi(choice) - 1));
                return choice;
        }
    }
    while(is_int(choice) == false){
        cout << "Invalid card choice! Use integer values to represent the card you want to play." << endl << "Card #";
        getline(cin, choice);
    }
    ////cout << "returning choice!" << endl;
    return choice;
}

string Player::get_name(){
    return name;
}

bool Player::is_winner(){
    if(hand.get_n_cards() == 0){
        return true;
    }
    return false;
}

void Player::print_hand(){
    hand.print_hand();
}

void Player::fill_player_hand(int & cards_left, Deck game_deck){
    hand.remake_hand(cards_left, game_deck);
}

void Player::set_name(string input){
    name = input;
}