#include "event.h"
#include "room.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"

#include <iostream>

using namespace std;

Room::Room(){

}

void Room::kill_wumpus(){
    delete room_event;
    room_event = NULL;
}

void Room::remove_wumpus(){
    room_event = NULL;
}

void Room::move_the_wumpus(Event * wumpus){
    room_event = wumpus;
}

void Room::set_room_event(int new_event, int temp){
    if(new_event == 1){
        room_event = new Wumpus;
        room_event->set_index(temp);
    }
    else if(new_event == 2){
        room_event = new Bats;
        room_event->set_index(temp);
    }else if(new_event == 3){
        room_event = new Pit;
        room_event->set_index(temp);
    }else if(new_event == 4){
        room_event = new Gold;
        room_event->set_index(temp);
    }
}

void Room::room_percept(int player_index, int size, bool has_gold){
    room_event->percept(player_index, size, has_gold);
}

void Room::set_spawn(bool new_spawn){
    spawn = new_spawn;
}

int Room::get_event(){
    if(spawn == true){
        return 5;
    }else if(room_event != NULL){
        return room_event->get_event();
    }else{
        return 0;
    }
}

void Room::set_wumpus_index(int new_index){
    room_event->set_index(new_index);
}

Event * Room::get_the_wumpus(){
    return room_event;
}

Room::~Room(){
    delete room_event;
}