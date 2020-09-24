#include <iostream>
#include <cstdlib>
#include "mult_div.h"

using namespace std;

void check(int * rows, int * cols){
   bool pass1 = false;
   bool pass2 = false;

   do{
      if(*rows < 1){
	 cout << "Invalid row value, please input again: ";
	 cin >> *rows;
      }
      if(*rows > 0)
	 pass1 = true;
   }while(pass1 == false);
   do{
      if(*cols < 1){
         cout << "Invalid column value, please input again: ";
         cin >> *cols;
      }else if(*cols > 0){
         pass2 = true;
      }
   }while(pass2 == false);
}

void print_table(mult_div_table** table, int rows, int cols){
   for(int i = 0; i < cols; i++){
      for(int j = 0; j < rows; j++){
      
	 cout << table[i][j].product << "  ";
      }
      cout << endl;
   }
   cout << endl;
   cout << endl;
   for(int i = 0; i < cols; i++){
      for(int j = 0; j < rows; j++){
      
	 cout << "  " << table[i][j].dividend;
      }
      cout << endl;
   }


}

void populate_table(mult_div_table** table, int rows, int cols){

   for(int i = 1; i <= rows; i++)
      for(int j = 1; j <= cols; j++){    
	 table[i-1][j-1].product = i * j;
	 table[i-1][j-1].dividend = float(i) / float(j);
      }
}

void delete_table(mult_div_table** table, int rows, int cols){

   for(int i = 0; i < rows; i++)
      delete table[i];
   delete table;

}

struct mult_div_table** create_table(int rows, int cols){

   struct mult_div_table** table;
   table = new struct mult_div_table* [rows];
   for(int i = 0; i < rows; i++)
      table[i] = new struct mult_div_table[cols];
   return table;
}
