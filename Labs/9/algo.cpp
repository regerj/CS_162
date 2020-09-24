#include "algo.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int * construct_array(int length){
    srand(time(NULL));
    int * temp = new int [length];
    for(int i = 0; i < length; i++){
        temp[i] = rand() % 100 + 1;
    }
    return temp;
}

int error_handle(){
    int input;
    cout << "Please select a size of the array between 1 and 25: ";
    cin >> input;

    while(input < 1 || input > 25){
        cout << "Invalid size, please try a size between 1 and 25: ";
        cin >> input;
    }
    return input;
}

void print_array(int * arr, int size){
    cout << "Array: " << endl << endl;
    for(int i = 0; i < size; i++){
        cout << "\t" << arr[i];
    }
    cout << endl << endl;
}

int * copy_array(int * arr, int size){
    int * temp = new int [size];
    for(int i = 0; i < size; i++){
        temp[i] = arr[i];
    }
    return temp;
}

void merge(int * arr, int left_index, int middle, int right_index){ 
    int i, j, k; 
    int n1 = middle - left_index + 1; 
    int n2 =  right_index - middle; 
  
    int Left[n1], Right[n2]; 

    for(i = 0; i < n1; i++){
        Left[i] = arr[left_index + i]; 
    }
    for(j = 0; j < n2; j++){
        Right[j] = arr[middle + 1+ j];
    } 
  
    i = 0;
    j = 0;
    k = left_index;
    while(i < n1 && j < n2){ 
        if (Left[i] <= Right[j]){ 
            arr[k] = Left[i]; 
            i++; 
        }else{ 
            arr[k] = Right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while(i < n1){ 
        arr[k] = Left[i]; 
        i++; 
        k++; 
    } 
  
    while(j < n2){ 
        arr[k] = Right[j]; 
        j++; 
        k++; 
    } 
} 

void merge_sort(int * arr, int left_index, int right_index){ 
    if(left_index < right_index){ 
        int middle = left_index+(right_index-left_index)/2; 
        merge_sort(arr, left_index, middle); 
        merge_sort(arr, middle + 1, right_index); 
        merge(arr, left_index, middle, right_index); 
    } 
} 
