#include "player.h"

using namespace std;

bool Player::get_gold(){
    return has_gold;
}

void Player::set_gold(bool set_to){
    has_gold = set_to;
}

int Player::get_arrows(){
    return arrows_left;
}

void Player::set_arrows(int new_count){
    arrows_left = new_count;
}