#include "animal.h"
#include "bear.h"
#include "sea_lion.h"
#include "tiger.h"
#include "zoo.h"
#include <iostream>
#include <cstdlib>

//TODO// Code for a special event
//TODO// Code for the extra revenue from Sea Lions
//TODO// Code for a sick/dead animal
//TODO// Code to check if you lost
//TODO// Fix formatting and make the output nice
//TODO?// Make a nice zoo status output for the screen
//TODO// Test game flow and try to break it
//TODO?// Give the player the option to end the game
//TODO// Code to check if the player has lost the game
//TODO// Check over the rubric
//TODO// Code to kill an animal if it gets sick

/******************************************************
** Program: zoo_keeper
** Author: Jacob Reger
** Date: 02/14/2020
** Description: This program will play the zoo keeper
** game where the user will be able to purchase animals
** of 3 different species and care for them. They will
** earn revenue based on these animals. They must care
** for the animals if they get sick. The animals may give
** birth and age. They will die if they cannot be cared
** for. Special events may occur during the turns
** including attendance boom, sickness, or birth. The
** game will continue until the user goes bankrupt or
** chooses to exit.
** Input: Inputs include decisions to keep playing, buy
** animals, which animals, and how many to purchase.
** Output: Outputs include basic interface outputs, the
** animal populations in the zoo, the bank balance, and
** updates on things happening in the game.
******************************************************/

using namespace std;

int main(){
    system("clear");
    Zoo zoo1;
    while(zoo1.is_loss() == false){
        string quit;
        zoo1.turn_hub_function();
        cout << "Would you like to quit the current game (yes or no): ";
        getline(cin, quit);
        while(quit != "yes" && quit != "no"){
            cout << "Invalid input! Please type either 'yes' or 'no': ";
            getline(cin, quit);
        }
        if(quit == "yes"){
            break;
        }
    }
    if(zoo1.is_loss() == true){
        cout << "Uh oh! Your zoo when bankrupt! Better luck next time!" << endl;
    }
    return 0;
}





//TODO Use friendship with zookeeper and operator overloading.