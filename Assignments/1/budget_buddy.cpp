#include <fstream>
#include "budget_buddy.h"

using namespace std;

void check_argument_count(int count){
    if(count != 3){
        cout << endl << "Invalid number of arguments. Please try again with only 3 arguments!" << endl << endl;
        exit(0);
    }
}

void check_file_existence(string in_file_budget, string in_file_user){
    ifstream in_file_users(in_file_user);
    if(!in_file_users.is_open()){
        cout << endl << "The user file you have provided does not exist. Please check your file name and that it exists in the folder, and try again!" << endl << endl;
        in_file_users.close();
        exit(0);
    }
    in_file_users.close();
    ifstream in_file_budgets(in_file_budget);
    if(!in_file_budgets.is_open()){
        cout << endl << "The budget file you have provided does not exist. Please chekc your file name and that it exists in the folder, and try again!" << endl << endl;
        in_file_budgets.close();
        exit(0);
    }
    in_file_budgets.close();

}

int user_login(string user_file){
    ifstream in_file_users;
    in_file_users.open(user_file);
    int user_count;
    int ID;
    int user_num = 0;
    in_file_users >> user_count;
    user * users = create_users(user_count);
    get_user_data(users, user_count, in_file_users);
    ID = login_ID(users, user_count, user_num);

    //!// RESOLVED USER NUM NOT STORING CORRECTLY, ONLY STORES 0;

    //cout << "user_num: " << user_num << endl;
    if(login_pass(user_num, users) == false){
        exit(0);
    }
    cout << "Account Name: " << users[user_num].name << endl;
    cout << "ID: " << ID << endl;
    in_file_users.close();
    delete_users(users, user_count);
    
    return ID;
}

budget * post_login(int ID, string budget_file, int & budget_count, int & budget_num){
    ifstream in_file_budgets;
    in_file_budgets.open(budget_file);
    //int budget_count;
    in_file_budgets >> budget_count;
    budget * budgets = create_budgets(budget_count);
    get_budget_data(budgets, budget_count, in_file_budgets);
    budget_num = get_user_budget(ID, budgets, budget_count);
    in_file_budgets.close();
    return budgets;
}

user * create_users(int count){
    user * users = new user [count];
    return users;
}

void delete_users(user * users, int user_count){
    delete[] users;
}

void get_user_data(user * users, int count, ifstream & in_file_users){
    for(int i = 0; i < count; i++){
        in_file_users >> users[i].name >> users[i].id >> users[i].password;
    }
}

budget* create_budgets(int count){
    budget * budgets = new budget [count];
    return budgets;
}

void delete_budgets(int count, budget * budgets){
    for(int i = 0; i < count; i++){
        delete[] budgets[i].t;
    }
    delete[] budgets;
}

//TODO// Make this function call the transaction fucntions so that the budget data
//TODO// will store correctly!
void get_budget_data(budget* budgets, int count, ifstream & in_file_budgets){
    for(int i = 0; i < count; i++){
        in_file_budgets >> budgets[i].id >> budgets[i].balance >> budgets[i].num_transactions;
        budgets[i].t = create_transactions(budgets[i].num_transactions);
        get_transaction_data(budgets[i].t, budgets[i].num_transactions, in_file_budgets);
        ////Just for testing!
        ////cout << budgets[i].id;
    }
}

transaction* create_transactions(int count){
    transaction * transactions = new transaction [count];
    return transactions;
}

void get_transaction_data(transaction* transactions, int num_transactions, ifstream & in_file_budgets){
    for(int i = 0; i < num_transactions; i++){
        in_file_budgets >> transactions[i].date >> transactions[i].amount >> transactions[i].description >> transactions[i].category;
        ////This is just test!
        ////cout << transactions[i].date << " " << transactions[i].amount << " " << transactions[i].description << " " << transactions[i].category << endl;
    }
}

//TODO// Add this function to the header file!
int login_ID(user * users, int user_count, int & user_num){
    string ID;
    int count = 1;
    cout << endl << "Hello welcome to Budget Buddy!" << endl << endl;
    do{
        cout << "Please enter an ID to login: ";
        getline(cin, ID);
        if(is_int(ID) == true){
            ////valid_ID(ID, user_count, users);
            if(stoi(valid_ID(ID,user_count, users, user_num)) == -1){
                cout << endl << "Invalid ID, please try again!" << endl << endl;
                count = count + 1;
            }else{
                return stoi(ID);
            }
        }else{
            cout << endl << "Invalid ID, please try again!" << endl << endl;
            count = count + 1;
        }
    }while (count < 4);
    cout << "Too many attempts! The program will quit now." << endl;
    exit(0);
    ////return -1; //This is to tell the main that there were too many attempts so it can quit!
}

//TODO// Add this function to the header file!
string valid_ID(string ID, int user_count, user * users, int & user_num){ 
    
    for(int i = 0; i < user_count; i++){
        //cout << "Validating ID: " << ID << " against " << users[i].id << endl;
        if(stoi(ID) == users[i].id){
            user_num = i;
            return ID;
        }
    }
    return "-1";
}

//TODO// Add this function to the header file!
bool login_pass(int user_num, user * users){
    string password;
    int count = 1;
    do{
        cout << "Please enter your password: ";
        getline(cin, password);
        if(password == users[user_num].password){
            cout << "Login Successful!" << endl;
            return true; //Telling the main that the user logged in successfully!
        }
        cout << "Wrong password!" << endl;
        count = count + 1;
    }while (count < 4);
    cout << "Too many attempts! The program will quit now." << endl;
    return false; //Telling the main that the user did not log in and that it needs to quit!
}

