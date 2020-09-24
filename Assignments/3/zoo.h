#ifndef ZOO_H
#define ZOO_H

using namespace std;

class Zoo{
    private:
        int bank_balance;
        Tiger * tigers;
        SeaLion * sealions;
        Bear * bears;
        int tiger_count;
        int sea_lion_count;
        int bear_count;
        bool attendance_boom = false;
        int base_cost = 80;
    public:
        //! Function header template DO NOT TOUCH
        /******************************************************
        ** Function: 
        ** Description: 
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        //! FUNCTIONS OF THE CLASS

        /******************************************************
        ** Function: Zoo
        ** Description: Simple constructor for the zoo class
        ** object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        Zoo(); //TODO// Code this constructor
        
        /******************************************************
        ** Function: ~Zoo
        ** Description: Simple destructor for the zoo class
        ** object.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/
        
        ~Zoo(); //TODO Code this destructor

        //! FUNCTIONS OF THE GAME

        /******************************************************
        ** Function: sick_*animal*
        ** Description: Three identical functions to apply
        ** sickness to the respective animal, deduct for care,
        ** or kill the animal if it cannot be afforded.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void sick_tiger();
        void sick_bear();
        void sick_sealion();

        /******************************************************
        ** Function: kill_*animl*
        ** Description: Kills an animal and removes it from the
        ** zoo.
        ** Parameters: int
        ** Pre-conditions: Take in an integer to represent which
        ** of the *animal* to kill.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void kill_tiger(int);
        void kill_bear(int);
        void kill_sealion(int);

        /******************************************************
        ** Function: count_animals
        ** Description: Counts the adult and baby animals of
        ** each species.
        ** Parameters: int &, int &, int &, int &, int &, int &
        ** Pre-conditions: Take in pointers to integer values 
        ** representing the counts of the adult and baby members
        ** of each species.
        ** Post-conditions: Set those integer values to the 
        ** correct values.
        ******************************************************/

        void count_animals(int &, int &, int &, int &, int &, int &);

        /******************************************************
        ** Function: is_loss
        ** Description: Tests the user to see if they have lost
        ** the game.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        bool is_loss();

        /******************************************************
        ** Function: birth
        ** Description: Function for an animal giving birth to
        ** offspring.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void birth();

        /******************************************************
        ** Function: apply_sick
        ** Description: Simple function that applies sickness
        ** to the animal if possible.
        ** Parameters: bool, bool, bool
        ** Pre-conditions: Take in three boolean values to show
        ** which species have a member to even get sick.
        ** Post-conditions: Unchanged.
        ******************************************************/

        bool apply_sick(bool, bool, bool);

        /******************************************************
        ** Function: sick
        ** Description: Gets one random animal sick and the
        ** zookeeper must care for them.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void sick();

        /******************************************************
        ** Function: special_event
        ** Description: Simple hub for the speciale event to be
        ** selected and then call the associated function.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void special_event();

        /******************************************************
        ** Function: compute_food_cost
        ** Description: Compute the food cost for the turn and
        ** deduct it from the bank balance.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void compute_food_cost(); 

        /******************************************************
        ** Function: compute_revenue
        ** Description: Compute the revenue for the turn and
        ** add the net revenue to your balance.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void compute_revenue(); //TODO// Code this function

        /******************************************************
        ** Function: turn_hub_function
        ** Description: This function acts as a hub to execute
        ** a single turn in the game.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void turn_hub_function();

        /******************************************************
        ** Function: purchase_tiger
        ** Description: Simple function that shallow copies the
        ** current tigers and adds dynamic memory to the end of
        ** the new array to add tigers.
        ** Parameters: int
        ** Pre-conditions: Takes in an int to represent the num
        ** of tigers to purchase.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void purchase_tiger(int, int);

        /******************************************************
        ** Function: purchase_sea_lion
        ** Description: Simple function that shallow copies the
        ** current sea lions and adds dynamic memory to the end of
        ** the new array to add sea lions.
        ** Parameters: int
        ** Pre-conditions: Takes in an int to represent the num
        ** of sea lions to purchase.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void purchase_sea_lion(int, int);

        /******************************************************
        ** Function: purchase_bear
        ** Description: Simple function that shallow copies the
        ** current bears and adds dynamic memory to the end of
        ** the new array to add bears.
        ** Parameters: int
        ** Pre-conditions: Takes in an int to represent the num
        ** of bears to purchase.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void purchase_bear(int, int);

        /******************************************************
        ** Function: animal_purchase_choice
        ** Description: Simple driver with user input to direct
        ** the choice to purchase or not, and how many to buy.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void animal_purchase_choice();

        /******************************************************
        ** Function: purchase_animal
        ** Description: Function to purchase animals.
        ** Parameters: int
        ** Pre-conditions: Take in the number of animals the
        ** user wants to buy.
        ** Post-conditions: Unchanged.
        ******************************************************/

        //? Place functions in each animal class or keep everything here using accessors and mutators.
        ////void purchase_animal(int); //TODO Code this function

        /******************************************************
        ** Function: increment_ages
        ** Description: Ages all of the animals forward by one
        ** month.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        void increment_ages(); //TODO// Code this function

        //! ACCESSOR FUNCTIONS

        /******************************************************
        ** Function: get_tiger_count
        ** Description: Simple accessor for the tiger count
        ** member variable.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        int get_tiger_count(); //TODO// Code this accessor

        /******************************************************
        ** Function: get_sea_lion_count
        ** Description: Simple accessor for the sea lion count
        ** member variable.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        int get_sea_lion_count(); //TODO// Code this accessor

        /******************************************************
        ** Function: get_bear_count
        ** Description: Simple accessor for the bear count
        ** member variable.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        int get_bear_count(); //TODO// Code this accessor

        /******************************************************
        ** Function: get_bank_balance
        ** Description: Simple accessor for the bank_balance
        ** member variable.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        int get_bank_balance(); //TODO// Code this accessor

        //! MUTATOR FUNCTIONS

        /******************************************************
        ** Function: set_bank_balance
        ** Description: Simple mutator for the bank_balance
        ** member variable.
        ** Parameters: int
        ** Pre-conditions: Take in an integer value of the new
        ** bank balance.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void set_bank_balance(int); //TODO// Code this mutator
    
};

#endif