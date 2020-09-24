#ifndef ROOM_H
#define ROOM_H
#include "event.h"
#include <cstddef>
#include "wumpus.h"

using namespace std;

class Room {
    private:
        
    protected:
        Event * room_event = NULL;
        bool spawn = false;
    public:

        //! Template for function header, DO NOT TOUCH
        /******************************************************
        ** Function: 
        ** Description: 
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        //! FUNCTIONS OF THE CLASS

        /******************************************************
        ** Function: Room
        ** Description: Basic constructor for the room class
        ** object. 
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Creates a room object.
        ******************************************************/

        Room();

        /******************************************************
        ** Function: ~Room
        ** Description: Basic destructor for the room class
        ** object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Frees the necessary memory and 
        ** destorys the object.
        ******************************************************/

        ~Room();

        //! FUNCTIONS OF THE GAME

        /******************************************************
        ** Function: kill_wumpus
        ** Description: Kills the wumpus.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Kills the wumpus and frees memory.
        ******************************************************/

        void kill_wumpus();

        /******************************************************
        ** Function: remove_wumpus
        ** Description: Removes the wumpus from the current 
        ** room.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Removes the wumpus from this room.
        ******************************************************/

        void remove_wumpus();

        /******************************************************
        ** Function: move_the_wumpus
        ** Description: Moves the wumpus to the room.
        ** Parameters: Event *
        ** Pre-conditions: Take in a pointer to an event class
        ** object, specifically the wumpus.
        ** Post-conditions: Set the room_event pointer equal to
        ** the parameter pointer.
        ******************************************************/

        void move_the_wumpus(Event *);

        /******************************************************
        ** Function: room_percept
        ** Description: Portal function for the room percept.
        ** Parameters: int, int, bool
        ** Pre-conditions: Take in an integer for player_index,
        ** an integer for size, and a bool for gold.
        ** Post-conditions: Passes into the event class for 
        ** the percept.
        ******************************************************/

        void room_percept(int, int, bool);

        //! ACCESSORS AND MUTATORS

        /******************************************************
        ** Function: set_wumpus_index
        ** Description: Basic mutator for the wumpus_index.
        ** Parameters: int
        ** Pre-conditions: Take in an integer to represent the 
        ** new index for the wumpus.
        ** Post-conditions: Change the index to the parameter
        ** value.
        ******************************************************/

        void set_wumpus_index(int);

        /******************************************************
        ** Function: set_spawn
        ** Description: Basic mutator for the spawn bool.
        ** Parameters: bool
        ** Pre-conditions: Take in a bool to represent the new
        ** value for the spawn bool.
        ** Post-conditions: Change the spawn bool to the 
        ** parameter value.
        ******************************************************/

        void set_spawn(bool);

        /******************************************************
        ** Function: get_the_wumpus
        ** Description: Basic accessor for the address to the
        ** wumpus object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Return a pointer to the wumpus
        ** object.
        ******************************************************/

        Event * get_the_wumpus();

        /******************************************************
        ** Function: set_room_event
        ** Description: Basic mutator for the room event.
        ** Parameters: int, int
        ** Pre-conditions: Take in an integer to represent the 
        ** new event and a temp.
        ** Post-conditions: Assign the room the correct event.
        ******************************************************/

        void set_room_event(int, int);

        /******************************************************
        ** Function: get_event
        ** Description: Basic accessor for the event integer.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Return an integer to represent the
        ** value of the event in the room.
        ******************************************************/

        int get_event();
};

#endif