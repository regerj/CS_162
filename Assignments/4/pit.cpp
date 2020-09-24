#include "pit.h"
#include <iostream>

using namespace std;

void Pit::percept(int player_index, int size, bool has_gold){
    int side_length = sqrt(size);
    if(player_index == 0 && (index == player_index + 1 || index == player_index + side_length || index == player_index + side_length + 1)){
        cout << "\tYou feel a breeze." << endl;
    }else if(player_index == side_length - 1 && (index == player_index - 1 || index == player_index + side_length || index == player_index + side_length - 1)){
        cout << "\tYou feel a breeze." << endl;
    }else if(player_index == size - 1 && (index == player_index - side_length || index == player_index - side_length - 1 || index == player_index - 1)){
        cout << "\tYou feel a breeze." << endl;
    }else if(player_index == size - side_length && (index == player_index + 1 || index == player_index - side_length || index == player_index - side_length + 1)){
        cout << "\tYou feel a breeze." << endl;
    }else if(player_index % side_length == 0 && (index == player_index - side_length || index == player_index - side_length + 1 || index == player_index + 1 || index == player_index + side_length || index == player_index + side_length + 1)){
        cout << "\tYou feel a breeze." << endl;
    }else if(player_index > 0 && player_index < sqrt(size) - 1 && ((index >= player_index - side_length - 1 && index <= player_index - side_length + 1) || (index >= player_index + side_length - 1 && index <= player_index + side_length + 1) || index == player_index - 1 || index == player_index + 1)){
        cout << "\tYou feel a breeze." << endl;
    }else if((player_index + 1) % side_length == 0 && (index == player_index - side_length || index == player_index - side_length - 1 || index == player_index - 1 || index == player_index + side_length || index == player_index + side_length - 1)){
        cout << "\tYou feel a breeze." << endl;
    }else if(player_index > size - side_length && player_index < size - 1 && ((index >= player_index - side_length - 1 && index <= player_index - side_length + 1) || (index >= player_index + side_length - 1 && index <= player_index + side_length + 1) || index == player_index - 1 || index == player_index + 1)){
        cout << "\tYou feel a breeze." << endl;
    }else if(player_index != 0 && player_index != side_length - 1 && player_index != size - 1 && player_index != size - side_length && player_index % side_length != 0 && player_index > side_length && (player_index + 1) % side_length != 0 && player_index < size - side_length){
        if(index >= player_index - side_length - 1 && index <= player_index - side_length + 1 || index >= player_index + side_length - 1 && index <= player_index + side_length + 1 || index == player_index - 1 || index == player_index + 1){
            cout << "\tYou feel a breeze." << endl;
        }
    }
}

int Pit::encounter(int player_index){
    cout << "The tunnel door opens up into a massive pit and you fall in. You have died." << endl;
    return -2;
}

int Pit::get_event(){
    return 3;
}

void Pit::set_index(int new_index){
    index = new_index;
}