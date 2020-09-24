#include "wumpus.h"
#include <iostream>

using namespace std;

void Wumpus::percept(int player_index, int size, bool has_gold){
    int side_length = sqrt(size);
    if(player_index == 0 && (index == player_index + 1 || index == player_index + side_length || index == player_index + side_length + 1)){
        cout << "\tYou smell a terrible stench." << endl;
    }else if(player_index == side_length - 1 && (index == player_index - 1 || index == player_index + side_length || index == player_index + side_length - 1)){
        cout << "\tYou smell a terrible stench." << endl;
    }else if(player_index == size - 1 && (index == player_index - side_length || index == player_index - side_length - 1 || index == player_index - 1)){
        cout << "\tYou smell a terrible stench." << endl;
    }else if(player_index == size - side_length && (index == player_index + 1 || index == player_index - side_length || index == player_index - side_length + 1)){
        cout << "\tYou smell a terrible stench." << endl;
    }else if(player_index % side_length == 0 && (index == player_index - side_length || index == player_index - side_length + 1 || index == player_index + 1 || index == player_index + side_length || index == player_index + side_length + 1)){
        cout << "\tYou smell a terrible stench." << endl;
    }else if(player_index > 0 && player_index < sqrt(size) - 1 && ((index >= player_index - side_length - 1 && index <= player_index - side_length + 1) || (index >= player_index + side_length - 1 && index <= player_index + side_length + 1) || index == player_index - 1 || index == player_index + 1)){
        cout << "\tYou smell a terrible stench." << endl;
    }else if((player_index + 1) % side_length == 0 && (index == player_index - side_length || index == player_index - side_length - 1 || index == player_index - 1 || index == player_index + side_length || index == player_index + side_length - 1)){
        cout << "\tYou smell a terrible stench." << endl;
    }else if(player_index > size - side_length && player_index < size - 1 && ((index >= player_index - side_length - 1 && index <= player_index - side_length + 1) || (index >= player_index + side_length - 1 && index <= player_index + side_length + 1) || index == player_index - 1 || index == player_index + 1)){
        cout << "\tYou smell a terrible stench." << endl;
    }else if(player_index != 0 && player_index != side_length - 1 && player_index != size - 1 && player_index != size - side_length && player_index % side_length != 0 && player_index > side_length && (player_index + 1) % side_length != 0 && player_index < size - side_length){
        if(index >= player_index - side_length - 1 && index <= player_index - side_length + 1 || index >= player_index + side_length - 1 && index <= player_index + side_length + 1 || index == player_index - 1 || index == player_index + 1){
            cout << "\tYou smell a terrible stench." << endl;
        }
    }
}

int Wumpus::encounter(int player_index){
    cout << "You walk into the room and barely make out the sillohuette of a huge furry thing. It heaves, you have made a serious mistake. You have died." << endl;
    return -2;
}
int Wumpus::get_event(){
    return 4;
}

void Wumpus::set_index(int new_index){
    index = new_index;
}