#ifndef BUDGET_BUDDY_H
#define BUDGET_BUDDY_H
#include <iostream>

using namespace std;

/******************************************************
** Program: budget_buddy.cpp
** Author: Jacob Reger
** Date: 01/13/2020
** Description: The following program will be capable
** logging in a user based on a user database file,
** providing that user with relevant account info, and
** then allowing the user to access their account info
** in one of many sorting formats, and have it output
** to the screen, or write onto a .txt file that they 
** can then use. 
** Input:
** Output:
******************************************************/


//!Structs listed below


/******************************************************
** Struct: user
** Purpose: A struct to contain all of the relevant
** account login information of a single user.
******************************************************/
struct user {
    string name;
    int id;
    string password;
};

/******************************************************
** Struct: budget
** Purpose: A struct to contain a user's budget info.
** It contains a nested transaction struct, see below.
******************************************************/

struct budget {
    int id;
    float balance;
    int num_transactions;
    struct transaction *t;
};

/******************************************************
** Struct: transaction
** Purpose: A struct to contain all of the relevant
** transaction information for each of possibly many
** seperate transactions. The category of the 
** transaction is limited to one of five categories:
** Housing, Food, Entertainment, Personal Care, and 
** Miscellaneous.
******************************************************/

struct transaction {
    float amount;
    string date;
    string category;
    string description;
};


//!Functions listed below

/******************************************************
 ** Function: check_argument_count
 ** Description: This function checks if the number of 
 ** arguments passed is equal to 3, and informs the 
 ** user if this is not the case before terminating.
 ** Parameters: int
 ** Pre-conditions: Take in an int for argc.
 ** Post-conditions: The parameters remain unchanged.
 *****************************************************/
void check_argument_count(int);

/******************************************************
 ** Function: post_login
 ** Description: Driver behind the code past login.
 ** Parameters: int, string, int &, int &
 ** Pre-conditions: Take in an int for the ID of the 
 ** user, a string for the name of the budget text, 
 ** an address for an int for the number of budgets,
 ** and an address for an int for the budget number.
 ** Post-conditions: Will assign a value to the two
 ** references.
 *****************************************************/

budget * post_login(int ID, string budget_file, int & budget_count, int & budget_num);

/******************************************************
 ** Function: delete_budgets
 ** Description: This function deletes the budget heap
 ** memory.
 ** Parameters: int, budget *
 ** Pre-conditions: Take in an int for the number of
 ** transactions, and a pointer to the budget struct
 ** array.
 ** Post-conditions: Delete the heap memory for the
 ** transactions and bugets.
 *****************************************************/

void delete_budgets(int count, budget * budgets);

/******************************************************
 ** Function: delete_users
 ** Description: This function deletes the user heap
 ** memory.
 ** Parameters: user *, int
 ** Pre-conditions: Take in a pointer to the user struct
 ** array and an int for the number of users.
 ** Post-conditions: Delete the heap memory that the
 ** pointer is pointing to.
 *****************************************************/

void delete_users(user * users, int user_count);

/******************************************************
 ** Function: write_to_file
 ** Description: This function will write the sorted
 ** transactions to the file the user specified.
 ** Parameters: budget *, int, int
 ** Pre-conditions: Takes in a pointer to the budget
 ** struct array, an int for the number of transacitons,
 ** and an int for the budget number.
 ** Post-conditions: The parameters are unchanged.
 *****************************************************/

void write_to_file(budget * budgets, int count, int budget_num);

/******************************************************
 ** Function: check_file_existence
 ** Description: This function will check for the
 ** existence of the files the user input into the
 ** command line and will inform the user if they find
 ** one to be invalid. It will then terminate the code.
 ** Parameters: string, string
 ** Pre-conditions: Take in the strings with the names
 ** of both of the files the user is attempting to use.
 ** Post-conditions: The parameters remain unchanged.
 *****************************************************/

void check_file_existence(string in_file_budget, string in_file_user);

