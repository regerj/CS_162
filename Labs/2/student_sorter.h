#include <iostream>
#include <cstdlib>

using namespace std;

struct student {
    int id;
    string first_name;
    string last_name;
};

student * create_student_db(int count); 

void get_student_db_info(student * students, int count, ifstream & file); 

void sorter (student * students, int count, ofstream & file);

void name_sorter (student* students, int count, ofstream & file);

void delete_student_db_info(student *);

//void delete_student_db_info (student **, int); 