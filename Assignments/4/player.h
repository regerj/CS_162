#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player{
    private:
        bool has_gold = false;
        int arrows_left = 3;
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

        //! ACCESSORS AND MUTATORS

        /******************************************************
        ** Function: get_arrows
        ** Description: Simple acccessor for the number of 
        ** arrows the player has left.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Returns the number of arrows that 
        ** the player has left.
        ******************************************************/

        int get_arrows();

        /******************************************************
        ** Function: set_arrows
        ** Description: Simple mutator for the number of arrows
        ** the player has left.
        ** Parameters: int
        ** Pre-conditions: Take in an integer to represent the 
        ** new number of arrows for the user.
        ** Post-conditions: Set the arrow count equal to the
        ** parameter value.
        ******************************************************/

        void set_arrows(int);

        /******************************************************
        ** Function: get_gold
        ** Description: Simple accessor for the boolean for if
        ** the user has the gold.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Return the boolean of the gold.
        ******************************************************/

        bool get_gold();

        /******************************************************
        ** Function: set_gold
        ** Description: Simple mutator for the boolean value
        ** gold.
        ** Parameters: bool
        ** Pre-conditions: Take in the new value of the gold
        ** boolean.
        ** Post-conditions: Set gold equal to the parameter.
        ******************************************************/

        void set_gold(bool);
};

#endif