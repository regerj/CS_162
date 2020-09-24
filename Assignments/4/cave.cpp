#include "cave.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "event.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

Cave::Cave(int side_length, string debug_mode){
    srand (time(NULL));
    player = new Player;
    size = side_length * side_length;
    construct_events(size);
    if(debug_mode == "true"){
        debugging = true;
    }else if(debug_mode == "false"){
        debugging = false;
    }
}

void Cave::construct_events(int size){
    gold_index = rand() % size;
    do{
        wumpus_index = rand() % size;
    }while(wumpus_index == gold_index);
    do{
        spawn_index = rand() % size;
    }while(spawn_index == gold_index || spawn_index == wumpus_index);
    do{
        bats_index = rand() % size;
    }while(bats_index == spawn_index || bats_index == gold_index || bats_index == wumpus_index);
    do{
        pit_index = rand() % size; 
    }while(pit_index == bats_index || pit_index == spawn_index || pit_index == gold_index || pit_index == wumpus_index);
    game_board.resize(size);
    game_board[wumpus_index].set_room_event(1, wumpus_index);
    game_board[spawn_index].set_spawn(true);
    game_board[bats_index].set_room_event(2, bats_index);
    game_board[pit_index].set_room_event(3, pit_index);
    game_board[gold_index].set_room_event(4, gold_index);
}

void Cave::turn(){
    print_cave();
        cout << endl << "What you notice: " << endl;
        game_board[bats_index].room_percept(player_position, size, player->get_gold());
        game_board[gold_index].room_percept(player_position, size, player->get_gold());
        game_board[pit_index].room_percept(player_position, size, player->get_gold());
        if(wumpus_alive == true){
            game_board[wumpus_index].room_percept(player_position, size, player->get_gold());
        }
        cout << endl;
        move_player_choice();
        //!system("clear");
        cout << endl << "Encounters: " << endl;
        is_encounter();
        cout << endl;
}

bool Cave::play_the_game(){
    string again_choice;
    player_position = spawn_index;
    player->set_arrows(3);
    while(player_position != wumpus_index && player_position != pit_index && (player_position != spawn_index || player->get_gold() != true)){
        turn();
    }
    if(player_position == spawn_index){
        cout << "\tYou climb up the rope, gold securely in your sack. It's time to go home..." << endl;
    }else{
        cout << "\tYou perished in the cave." << endl;
    }
    cout << "Would you like to play again with the same cave, play again with a differnt cave, or quit (1, 2, or 3): ";
    getline(cin, again_choice);
    while(again_choice != "1" && again_choice != "2" && again_choice != "3"){
        cout << "Invalid choice. Please enter '1' to play again in the same cave, '2' to play again in a different cave, or '3' to quit: ";
        getline(cin, again_choice);
    }
    if(again_choice == "1"){
        player->set_gold(false);
        return play_the_game();
    }else if(again_choice == "2"){
        return true;
    }else if(again_choice == "3"){
        return false;
    }
}

void Cave::move_player_choice(){
    string choice;
    cout << "Which direction do you want to move in (w, a, s, d) or do you want to fire one of your arrows (space): ";
    getline(cin, choice);
    while(choice != "w" && choice != "a" && choice != "s" && choice != "d" && (choice == " " && player->get_arrows() < 1)){
        if(choice == " "){
            cout << "You reach for an arrow, but find none left in your quiver... Best be careful from now on. Please choose a direction to move in (w, a, s, d): ";
        }else{
            cout << "Invalid input! Please choose a direction to move in (w, a, s, d) or to fire an arrow (space): ";
        }
        getline(cin, choice);
    }
    move_player(choice);
}

void Cave::is_encounter(){
    if(player_position == gold_index && player->get_gold() == false){
        cout << "\tBy the faint light of your lantern, you notice the glimmer of gold. You pick the gold up and put it into your sack. Now if you could find your way back..." << endl;
        player->set_gold(true);
    }else if(player_position == wumpus_index){
        cout << "\tYou find yourself into the room and barely make out the sillohuette of a huge furry thing. It heaves, and you realize your mistake too late. You have died." << endl;
    }else if(player_position == pit_index){
        cout << "\tIn the faint light you fail to notice a massive abyss. It's too late now. You have died." << endl;
    }else if(player_position == bats_index){
        cout << "\tAll of the sudden giant bats swoop in and pick you up! You have no idea where they're taking you..." << endl;
        do{
            player_position = rand() % size;
        }while(player_position == bats_index);
        cout << "\tThe bats finally let go of your arms and you fall." << endl;
        is_encounter();
    }
}

void Cave::wumpus_move(int move_chance){
    int new_index;
    if(move_chance != 0 && wumpus_alive == true){
        do{
            new_index = rand() % size;
        }while(game_board[new_index].get_event() != 0);
        game_board[new_index].move_the_wumpus(game_board[wumpus_index].get_the_wumpus());
        game_board[wumpus_index].remove_wumpus();
        game_board[new_index].set_wumpus_index(new_index);
        wumpus_index = new_index;
    }
}

