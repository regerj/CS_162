#include "node.h"
#include "linked_list.h"
#include <iostream>

using namespace std;

//TODO// Error handle the value inputs
//TODO// Check over the rubric

/******************************************************
** Program: LL_Test
** Author: Jacob Reger
** Date: 03/15/2020
** Description: This program test the implementation
** of my from-scratch linked list class. It will 
** construct a linked list object and prompt the user
** to fill it with as many values as they wish. It will
** then print their linked list, and ask them which order
** they wish to sort the list in. It will then sort the 
** list, and print it again. It will then tell the user 
** how many prime numbers are in the list, before
** clearing the list and prompting the user to do it
** again.
** Input: Inputs include the data values to be stored
** in each of the nodes of the linked list, a 
** confirmation that the user wishes to enter another
** data point, whether the user wants to sort in
** ascending or descending order, and finally if the
** user wants to run the program again.
** Output: Outputs include basic interface outputs and 
** the linked list.
******************************************************/

int main() {
    bool again = false;
    do{
        Linked_List L1;
        L1.print();
        L1.choose_order();
        L1.print();
        L1.prime_number_find();
        L1.clear();
        again = L1.again();
    }while(again == true);

    return 0;
}