/******************************************************
 ** Function: user_login
 ** Description: This function is the overall driver
 ** for the login portion of the program. It uses the
 ** other functions to log a user in and return the 
 ** ID number cooresponding to the user.
 ** Parameters: string
 ** Pre-conditions: Take in a string with the users.txt
 ** file in it.
 ** Post-conditions: The parameters remain unchanged.
 *****************************************************/
int user_login(string user_file);

/******************************************************
 ** Function: sorter_date
 ** Description: This function sorts the transactions
 ** in a budget by their date.
 ** Parameters: budget *, int, int
 ** Pre-conditions: Take in a pointer to the budget 
 ** struct array, an int for the number of transactions,
 ** and an int for the budget number.
 ** Post-conditions: The budget struct array will be 
 ** sorted according to date.
 *****************************************************/

void sorter_date (budget * budgets, int count, int budget_num);

/******************************************************
 ** Function: sorter_category
 ** Description: This function sorts the transactions
 ** in a budget by their category.
 ** Parameters: budget *, int, int
 ** Pre-conditions: Take in a pointer to the budget 
 ** struct array, an int for the number of transactions,
 ** and an int for the budget number.
 ** Post-conditions: The budget struct array will be 
 ** sorted according to category.
 *****************************************************/

void sorter_category (budget * budgets, int count, int budget_num);

/******************************************************
 ** Function: write_options
 ** Description: This function creates the interface
 ** for the user to choose how they wish the data to be
 ** written. 
 ** Parameters: budget *, int, int
 ** Pre-conditions: Take in a pointer to the budget 
 ** struct array, an int for the number of transactions,
 ** and an int for the budget number.
 ** Post-conditions: The parameters are not changed.
 *****************************************************/

void write_options(budget * budgets, int count, int budget_num);

/******************************************************
 ** Function: action_options
 ** Description: This function creates the interface
 ** where the user chooses how they wish to sort the
 ** data or if they wish to exit. It then redirects
 ** them where they need to go.
 ** Parameters: budget *, int, int, int
 ** Pre-conditions: Take in a pointer to the budget
 ** struct array, an int for the number of transactions,
 ** an int for the budget number to be sorted, and an
 ** int for the number of budgets present.
 ** Post-conditions: None of the parameters are changed
 ** by this function.
 *****************************************************/

void action_options(budget * budgets, int count, int budget_num, int budget_count);

/******************************************************
 ** Function: sorter_amount
 ** Description: A simple bubble sort algorithm that
 ** will sort the transactions from lowest to highest.
 ** Parameters: budget *, int, int
 ** Pre-conditions: Take in a pointer to the budget
 ** struct array, an int for the number of budgets, and
 ** an int for the budget number to be sorted.
 ** Post-conditions: The budget struct array will be 
 ** sorted according to the transaction amounts.
 *****************************************************/

void sorter_amount (budget * budgets, int count, int budget_num);

/******************************************************
 ** Function: get_user_budget
 ** Description: Simple function to cross reference the
 ** ID determined during login with the IDs found in
 ** the budgets.txt file, and return an integer based
 ** on which budget had the cooresponding ID.
 ** Parameters: int, budget *, int
 ** Pre-conditions: Take in an integer for the ID, a
 ** pointer to the budget struct array, and an integer
 ** that is the number of budgets present.
 ** Post-conditions: Parameters remain unchanged.
 *****************************************************/

int get_user_budget(int, budget *, int);

/******************************************************
 ** Function: is_int
 ** Description: Simple function to test if the
 ** parameter is a valid integer or not. Returns a bool
 ** based on its findings.
 ** Parameters: string
 ** Pre-conditions: Take in a string to be tested.
 ** Post-conditions: Parameters unchanged.
 *****************************************************/

bool is_int(string num);

/******************************************************
 ** Function: login_ID
 ** Description: Driving function for overall ID part
 ** of logging in. Greets the user and prompts them for
 ** an ID. Will only let them attempt to login 3 times
 ** before informing them and exiting. 
 ** Parameters: user *, int, int &
 ** Pre-conditions: Take in a pointer to the user struct
 ** array, an integer for the number of users, and 
 ** the address of the user number.
 ** Post-conditions: Change the user number to the
 ** correct cooresponding user number.
 *****************************************************/

