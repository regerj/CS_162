#include "implementation.h"
#include <string>

using namespace std;

void error_handle_cmd_line(string & size, string & debug){
    while(is_int(size) == false || stoi(size) < 4){
        cout << "Invalid size, please input a positive integer greater than 4 for the length of the sides of the cave: ";
        getline(cin, size);
    }

    while(debug != "true" && debug != "false"){
        cout << "Invalid debug mode setting. Please input either 'true' or 'false' for debug mode: ";
        getline(cin, debug);
    }
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