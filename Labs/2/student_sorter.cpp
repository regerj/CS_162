#include <iostream>
#include <fstream>
#include <cstdlib>
#include "student_sorter.h"

using namespace std;

student * create_student_db(int count){
    student * students = new student [count];
    return students;
}

void get_student_db_info (student * students, int count, ifstream & file) {
    int id;
    string major;
    for(int i = 0; i < count; i++){
        file >> students[i].id >> students[i].first_name >> students[i].last_name >> major;
    }
}

void sorter (student * students, int count, ofstream & file) {
    for(int i = 0; i < count - 1; i++){
        for(int j = 0; j < count - 1 - i; j++){
            if(students[j].id > students[j+1].id){
                swap(students[j], students[j+1]);
            }
        }
    }

    file << endl << endl << "SORTED BY ID NUMBER" << endl << endl;

    for(int i = 0; i < count; i++){
        file << students[i].id << " " << students[i].first_name << " " << students[i].last_name << endl;
    }
    
}

void name_sorter (student* students, int count, ofstream & file) {
    for(int i = 0; i < count - 1; i++){
        for(int j = 0; j < count - 1 - i; j++){
            if(students[j].last_name > students[j+1].last_name){
                swap(students[j], students[j+1]);
            }
        }
    }

    file << endl << "SORTED BY LAST NAME" << endl << endl;

    for(int i = 0; i < count; i++){
        file << students[i].id << " " << students[i].first_name << " " << students[i].last_name << endl;
    }
}

void delete_student_db_info(student * students){
    delete[] students;
}