int login_ID(user * users, int user_count, int & user_num);

/******************************************************
 ** Function: login_pass
 ** Description: Handles the user password check, and
 ** returns a boolean value to represent if it passed.
 ** Parameters: int, user *
 ** Pre-conditions: Take in an integer to represent 
 ** which user is attempting to login, as well as a
 ** pointer to the user struct array.
 ** Post-conditions: Parameters remain unchanged, just
 ** returns a boolean.
 *****************************************************/

bool login_pass(int user_num, user * users);

/******************************************************
 ** Function: valid_ID
 ** Description: Tests an ID for whether or not it
 ** matches an ID in the users.txt file. It will return 
 ** the ID number if it is correct, or it will return
 ** -1 if it does not match.
 ** Parameters: string, int, user *, int &
 ** Pre-conditions: Take in the ID, the number of users,
 ** a pointer to the user struct array, and the adress
 ** of an integer representing what account # in the
 ** list that the ID coorelated with.
 ** Post-conditions: Return either the ID or a -1 and
 ** change the user_num to the user number coorelated 
 ** to the valid ID.
 *****************************************************/

string valid_ID(string ID, int user_count, user * users, int & user_num);

/******************************************************
 ** Function: create_users
 ** Description: Dynamically allocates an array of user
 ** structs and returns a pointer to it.
 ** Parameters: int
 ** Pre-conditions: Take in an integer of how many
 ** users there are in the file.
 ** Post-conditions: The parameters remain unchanged.
 *****************************************************/

user * create_users(int);

/******************************************************
 ** Function: get_user_data
 ** Description: Populates the user struct array with
 ** the data from the file.
 ** Parameters: user *, int, ifstream &
 ** Pre-conditions: Take in a pointer to the array of
 ** user structs, an integer representing the number 
 ** of users, and the input file.
 ** Post-conditions: Populate the array of user structs
 ** while the other paramters remain unchanged.
 *****************************************************/

void get_user_data(user *, int, ifstream &);

/******************************************************
 ** Function: create_budgets
 ** Description: Dynamically allocates an array of 
 ** given size.
 TODO: Name parameters
 ** Parameters: int
 ** Pre-conditions: Take in the size of the array for
 ** the budgets.
 ** Post-conditions: Create the array and leave the 
 ** int unchanged.
 *****************************************************/

budget* create_budgets(int);

/******************************************************
 ** Function: get_budget_data
 ** Description: This function will fill a budget 
 ** struct with information that is read in from 
 ** budgets.txt.
 TODO: Name parameters
 ** Parameters: budget*, int, ifstream &
 ** Pre-conditions: Take in a pointer to a budget, an
 ** int for the number of budgets, and an input text
 ** file address.
 ** Post-conditions: Populate the budget array of 
 ** structs with the relevant information.
 *****************************************************/

void get_budget_data(budget*, int, ifstream &);

/******************************************************
 ** Function: create_transactions
 ** Description: This function will dynamically 
 ** allocate an array of transactions (of the 
 ** requested size).
 TODO: Name parameters
 ** Parameters: int
 ** Pre-conditions: Take in an int value for the number
 ** of transactions.
 ** Post-conditions: Create the transaction array of 
 ** given size, the int remains unchanged.
 *****************************************************/

transaction* create_transactions(int);

/******************************************************
 ** Function: get_transaction_data
 ** Description: This function will fill a transaction 
 ** struct with information that is read in from 
 ** budgets.txt.
 TODO: Name parameters
 ** Parameters: transaction*, int, ifstream&
 ** Pre-conditions: Take in a pointer to the array of
 ** transaction structs, and integer for the number of 
 ** transactions, and an address to an open input text
 ** file.
 ** Post-conditions: Populate the transaction array
 ** with the data grabbed from the file.
 *****************************************************/

void get_transaction_data(transaction*, int, ifstream &);

//TODO// write a delete function to free memory.
#endif