void Cave::fire_arrow_a_cont(int move_chance, int side_length){
    if(player_position % side_length != 0){
        if(wumpus_index == player_position - 1){
            hit_wumpus();
        }else if((player_position - 1) % side_length != 0){
            if(wumpus_index == player_position - 2){
                hit_wumpus();
            }else if((player_position - 2) % side_length != 0){
                if(wumpus_index == player_position - 3){
                    hit_wumpus();
                }else{
                    miss_arrow(move_chance);
                }
            }else{
                miss_arrow(move_chance);
            }
        }else{
            miss_arrow(move_chance);
        }
    }else{
        miss_arrow(move_chance);
    }
}

void Cave::hit_wumpus(){
    cout << "You hear a light thud, and the feral pained scream of a beast. Its protests fade until it goes silent. The cave is much safer wihtout that...thing." << endl;
    game_board[wumpus_index].kill_wumpus();
    wumpus_index = -1111;
    wumpus_alive = false;
}

void Cave::miss_arrow(int move_chance){
    cout << "You hear the tip of your arrow clink against the stone loudly. You must have missed, you hope nothing heard that..." << endl;
    wumpus_move(move_chance);
}

void Cave::fire_arrow_d_cont(int move_chance, int side_length){
    if((player_position + 1) % side_length != 0){
        if(wumpus_index == player_position + 1){
            hit_wumpus();
        }else if((player_position + 2) % side_length != 0){
            if(wumpus_index == player_position + 2){
                hit_wumpus();
            }else if((player_position + 3) % side_length != 0){
                if(wumpus_index == player_position + 3){
                    hit_wumpus();
                }else{
                    miss_arrow(move_chance);
                }
            }else{
                miss_arrow(move_chance);
            }
        }else{
            miss_arrow(move_chance);
        }
    }else{
        miss_arrow(move_chance);
    }
}

void Cave::fire_arrow(string dir){
    int move_chance = rand() % 4;
    int side_length = sqrt(size);
    cout << "You let the arrow fly, and hope it finds its target." << endl;
    if(dir == "w" && (wumpus_index == player_position - sqrt(size) || wumpus_index == player_position - 2 * sqrt(size) || wumpus_index == player_position - 3 * sqrt(size))){
        hit_wumpus();
    }else if(dir == "w"){
        miss_arrow(move_chance);
    }else if(dir == "a"){
        fire_arrow_a_cont(move_chance, side_length);
    }else if(dir == "s" && (wumpus_index == player_position + sqrt(size) || wumpus_index == player_position + 2 * sqrt(size) || wumpus_index == player_position + 3 * sqrt(size))){
        hit_wumpus();
    }else if(dir == "s"){
        miss_arrow(move_chance);
    }else if(dir == "d"){
        fire_arrow_d_cont(move_chance, side_length);
    }
    player->set_arrows(player->get_arrows() - 1);
}

void Cave::move_player(string choice){
    int side_length = sqrt(size);
    if(choice == "w" && player_position - side_length >= 0){
        player_position = player_position - side_length;
    }else if(choice == "s" && player_position + side_length < size){
        player_position = player_position + side_length;
    }else if(choice == "a" && player_position % side_length != 0){
        player_position = player_position - 1;
    }else if(choice == "d" && (player_position + 1) % side_length != 0){
        player_position = player_position + 1;
    }else if((choice == "w" && player_position - side_length < 0) || (choice == "s" && player_position + side_length > size - 1) || (choice == "a" && player_position % side_length == 0) || (choice == "d" && (player_position + 1) % side_length == 0)){
        cout << "In the dark you stumble and bump into a wall. Probably don't want to go that way." << endl;
    }else if(choice == " " && player->get_arrows() > 0){
        cout << "You knock and draw an arrow on your bow. Best be careful, there are things asleep in these caves... Which direction do you aim (w, a, s, d): ";
        getline(cin, choice);
        while(choice != "w" && choice != "a" && choice != "s" && choice != "d"){
            cout << "Invalid direction! Please choose a direction to fire in (w, a, s, d): ";
            getline(cin, choice);
        }
        fire_arrow(choice);
    }
}

void Cave::print_cave(){
    for(int i = 0; i < sqrt(size); i++){
        for(int j = 0; j < sqrt(size); j++){
            cout << "+-----";
        }
        cout << "+" << endl;
        for(int j = 0; j < sqrt(size); j++){
            cout << "|     ";
        }
        cout << "|" << endl;
        for(int j = 0; j < sqrt(size); j++){
            cout << "|  ";
            if(i * sqrt(size) + j == player_position){
                cout << "*  ";
            }else{
                cout << "   ";
            }
        }
        cout << "|" << endl;
        if(debugging == true){
            for(int j = 0; j < sqrt(size); j++){
                cout << "|  ";
                if(game_board[(i * sqrt(size)) + j].get_event() == 0){
                    cout << "   ";
                }else{
                    cout << game_board[(i * sqrt(size)) + j].get_event() << "  ";
                }
            }
            cout << "|" << endl;
        }else{
            for(int j = 0; j < sqrt(size); j++){
                cout << "|     ";
            }
            cout << "|" << endl;
        }
    }
    for(int i = 0; i < sqrt(size); i++){
        cout << "+-----";
    }
    cout << "+" << endl;
}

Cave::~Cave(){
    delete player;
}