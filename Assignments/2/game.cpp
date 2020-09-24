#include "game.h"
#include <cstdlib>

using namespace std;

Game::Game(){
    system("clear");
    cout << "Please enter your name: ";
    string name_input;
    getline(cin, name_input);
    players[0].set_name(name_input);
    print_deck();
    cout << "There are " << cards_left + 1 << " cards in the deck." << endl;
    players[0].fill_player_hand(cards_left, cards);
    players[0].print_hand();
    cout << "There are " << cards_left + 1 << " cards in the deck after dealing player 1" << endl;
    players[1].fill_player_hand(cards_left, cards);
    players[1].print_hand();
    cout << "There are " << cards_left + 1 << " cards in the deck after dealing player 2" << endl;
    
    active_card.set_card_rank(cards.get_card_info(cards_left, 0));
    active_card.set_card_suit(cards.get_card_info(cards_left, 1));
    cards_left = cards_left - 1;
    ////cout << "Game constructed." << endl;
}

bool Game::is_winner(){
    if(players[0].is_winner() == true || (cards_left == -1 && players[0].is_possible_play(active_card) == -1 && players[1].is_possible_play(active_card) == -1 && players[0].get_n_cards() < players[0].get_n_cards())){
        cout << players[0].get_name() << " has no cards left! " << players[0].get_name() << " won!" << endl << endl;
        return true;
    }
    else if(players[1].is_winner() == true || ((cards_left == -1 && players[0].is_possible_play(active_card) == -1 && players[1].is_possible_play(active_card) == -1 && players[0].get_n_cards() > players[0].get_n_cards()))){
        cout << "Uh oh! " << players[0].get_name() << " lost to a bot! The bot has no cards left!" << endl << endl;
        return true;
    }
    else if(cards_left == -1 && players[0].is_possible_play(active_card) == -1 && players[1].is_possible_play(active_card) == -1 && players[0].get_n_cards() == players[0].get_n_cards()){
        cout << "It's a draw! Neither of you can play, there's no more cards to draw, and you both have the same number of cards remaining!" << endl;
        return true;
    }
    return false;
}

void Game::play_the_game(){
    cout << "Game started! Player 1's turn..." << endl;
    do{
        players[0].display_active_card(active_card);
        players[0].play_card(active_card, cards_left, cards);
        ////cout << "in between play_card and print_hand" << endl;
        ////players[1].display_active_card(active_card);
        ////players[0].print_hand();
        players[1].ai_play(active_card, cards_left, cards);
    }while(is_winner() == false);
}

int Game::get_active_card_rank(){
    return active_card.get_card_rank();
}

int Game::get_active_card_suit(){
    return active_card.get_card_suit();
}

void Game::set_active_card_rank(int rank_choice){
    active_card.set_card_rank(rank_choice);
}

void Game::set_active_card_suit(int suit_choice){
    active_card.set_card_suit(suit_choice);
}

Game::~Game(){
    ////cout << "Game destroyed!" << endl;
    ////delete [] players;
}

void Game::print_deck(){
    cards.print_deck();
}

