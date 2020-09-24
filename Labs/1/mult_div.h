#include <iostream>
#include <cstdlib>

struct mult_div_table{
   int product;
   float dividend;
};

void check(int * rows, int * cols);
mult_div_table** create_table(int rows, int cols);
void populate_table(mult_div_table** table, int rows, int cols);
void print_table(mult_div_table** table, int rows, int cols);
void delete_table(mult_div_table** table, int rows, int cols);