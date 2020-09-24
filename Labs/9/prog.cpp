#include "algo.h"
#include <iostream>

using namespace std;

int main(){
    int input = error_handle();
    int * original_array = construct_array(input);
    print_array(original_array, input);
    int * new_array = copy_array(original_array, input);
    merge_sort(new_array, 0, input - 1);
    cout << endl << endl << "Sorted your array." << endl << endl;
    print_array(new_array, input);

    cout << "Your program contains the following prime numbers:" << endl;
    bool temp;
    for(int i = 0; i < input; i++){
       	temp = true;
    	for(int j = 2; j < new_array[i]; j++){
	   if(new_array[i] % j == 0){
	      temp = false;
	   }
	}
	if(temp == true){
	   cout << "\tPrime number: " << new_array[i] << endl;
	}
    }
    delete [] original_array;
    delete [] new_array;
    return 0;
}
