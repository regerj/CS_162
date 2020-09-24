#include "linked_list.h"
#include "node.h"
#include <iostream>

using namespace std;

Linked_List::Linked_List(){
    bool another = true;
    string temp;
    cout << "Please enter a number: ";
    getline(cin, temp);
    head = new Node;
    head->val = stoi(temp);
    length = 1;
    cout << "Do you want to enter another number (y or n): ";
    getline(cin, temp);
    while(temp != "y" && temp != "n"){
        cout << "Invalid choice! Please enter a 'y' or an 'n': ";
        getline(cin, temp);
    }
    if(temp == "n"){
        another = false;
    }
    while(another == true){
        cout << "Please enter a number: ";
        getline(cin, temp);
        push_back(stoi(temp));
        cout << "Do you want to enter another number (y or n): ";
        getline(cin, temp);
        while(temp != "y" && temp != "n"){
            cout << "Invalid choice! Please enter a 'y' or an 'n': ";
            getline(cin, temp);
        }
        if(temp == "n"){
            another = false;
        }
    }
}

void Linked_List::prime_number_find(){
    cout << "Your program contains the following prime numbers:" << endl;
    bool temp;
    Node * active = head;
    for(int i = 0; i < length; i++){
       	temp = true;
    	for(int j = 2; j < active->val; j++){
	        if(active->val % j == 0){
	            temp = false;
	        }
	    }
	    if(temp == true){
	        cout << "\tPrime number: " << active->val << endl;
	    }
        active = active->next;
    }
}

int Linked_List::get_length(){
    return length;
}

void Linked_List::clear(){
    Node * temp1 = head->next;
    Node * temp2 = NULL;
    delete head;
    for(int i = 0; i < length - 1; i++){
        temp2 = temp1->next;
        delete temp1;
        temp1 = temp2;
    }
    length = 0;
}

void Linked_List::print(){
    Node * active = NULL;
    for(int i = 0; i < length; i++){
        active = get_node(i);
        cout << active->val << "   ";
    }
    cout << endl;
}

Node * Linked_List::get_node(int index){
    Node * temp;
    temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp;
}

void Linked_List::choose_order(){
    string temp;
    cout << "Sort ascending or descending (a or d): ";
    getline(cin, temp);
    while(temp != "a" && temp != "d"){
        cout << "Invalid choice, please select 'a' to sort in ascending order and 'd' to sort in descending: ";
        getline(cin, temp);
    }
    if(temp == "a"){
        sort_ascending();
    }else{
        sort_descending();
    }
}

unsigned int Linked_List::push_back(int new_value){
    Node * end = get_node(length - 1);
    end->next = new Node;
    end->next->val = new_value;
    length = length + 1;
    return 0;
}

unsigned int Linked_List::push_front(int value){
    Node * temp = head;
    head = new Node;
    head->val = value;
    head->next = temp;
    length = length + 1;
}

unsigned int Linked_List::insert(int value, unsigned int index){
    Node * temp1 = new Node;
    temp1->val = value;
    Node * temp2 = get_node(index - 1);
    Node * temp3 = temp2->next;
    temp2->next = temp1;
    temp1->next = temp3;
    length = length + 1;
}

void Linked_List::merge(bool descending, int left_index, int middle, int right_index){
    int i, j, k; 
    int n1 = middle - left_index + 1; 
    int n2 =  right_index - middle; 
    Node * Left = new Node;
    Node * Right = new Node;
    Node * iterator1 = Left;
    Node * active = get_node(left_index);
    for(i = 0; i < n1; i++){
        iterator1->val = active->val;
        iterator1->next = new Node;
        iterator1 = iterator1->next;
        active = active->next; 
    }
    active = get_node(middle + 1);
    iterator1 = Right;
    for(j = 0; j < n2; j++){
        iterator1->val = active->val;
        iterator1->next = new Node;
        iterator1 = iterator1->next;
        active = active->next;
    } 
    i = 0;
    j = 0;
    k = left_index;
    active = get_node(k);
    iterator1 = Left;
    Node * iterator2 = Right;
    while(i < n1 && j < n2){ 
        if(descending == true){
            if(iterator1->val >= iterator2->val){ 
                active->val = iterator1->val; 
                i++; 
                iterator1 = iterator1->next;
            }else{ 
                active->val = iterator2->val;
                j++; 
                iterator2 = iterator2->next;
            } 
            k++; 
            active = active->next;
        }else if(descending == false){
            if(iterator1->val <= iterator2->val){ 
                active->val = iterator1->val; 
                i++; 
                iterator1 = iterator1->next;
            }else{ 
                active->val = iterator2->val;
                j++; 
                iterator2 = iterator2->next;
            } 
            k++; 
            active = active->next;
        }
    } 
    while(i < n1){ 
        active->val = iterator1->val; 
        i++; 
        iterator1 = iterator1->next;
        k++;
        active = active->next;
    } 
    while(j < n2){ 
        active->val = iterator2->val; 
        j++; 
        iterator2 = iterator2->next;
        k++; 
        active = active->next;
    }
    Node * temp;
    while(Left->next != NULL){
        temp = Left->next;
        delete Left;
        Left = temp;
    }
    while(Right->next != NULL){
        temp = Right->next;
        delete Right;
        Right = temp;
    }
    
}

void Linked_List::merge_sort(bool descending, int left_index, int right_index){
    if(left_index < right_index){
        int middle = left_index + (right_index - left_index) / 2;
        merge_sort(descending, left_index, middle);
        merge_sort(descending, middle + 1, right_index);
        merge(descending, left_index, middle, right_index);
    }
}

void Linked_List::sort_ascending(){
    merge_sort(false, 0, length - 1);
}

void Linked_List::sort_descending(){
    merge_sort(true, 0, length - 1);
}