
#include <iostream>

using namespace std;

class Hand {
    private:
        int * cards;
        int n_cards;
    public:
        void set_cards();
        void get_cards();
        Hand();
        ~Hand();
        Hand(const Hand & og_hand);
        Hand & operator=(const Hand & og_hand);
};