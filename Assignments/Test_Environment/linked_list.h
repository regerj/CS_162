#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdlib>
#include "node.h"
#include <iostream>

using namespace std;

/******************************************************
** Class: Linked_List
** Purpose: A class to hold a pointer to the head node
** of a linked list as well as an integer representing
** how long the linked list is. It will also contain
** all of the necessary functions to give the linked
** list its real world functionality.
******************************************************/

class Linked_List {
    private:
        unsigned int length = 0;
        Node * head = NULL;
    public:

        //! TEMPLATE FOR FUNCTION HEADER, DO NOT TOUCH

        /******************************************************
        ** Function: 
        ** Description: 
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: NA
        ******************************************************/

        //! FUNCTIONS OF THE CLASS

        /******************************************************
        ** Function: Linked_List
        ** Description: Simple constructor for the linked list
        ** class. 
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Create the linked list, filling it
        ** with its members based on user input and setting its
        ** length respecitvely.
        ******************************************************/

        Linked_List(); //TODO// Code constructor

        //! ACCESSORS AND MUTATOTRS

        /******************************************************
        ** Function: get_length
        ** Description: Returns the length of the linked list.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Return an integer to show the length
        ** of the linked list.
        ******************************************************/

        int get_length(); //TODO// Code accessor

        /******************************************************
        ** Function: get_node
        ** Description: A funtion that returns a pointer to the
        ** node at the specified index.
        ** Parameters: int
        ** Pre-conditions: Take in an integer to represent the 
        ** index that the user wishes to retrieve the node at.
        ** Post-conditions: Unchanged, returns a pointer to the
        ** requested node.
        ******************************************************/

        Node * get_node(int); //TODO// Code get_node

        //! FUNCTIONS OF THE LINKED LIST

        /******************************************************
        ** Function: print
        ** Description: Simple function which parses through
        ** the linked list and prints its members to the screen.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Prints the linked list data members
        ** to the screen.
        ******************************************************/

        void print(); //TODO// Code print

        /******************************************************
        ** Function: clear
        ** Description: Clears the linked list, frees memory, 
        ** and resets the length and head member varaibles.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Clears all memory from the heap and
        ** resets all the member variables.
        ******************************************************/

        void clear(); //TODO// Code clear

        /******************************************************
        ** Function: push_front
        ** Description: Function to push a new node onto the
        ** front of the linked list.
        ** Parameters: int
        ** Pre-conditions: Take in an integer value to show the
        ** data to be stored to the new node.
        ** Post-conditions: Return an integer to represent the
        ** new length of the linked list.
        ******************************************************/

        unsigned int push_front(int); //TODO// Code push_front

        /******************************************************
        ** Function: push_back
        ** Description: Function to push a new node onto the
        ** back of the linked list.
        ** Parameters: int
        ** Pre-conditions: Take in an integer value to show the
        ** data to be stored to the new node.
        ** Post-conditions: Return an integer to represent the 
        ** new length of the linked list.
        ******************************************************/

        unsigned int push_back(int); //TODO// Code push_back

        /******************************************************
        ** Function: insert
        ** Description: Function to insert a new node at any
        ** index within the linked list.
        ** Parameters: int, unsigned int
        ** Pre-conditions: Take in an integer value to show the
        ** data to be stored to the new node as well as an 
        ** integer value to show which index to insert the node
        ** at.
        ** Post-conditions: Return an integer to represent the 
        ** new length of the linked list.
        ******************************************************/

        unsigned int insert(int, unsigned int); //TODO// Code insert

        /******************************************************
        ** Function: sort_ascending
        ** Description: Passthrough function for when the user
        ** decides to sort their linked list in ascending order.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Resorts the linked list to be in 
        ** ascending order.
        ******************************************************/

        void sort_ascending(); //TODO// Code sort_ascending

        /******************************************************
        ** Function: sort_descending
        ** Description: Passthrough function for when the user
        ** decides to sort their linekd list in descending 
        ** order.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Resorts the linked list to be in
        ** descending order.
        ******************************************************/

        void sort_descending(); //TODO// Code sort_descending

        /******************************************************
        ** Function: merge
        ** Description: Function which merges a left and a right
        ** linked list head.
        ** Parameters: Node *, Node *, bool
        ** Pre-conditions: Take in two node pointers to the left
        ** and right linked lists, as well as a boolean value
        ** to represent if it is to be sorted in descending 
        ** order or not.
        ** Post-conditions: Merges the two linked lists in the
        ** correct order.
        ******************************************************/

        Node * merge(Node *, Node *, bool);

        /******************************************************
        ** Function: merge_sort
        ** Description: Hub function for the recursive merge
        ** sort algorithm.
        ** Parameters: Node **, bool
        ** Pre-conditions: Take in a pointer to the node pointer
        ** to the head node as well as a boolean value to show
        ** if the sort is to be in descending order or not.
        ** Post-conditions: Call the correct recursive functions
        ** to sort the linked list.
        ******************************************************/

        void merge_sort(Node **, bool);

        /******************************************************
        ** Function: split_linked_list
        ** Description: Function which splits the given linked 
        ** list into two halves.
        ** Parameters: Node *, NOde **, Node **
        ** Pre-conditions: Take in a node pointer to the head of
        ** the linked list, as well as two pointers to either
        ** node pointers to the sides of the linked list.
        ** Post-conditions: Change the right and left node 
        ** pointers to be the appropriate nodes.
        ******************************************************/

        void split_linked_list(Node *, Node **, Node **);

        /******************************************************
        ** Function: prime_number_find
        ** Description: Function to find and print all of the
        ** prime numbers in the linked list, and includes any
        ** repeats.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Prints out all of the prime numbers
        ** in the linked list.
        ******************************************************/

        void prime_number_find();

        /******************************************************
        ** Function: choose_order
        ** Description: Hub function for the user to choose the
        ** order they wish the program to sort their linked list
        ** in.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Call on the appropriate function 
        ** based on what the user chooses.
        ******************************************************/

        void choose_order();

        /******************************************************
        ** Function: again
        ** Description: Hub function for the user to choose if
        ** they want to run the program again to make a new 
        ** linked list.
        ** Parameters: NA
        ** Pre-conditions: NA
        ** Post-conditions: Return a boolean value to represent
        ** if the user wants to run it again.
        ******************************************************/

        bool again();

        //! ERROR HANLDING FUNCTIONS

        /******************************************************
        ** Function: is_int
        ** Description: Simple error handling function which 
        ** tests a string to see if it is an integer or not, and
        ** returns a boolean value to reflect that.
        ** Parameters: string
        ** Pre-conditions: Take in a string to test.
        ** Post-conditions: Unchanged, return a boolean value
        ** of true if the string is an integer or a false if
        ** the string is not a valid integer.
        ******************************************************/

        bool is_int(string);
};

#endif