bool is_int(string num){
    if(num.at(0) != 45 && (num.at(0) > 57 || num.at(0) < 48))
        return 0;
    for(int i = 1; i < num.length(); i++){
        if(num.at(i) > 57 || num.at(i) < 48){
	        return 0;
        }
    }
    return 1; 
}

int get_user_budget(int ID, budget * budgets, int budget_count){
    for(int i = 0; i < budget_count; i++){
        if(ID == budgets[i].id){
            return i;
        }
    }
}

//TODO// Rework to fit use case!
void sorter_amount (budget * budgets, int count, int budget_num) {
    for(int i = 0; i < count - 1; i++){
        for(int j = 0; j < count - 1 - i; j++){
            if(budgets[budget_num].t[j].amount > budgets[budget_num].t[j + 1].amount){
                swap(budgets[budget_num].t[j], budgets[budget_num].t[j + 1]);
            }
        }
    }
}

void sorter_category (budget * budgets, int count, int budget_num) {
    ////int temp1, temp2;
    for(int i = 0; i < count - 1; i++){
        for(int j = 0; j < count - 1 - i; j++){
            if(budgets[budget_num].t[j].category[0] > budgets[budget_num].t[j + 1].category[0]){
                swap(budgets[budget_num].t[j], budgets[budget_num].t[j + 1]);
            }
        }
    }
}

void sorter_date (budget * budgets, int count, int budget_num){
    for(int i = 0; i < count - 1; i++){
        for(int j = 0; j < count - 1 - i; j++){
            if(budgets[budget_num].t[j].date.substr(6,4) > budgets[budget_num].t[j + 1].date.substr(6,4)){
                swap(budgets[budget_num].t[j], budgets[budget_num].t[j + 1]);
            }
            else if(budgets[budget_num].t[j].date.substr(6,4) == budgets[budget_num].t[j + 1].date.substr(6,4)){
                if(budgets[budget_num].t[j].date.substr(0,2) > budgets[budget_num].t[j + 1].date.substr(0,2)){
                    swap(budgets[budget_num].t[j], budgets[budget_num].t[j + 1]);
                }
                else if(budgets[budget_num].t[j].date.substr(0,2) == budgets[budget_num].t[j + 1].date.substr(0,2)){
                    if(budgets[budget_num].t[j].date.substr(3,2) > budgets[budget_num].t[j + 1].date.substr(3,2)){
                        swap(budgets[budget_num].t[j], budgets[budget_num].t[j + 1]);
                    }
                }
            }
        }
    }
}

//TODO// Finish this action_options
void action_options(budget * budgets, int count, int budget_num, int budget_count){
    string choice1;
    bool pass = false;
    cout << "What would you like to do? " << endl;
    cout << "\t 1. Sort transactions by category." << endl;
    cout << "\t 2. Sort transactions by date." << endl;
    cout << "\t 3. Sort transactions by dollar amount." << endl;
    cout << "\t 4. Quit." << endl << endl << "Choice: ";
    getline(cin, choice1);

    do{
        //cout << "Entered do while loop to test sort choice." << endl;
        if(choice1 == "1"){
            sorter_category(budgets, count, budget_num);
            pass = true;
        }
        else if(choice1 == "2"){
            sorter_date(budgets, count, budget_num);
            pass = true;
        }
        else if(choice1 == "3"){
            sorter_amount(budgets, count, budget_num);
            pass = true;
        }
        else if(choice1 == "4"){
            delete_budgets(budget_count, budgets);
            exit(0);
        }
        else if (choice1 != "1" && choice1 != "2" && choice1 != "3" && choice1 != "4"){
            cout << "Invalid input! Please try again: ";
            getline(cin, choice1);
        }
    }while(pass == false);
}

void write_options(budget * budgets, int count, int budget_num){
    string choice2;
    bool pass2 = false;
    cout << endl << "How would you like the sorted data output?" << endl;
    cout << "\t 1. Display on screen." << endl;
    cout << "\t 2. Write to a text file." << endl << endl << "Choice: ";
    getline(cin, choice2);
    do{
        if(choice2 == "1"){
            cout << endl;
            for(int i = 0; i < budgets[budget_num].num_transactions; i++){
                cout << "Transaction #" << i + 1 << ":" << endl;
                cout << "\t Amount: $" << budgets[budget_num].t[i].amount << endl;
                cout << "\t Date: " << budgets[budget_num].t[i].date << endl;
                cout << "\t Category: " << budgets[budget_num].t[i].category << endl;
                cout << "\t Description: " << budgets[budget_num].t[i].description << endl << endl;
            }
            pass2 = true;
        }
        if(choice2 == "2"){
            write_to_file(budgets, count, budget_num);
            pass2 = true;
        }
        else if(choice2 != "1" && choice2 != "2"){
            cout << "Invalid input! Please try again: ";
            getline(cin, choice2);
            //cin.ignore();
        }
    } while (pass2 == false);
}

void write_to_file(budget * budgets, int count, int budget_num){
    string file_name;
    cout << endl << "Please enter a file name including the file extension (.txt) that you want your sorted transactions to be output to: ";
    getline(cin, file_name);
    cout << endl;
    ofstream out_file(file_name, fstream::trunc);
    for(int i = 0; i < budgets[budget_num].num_transactions; i++){
        out_file << "Transaction #" << i + 1 << endl;
        out_file << "\t Amount: $" << budgets[budget_num].t[i].amount << endl;
        out_file << "\t Date: " << budgets[budget_num].t[i].date << endl;
        out_file << "\t Category: " << budgets[budget_num].t[i].category << endl;
        out_file << "\t Description: " << budgets[budget_num].t[i].description << endl << endl;
    }
    cout << "File write successful!" << endl << endl;
    out_file.close();
}