#include "gold.h"
#include <iostream>
#include <cmath>

using namespace std;

void Gold::percept(int player_index, int size, bool has_gold){
    int side_length = sqrt(size);
    if(has_gold == false){
        if(player_index == 0 && (index == player_index + 1 || index == player_index + side_length || index == player_index + side_length + 1)){
            cout << "\tYou see a glimmer nearby." << endl;
        }else if(player_index == side_length - 1 && (index == player_index - 1 || index == player_index + side_length || index == player_index + side_length - 1)){
            cout << "\tYou see a glimmer nearby." << endl;
        }else if(player_index == size - 1 && (index == player_index - side_length || index == player_index - side_length - 1 || index == player_index - 1)){
            cout << "\tYou see a glimmer nearby." << endl;
        }else if(player_index == size - side_length && (index == player_index + 1 || index == player_index - side_length || index == player_index - side_length + 1)){
            cout << "\tYou see a glimmer nearby." << endl;
        }else if(player_index % side_length == 0 && (index == player_index - side_length || index == player_index - side_length + 1 || index == player_index + 1 || index == player_index + side_length || index == player_index + side_length + 1)){
            cout << "\tYou see a glimmer nearby." << endl;
        }else if(player_index > 0 && player_index < sqrt(size) - 1 && ((index >= player_index - side_length - 1 && index <= player_index - side_length + 1) || (index >= player_index + side_length - 1 && index <= player_index + side_length + 1) || index == player_index - 1 || index == player_index + 1)){
            cout << "\tYou see a glimmer nearby." << endl;
        }else if((player_index + 1) % side_length == 0 && (index == player_index - side_length || index == player_index - side_length - 1 || index == player_index - 1 || index == player_index + side_length || index == player_index + side_length - 1)){
            cout << "\tYou see a glimmer nearby." << endl;
        }else if(player_index > size - side_length && player_index < size - 1 && ((index >= player_index - side_length - 1 && index <= player_index - side_length + 1) || (index >= player_index + side_length - 1 && index <= player_index + side_length + 1) || index == player_index - 1 || index == player_index + 1)){
            cout << "\tYou see a glimmer nearby." << endl;
        }else if(player_index != 0 && player_index != side_length - 1 && player_index != size - 1 && player_index != size - side_length && player_index % side_length != 0 && player_index > side_length && (player_index + 1) % side_length != 0 && player_index < size - side_length){
            if(index >= player_index - side_length - 1 && index <= player_index - side_length + 1 || index >= player_index + side_length - 1 && index <= player_index + side_length + 1 || index == player_index - 1 || index == player_index + 1){
                cout << "\tYou see a glimmer nearby." << endl;
            }
        }
    }
}

int Gold::encounter(int player_index){
    cout << "You find the gold and pocket it. Better get out of here..." << endl;
    return -1;
}

int Gold::get_event(){
    return 2;
}
void Gold::set_index(int new_index){
    index = new_index;
}