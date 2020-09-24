#ifndef EVENT_H
#define EVENT_H
#include <cmath>
//#include "wumpus.h"

using namespace std;

class Event {
    private:
    protected:
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
        ** Function: Event
        ** Description: Placehold constructor
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        Event();

        //! FUNCTIONS OF THE GAME

        /******************************************************
        ** Function: percept
        ** Description: This function determines and prints 
        ** the appropriate percept if necessary.
        ** Parameters: int, int, bool
        ** Pre-conditions: Take in an integer to represent the
        ** size, an integer to represent the player_index, and
        ** a boolean to represent if the player has the gold.
        ** Post-conditions: Unchanged, just prints the percept
        ** if necessary.
        ******************************************************/

        virtual void percept(int, int, bool) = 0;

        /******************************************************
        ** Function: encounter
        ** Description: This function determines an encounter
        ** and deals with it in turn.
        ** Parameters: int
        ** Pre-conditions: Takes in an int to represent the 
        ** location of the player.
        ** Post-conditions: Unchanged, just prints the correct
        ** message.
        ******************************************************/

        virtual int encounter(int) = 0;

        //! ACCESSORS AND MUTATORS

        /******************************************************
        ** Function: get_event
        ** Description: Simple accessor for what event this
        ** is.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Returns an integer value to show
        ** what the event is.
        ******************************************************/

        virtual int get_event() = 0;

        /******************************************************
        ** Function: set_index
        ** Description: Simple mutator to change the index of 
        ** this event.
        ** Parameters: int
        ** Pre-conditions: Take in an integer to represent the
        ** new index for the event.
        ** Post-conditions: Change the index of the event to
        ** the new index.
        ******************************************************/

        virtual void set_index(int) = 0;
};

#endif