
#include "animal.h"
#include "tiger.h"
#include "sea_lion.h"
#include "bear.h"
#include "zoo.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Zoo::Zoo(){ //TODO// Finish this constructor
    bank_balance = 100000;
    tiger_count = 0;
    sea_lion_count = 0;
    bear_count = 0;
    cout << "Welcome to your new zoo! You are starting out with $100000 dollars; good luck!" << endl;
}

Zoo::~Zoo(){ //TODO// Finish this destructor
    delete [] tigers;
    delete [] bears;
    delete [] sealions;
}

void Zoo::compute_revenue(){ //TODO// Code for potential sea lion extra income
    for(int i = 0; i < tiger_count; i++){
        if(tigers[i].get_age() < 6){
            bank_balance = bank_balance + 2400;
        }else{
            bank_balance = bank_balance + 1200;
        }
    }for(int i = 0; i < bear_count; i++){
        if(bears[i].get_age() < 6){
            bank_balance = bank_balance + 1000;
        }else{
            bank_balance = bank_balance + 500;
        }
    }for(int i = 0; i < sea_lion_count; i++){
        if(attendance_boom == false){
            if(sealions[i].get_age() < 6){
                bank_balance = bank_balance + 280;
            }else{
                bank_balance = bank_balance + 140;
            }
        }else if(attendance_boom == true){
            if(sealions[i].get_age() < 6){
                bank_balance = bank_balance + 2 * (140 + rand() % 251 + 150);
            }else{
                bank_balance = bank_balance + 140 + rand() % 251 + 150;
            }
        }
    }
}

void Zoo::compute_food_cost(){
    srand(time(NULL));
    float cost_adjustment = (rand() % 5 + 8) / 10.0;
    base_cost = base_cost * cost_adjustment;
    cout << "Current base cost of food: " << base_cost << endl;
    for(int i = 0; i < tiger_count; i++){
        float temp1 = 5 * base_cost;
        bank_balance = bank_balance - temp1;
    }
    for(int i = 0; i < sea_lion_count; i++){
        float temp2 = base_cost;
        bank_balance = bank_balance - temp2;
    }
    for(int i  = 0; i < bear_count; i++){
        float temp3 = 3 * base_cost;
        bank_balance = bank_balance - temp3;
    }

}

void Zoo::count_animals(int & baby_tiger_count, int & adult_tiger_count, int & baby_bear_count, int & adult_bear_count, int & baby_sealion_count, int & adult_sealion_count){
    int temp_baby = 0;
    int temp_adult = 0;
    for(int i = 0; i < tiger_count; i++){
        if(tigers[i].get_age() < 6){
            temp_baby = temp_baby + 1;
        }else if(tigers[i].get_age() >= 48){
            temp_adult = temp_adult + 1;
        }
    }
    baby_tiger_count = temp_baby; adult_tiger_count = temp_adult;
    temp_baby = 0; temp_adult = 0;
    for(int i = 0; i < bear_count; i++){
        if(bears[i].get_age() < 6){
            temp_baby = temp_baby + 1;
        }else if(bears[i].get_age() >= 48){
            temp_adult = temp_adult + 1;
        }
    }
    baby_bear_count = temp_baby; adult_bear_count = temp_adult;
    temp_baby = 0; temp_adult = 0;
    for(int i = 0; i < sea_lion_count; i++){
        if(sealions[i].get_age() < 6){
            temp_baby = temp_baby + 1;
        }else if(sealions[i].get_age() >= 48){
            temp_adult = temp_adult + 1;
        }
    }
    baby_sealion_count = temp_baby; adult_sealion_count = temp_adult;
}

void Zoo::turn_hub_function(){ //TODO// Code the special event function.
    cout << "Your current bank balance is: $" << bank_balance << endl;
    increment_ages();
    //Special event occurs
    special_event();
    //Monthy revenue
    compute_revenue();
    int baby_tiger_count, adult_tiger_count, baby_bear_count, adult_bear_count, baby_sealion_count, adult_sealion_count;
    count_animals(baby_tiger_count, adult_tiger_count, baby_bear_count, adult_bear_count, baby_sealion_count, adult_sealion_count);
    cout << "You currently have:" << endl << "\tTigers: " << endl << "\t\tBabies: " << baby_tiger_count << endl << "\t\tAdults: " << adult_tiger_count << endl;
    cout << endl << "\tBears: " << endl << "\t\tBabies: " << baby_bear_count << endl << "\t\tAdults: " << adult_bear_count << endl;
    cout << endl << "\tSea Lions: " << endl << "\t\tBabies: " << baby_sealion_count << endl << "\t\tAdults: " << adult_sealion_count << endl;
    //Purchase animals
    animal_purchase_choice();
    system("clear");
    //Pay for animal feeding
    compute_food_cost();
}

void Zoo::special_event(){
    srand(time(NULL));
    int event = rand() % 4;
    if(event == 0){
        sick();
    }
    else if(event == 1){
        birth();
    }
    else if(event == 2){
        cout << "There was a boom in attendence this month! Hope you bought some sea lions!" << endl;
        attendance_boom = true;
    }
    else if(event == 3){
        return;
    }
}

