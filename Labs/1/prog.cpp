#include "mult_div.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){

   int rows;
   int cols;
   if (argc == 3){
      rows = atoi(argv[1]);
      cols = atoi(argv[2]);
      check(&rows, &cols);
   }else{
      cout << "Invalid number of arguments, please try again." << endl;
      cout << "Rows: ";
      cin >> rows;
      cout << "Cols: ";
      cin >> cols;
   }
   struct mult_div_table** table;
   table = create_table(rows, cols);
   populate_table(table, rows, cols);
   print_table(table, rows, cols);
   delete_table(table, rows, cols);
   return 0;
}
