#include <iomanip>
#include "budget_buddy.h"

using namespace std;

int main(int argc, char * argv[]){
    //!// Try using ios::.good() to test existence of files!

    //!// Change code to not import the transaction data for all budgets, only import transaction data for user logged in!

    //TODO// Modularize driver
    //TODO// Test existence of files, probably write a function for it, use isopen?
    //TODO// Put everthing in a while loop
    //TODO// Finish writing function for writing to output file
    //TODO// Error handle output choice function
    //TODO// Finish function headers
    //TODO// Write delete functions
    //TODO// Remember to close files
    //TODO// Clean up include statements
    //TODO// Header guard
    //TODO Check over rubric
    check_argument_count(argc);
    
    check_file_existence(argv[2], argv[1]);
    int ID = user_login(argv[1]);
    int budget_count, budget_num;
    do{
        budget * budgets = post_login(ID, argv[2], budget_count, budget_num);
        cout << fixed << setprecision(2) << "Current Balance: " << budgets[budget_num].balance << endl << endl; 
        action_options(budgets, budgets[budget_num].num_transactions, budget_num, budget_count);
        write_options(budgets, budgets[budget_num].num_transactions, budget_num);
        ////sorter_amount(budgets, budgets[budget_num].num_transactions, budget_num);
        delete_budgets(budget_count, budgets);
    } while (1);
    return 0;
}