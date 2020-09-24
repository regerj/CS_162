#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
    private:

    protected:
        int age;
        int cost;
        int offspring_size;
        int base_food_cost = 80;
        int revenue;

    public:
        //! Template for function header, DO NOT TOUCH
        /******************************************************
        ** Function: 
        ** Description: 
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        /******************************************************
        ** Function: set_age
        ** Description: Simple accessor for the age member
        ** variable of the animal class and its children.
        ** Parameters: int
        ** Pre-conditions: Take in an integer value to show the
        ** new age of the animal.
        ** Post-conditions: Unchanged.
        ******************************************************/

        void set_age(int);

        /******************************************************
        ** Function: get_age
        ** Description: Simple accessor for the age member
        ** variable.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

       int get_age();

        /******************************************************
        ** Function: get_cost
        ** Description: Simple accessor for the cost member
        ** variable.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/
};

#endif