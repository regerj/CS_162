#include "hand.h"

using namespace std;

Hand::Hand(){
    cout << "Constructor called!" << endl;
    cards = new int[7];
    n_cards = 7;
}

void Hand::set_cards(){
    for(int i = 0; i < 7; i++){
        cards[i] = i;
    }
}

void Hand::get_cards(){
    cout << "{";
    for(int i = 0; i < 7; i++){
        cout << cards[i] << " ";
    }
    cout << "}" << endl;
}

Hand::~Hand(){
    cout << "Destructor called!" << endl;
    delete [] cards;
}

Hand::Hand(const Hand & og_hand){
    cout << "Copy constructor called!" << endl;
    this->n_cards = og_hand.n_cards;
    this->cards = new int[n_cards];
    for(int x = 0; x < n_cards; x++){
        cards[x] = og_hand.cards[x];
    }
}

Hand & Hand::operator=(const Hand & og_hand){
    cout << "Assignment operator overload called!" << endl;
    delete [] cards;
    this->n_cards = og_hand.n_cards;
    this->cards = new int [n_cards];
    for(int x = 0; x < n_cards; x++){
        cards[x] = og_hand.cards[x];
    }
    return *this;
}