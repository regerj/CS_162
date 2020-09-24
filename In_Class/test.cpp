#include <iostream>
#include <algorithm>
#include <list>
#include <numeric>

using namespace std;

int main(){
   list<int> li(6);
   iota(li.begin(), li.end(), 0);

   // Find the value 3 in the list

   auto it{
      find(li.begin(), li.end(), 3)
   };

   // Insert 8 right before 3

   li.insert(it, 8);

   for(int i : li) // For each loop with iterators
      cout << i << ' ';
   cout << endl;
}