bool Zoo::is_loss(){
    if(bank_balance < 0){
        return true;
    }
    return false;
}

void Zoo::birth(){
    bool sealion_valid = true;
    bool tiger_valid = true;
    bool bear_valid = true;
    while(sealion_valid == true || tiger_valid == true || bear_valid == true){
        int mother = rand() % 3;
        if(mother == 0 && tiger_valid == true){
            for(int i = 0; i < tiger_count; i++){
                if(tigers[i].get_age() >= 48){
                    purchase_tiger(3, 0);
                    cout << "One of your tigers gave birth to three babies!" << endl; 
                    return;
                }
            }
            tiger_valid = false;
        }
        else if(mother == 1 && bear_valid == true){
            for(int i = 0; i < bear_count; i++){
                if(bears[i].get_age() >= 48){
                    purchase_bear(2, 0);
                    cout << "One of your bears gave birth to two babies!" << endl;
                    return;
                }
            }
            bear_valid = false;
        }
        else if(mother == 2 && sealion_valid == true){
            for(int i = 0; i < sea_lion_count; i++){
                if(sealions[i].get_age() >= 48){
                    purchase_sea_lion(1, 0);
                    cout << "One of your sea lions gave birth to a baby!" << endl;
                    return;
                }
            }
            sealion_valid = false;
        }
    }
}

void Zoo::sick_tiger(){
    int species2 = rand() % tiger_count;
    if(tigers[species2].get_age() < 6){
        if(bank_balance < 12000){
            cout << "Uh oh! You didn't have enough money to heal one of your baby tigers! They passed." << endl;
            kill_tiger(species2);
        }
        cout << "Uh oh! One of your baby tigers got sick! It cost $12000 to heal them." << endl;
        bank_balance = bank_balance - 12000;
        return;
    }else{
        if(bank_balance < 6000){
            cout << "Uh oh! You didn't have enough money to heal one of your tigers! They passed." << endl;
            kill_tiger(species2);
        }
        cout << "Uh oh! One of your tigers got sick! It cost $6000 to heal them." << endl;
        bank_balance = bank_balance - 6000;
        return;
    }
}

void Zoo::kill_tiger(int species2){
    Tiger * temp;
    temp = new Tiger[tiger_count - 1];
    for(int i = 0; i < species2; i++){
        temp[i].set_age(tigers[i].get_age());
    }
    for(int i = species2; i < tiger_count - 1; i++){
        temp[i].set_age(tigers[i + 1].get_age());
    }
    delete [] tigers;
    tigers = temp;
    tiger_count = tiger_count - 1;
}

void Zoo::sick_bear(){
    int species2 = rand() % bear_count;
    if(bears[species2].get_age() < 6){
        cout << "Uh oh! One of your baby bears got sick! It cost $5000 to heal them." << endl;
        bank_balance = bank_balance - 5000;
        return;
    }else{
        cout << "Uh oh! One of your bears got sick! It cost $2500 to heal them." << endl;
        bank_balance = bank_balance - 2500;
        return;
    }
}

void Zoo::kill_bear(int species2){
    Bear * temp;
    temp = new Bear[bear_count - 1];
    for(int i = 0; i < species2; i++){
        temp[i].set_age(bears[i].get_age());
    }
    for(int i = species2; i < bear_count - 1; i++){
        temp[i].set_age(bears[i + 1].get_age());
    }
    delete [] bears;
    bears = temp;
    bear_count = bear_count - 1;
}

void Zoo::sick_sealion(){
    int species2 = rand() % sea_lion_count;
    if(sealions[species2].get_age() < 6){
        cout << "Uh oh! One of your baby sea lions got sick! It cost $700 to heal them." << endl;
        bank_balance = bank_balance - 700;
        return;
    }else{
        cout << "Uh oh! One of your sea lions got sick! It cost $350 to heal them." << endl;
        bank_balance = bank_balance - 350;
        return;
    }
}

void Zoo::kill_sealion(int species2){
    SeaLion * temp;
    temp = new SeaLion[sea_lion_count - 1];
    for(int i = 0; i < species2; i++){
        temp[i].set_age(sealions[i].get_age());
    }
    for(int i = species2; i < sea_lion_count - 1; i++){
        temp[i].set_age(sealions[i + 1].get_age());
    }
    delete [] sealions;
    sealions = temp;
    sea_lion_count = sea_lion_count - 1;
}

bool Zoo::apply_sick(bool tiger_valid, bool bear_valid, bool sealion_valid){
    int species1 = rand() % 3;
    if(species1 == 0 && tiger_valid == true){
        sick_tiger();
        return true;
    }else if(species1 == 1 && bear_valid == true){
        sick_bear();
        return true;
    }else if(species1 == 2 && sealion_valid == true){
        sick_sealion();
        return true;
    }
    return false;
}

