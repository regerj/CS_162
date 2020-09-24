#include <iostream>
#include <cstdlib>
#include "deck.h"
#include "hand.h"
#include "game.h"

using namespace std;

//TODO// Error handle stoi() function to prevent crashes, and check error handling on all other functions
//TODO// Fill out all function headers
//TODO// FIll out program header
//TODO// Code the draw functions for the user
//TODO// Check over the functionality of the AI and whether or not it is working
//TODO Check over the rubric
//TODO// Make sure that the program can play again with a completely different deck.
//TODO!// AI is having problems validating a play before playing it, appears to play from hand, and always first card in hand the first time...

/******************************************************
** Program: crazy_eights
** Author: Jacob Reger
** Date: 02/1/2020
** Description: The following program will be capable
** of playing a one player game of crazy eights against 
** an unintelligent ai. It will allow the player to 
** type in a name. It will create a deck of 52 cards,
** shuffle them, and doll out 7 card hands to the ai
** and the player. The player will not be able to see 
** either the deck or the ai's hand. The player will be
** presented with their hand and the active card each 
** turn. The ai will play in between player turns. The
** game will continue until a win condition is met.
** After which, the player will be informed of the 
** result, and will be prompted if they wish to play 
** again with a new deck.
** Input: Input will include the player name, the cards
** that the player wishes to play each turn, and finally
** in the event that the player plays a crazy eight, 
** they will input which suit they want the deck to be
** changed to. The player will also input if they wish
** to play again.
** Output: Output will simply be text to the screen to
** update the player as to the state of the game.
******************************************************/

int main(){
    ////Deck game_deck;
    string again;
    do{
        Game game1;
        game1.play_the_game();
        cout << "Would you like to play again? (yes or no): ";
        getline(cin, again);
        while(again != "yes" && again != "no"){
            cout << "Invalid input, please choose 'yes' or 'no'. Would you like to play again: ";
            getline(cin, again);
        }
    }
    while(again == "yes");
    
    return 0;
}