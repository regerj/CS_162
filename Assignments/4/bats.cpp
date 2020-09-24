#include "bats.h"
#include <iostream>
#include <cmath>

using namespace std;

void Bats::percept(int player_index, int size, bool has_gold){
    int side_length = sqrt(size);
    if(player_index == 0 && (index == player_index + 1 || index == player_index + side_length || index == player_index + side_length + 1)){
        cout << "\tYou hear wingls flapping." << endl;
    }else if(player_index == side_length - 1 && (index == player_index - 1 || index == player_index + side_length || index == player_index + side_length - 1)){
        cout << "\tYou hear wingls flapping." << endl;
    }else if(player_index == size - 1 && (index == player_index - side_length || index == player_index - side_length - 1 || index == player_index - 1)){
        cout << "\tYou hear wingls flapping." << endl;
    }else if(player_index == size - side_length && (index == player_index + 1 || index == player_index - side_length || index == player_index - side_length + 1)){
        cout << "\tYou hear wingls flapping." << endl;
    }else if(player_index % side_length == 0 && (index == player_index - side_length || index == player_index - side_length + 1 || index == player_index + 1 || index == player_index + side_length || index == player_index + side_length + 1)){
        cout << "\tYou hear wingls flapping." << endl;
    }else if(player_index > 0 && player_index < sqrt(size) - 1 && ((index >= player_index - side_length - 1 && index <= player_index - side_length + 1) || (index >= player_index + side_length - 1 && index <= player_index + side_length + 1) || index == player_index - 1 || index == player_index + 1)){
        cout << "\tYou hear wingls flapping." << endl;
    }else if((player_index + 1) % side_length == 0 && (index == player_index - side_length || index == player_index - side_length - 1 || index == player_index - 1 || index == player_index + side_length || index == player_index + side_length - 1)){
        cout << "\tYou hear wingls flapping." << endl;
    }else if(player_index > size - side_length && player_index < size - 1 && ((index >= player_index - side_length - 1 && index <= player_index - side_length + 1) || (index >= player_index + side_length - 1 && index <= player_index + side_length + 1) || index == player_index - 1 || index == player_index + 1)){
        cout << "\tYou hear wingls flapping." << endl;
    }else if(player_index != 0 && player_index != side_length - 1 && player_index != size - 1 && player_index != size - side_length && player_index % side_length != 0 && player_index > side_length && (player_index + 1) % side_length != 0 && player_index < size - side_length){
        if(index >= player_index - side_length - 1 && index <= player_index - side_length + 1 || index >= player_index + side_length - 1 && index <= player_index + side_length + 1 || index == player_index - 1 || index == player_index + 1){
            cout << "\tYou hear wingls flapping." << endl;
        }
    }
}

int Bats::encounter(int player_index){
    cout << "All of the sudden giant bats swoop in and pick you up! You have no idea where they're taking you..." << endl;
}

int Bats::get_event(){
    return 1;
}

void Bats::set_index(int new_index){
    index = new_index;
}