void Zoo::sick(){
    ////srand(time(NULL));
    bool tiger_valid = true; 
    bool bear_valid = true; 
    bool sealion_valid = true;
    bool complete = false;
    if(tiger_count == 0){
        tiger_valid = false;
    }if(bear_count == 0){
        bear_valid = false;
    }if(sea_lion_count == 0){
        sealion_valid = false;
    }
    while((tiger_valid == true || bear_valid == true || sealion_valid == true) && complete == false){
        complete = apply_sick(tiger_valid, bear_valid, sealion_valid);
    }
    return;
}

void Zoo::animal_purchase_choice(){
    string count;
    string purchase_choice;
    string species_choice;

    cout << "Would you like to purchase animals this turn? (yes or no)" << endl << "Choice: ";
    getline(cin, purchase_choice);
    while(purchase_choice != "yes" && purchase_choice != "no"){
        cout << "Invalid choice! Please input a 'yes' or a 'no'." << endl << "Choice: ";
        getline(cin, purchase_choice);
    }
    if(purchase_choice == "yes"){
        cout << "Which species of animal would you like to purchase (tiger, bear, or sea lion)?" << endl << "Choice: ";
        getline(cin, species_choice); //TODO Error handle this input.
        while(species_choice != "tiger" && species_choice != "bear" && species_choice != "sea lion"){
            cout << "Invalid choice! Please input one of the following options: 'tiger' 'bear' 'sea lion': ";
            getline(cin, species_choice);
        }
        cout << "How many would you like to buy? (1 or 2)" << endl << "Count: ";
        getline(cin, count); //TODO// Error handle this input.
        while(count != "1" && count != "2"){
            cout << "Invalid input, you must choose to buy only 1 or 2: ";
            getline(cin, count);
        }
        if(species_choice == "Tiger" || species_choice == "tiger"){
            purchase_tiger(stoi(count), 48);
        }else if(species_choice == "Sea Lion" || species_choice == "sea lion"){
            purchase_sea_lion(stoi(count), 48);
        }else if(species_choice == "Bear" || species_choice == "bear"){
            purchase_bear(stoi(count), 48);
        }
    }else if(purchase_choice == "no"){
        return;
    }
}

void Zoo::purchase_tiger(int count, int new_age){
    if(tiger_count == 0){
        tigers = new Tiger[count];
        for(int i = 0; i < count; i++){
            tigers[i].set_age(new_age);
        }
    }else{
        Tiger * temp;
        temp = new Tiger[tiger_count + count];
        for(int i = 0; i < tiger_count; i++){
            temp[i].set_age(tigers[i].get_age());
        }
        delete [] tigers;
        tigers = temp;
        for(int i = 0; i < count; i++){
            tigers[tiger_count + i].set_age(new_age);
        }
    }
    tiger_count = tiger_count + count;
    if(new_age == 48){
        bank_balance = bank_balance - 12000 * count;
    }
}

void Zoo::purchase_bear(int count, int new_age){
    if(bear_count == 0){
        bears = new Bear[count];
        for(int i = 0; i < count; i++){
            bears[i].set_age(new_age);
        }
    }else{
        Bear * temp;
        temp = new Bear[bear_count + count];
        for(int i = 0; i < bear_count; i++){
            temp[i].set_age(bears[i].get_age());
        }
        delete [] bears;
        bears = temp;
        for(int i = 0; i < count; i++){
            bears[bear_count + i].set_age(new_age);
        }
    }
    bear_count = bear_count + count;
    bank_balance = bank_balance - 5000 * count;
}

void Zoo::purchase_sea_lion(int count, int new_age){
    if(sea_lion_count == 0){
        sealions = new SeaLion[count];
        for(int i = 0; i < count; i++){
            sealions[i].set_age(new_age);
        }
    }else{
        SeaLion * temp;
        temp = new SeaLion[sea_lion_count + count];
        for(int i = 0; i < sea_lion_count; i++){
            temp[i].set_age(sealions[i].get_age());
        }
        delete [] sealions;
        sealions = temp;
        for(int i = 0; i < count; i++){
            sealions[sea_lion_count + i].set_age(new_age);
        }
    }
    sea_lion_count = sea_lion_count + count;
    bank_balance = bank_balance - 700 * count;
}

void Zoo::increment_ages(){
    for(int i = 0; i < tiger_count; i++){
        tigers[i].set_age(tigers[i].get_age() + 1);
    }
    for(int i = 0; i < sea_lion_count; i++){
        sealions[i].set_age(sealions[i].get_age() + 1);
    }
    for(int i = 0; i < bear_count; i++){
        bears[i].set_age(bears[i].get_age() + 1);
    }
}

int Zoo::get_tiger_count(){
    return tiger_count;
}

int Zoo::get_sea_lion_count(){
    return sea_lion_count;
}

int Zoo::get_bear_count(){
    return bear_count;
}

int Zoo::get_bank_balance(){
    return bank_balance;
}

void Zoo::set_bank_balance(int new_balance){
    bank_balance = new_balance;
}