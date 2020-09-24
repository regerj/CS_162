#include <iostream>
#include <fstream>
#include <cstdlib>
#include "student_sorter.h"

using namespace std;

int main(){
    ifstream in_file_student;
    in_file_student.open("input.txt");
    int count;
    in_file_student >> count;
    student * students = create_student_db(count);
    get_student_db_info(students, count, in_file_student);
    in_file_student.close();
    ofstream out_file_student;
    out_file_student.open("output.txt");
    sorter(students, count, out_file_student);
    name_sorter(students, count, out_file_student);
    delete_student_db_info(students);
    out_file_student.close();

}



