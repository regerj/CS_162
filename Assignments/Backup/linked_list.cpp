#include "linked_list.h"
#include "node.h"
#include <iostream>

using namespace std;

Linked_List::Linked_List(){
    bool another = true;
    string temp;
    cout << "Please enter a number: ";
    getline(cin, temp);
    while(is_int(temp) == false){
        cout << "Invalid integer, please enter a valid integer: ";
        getline(cin, temp);
    }
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
        while(is_int(temp) == false){
            cout << "Invalid integer, please enter a valid integer: ";
            getline(cin, temp);
        }
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

bool Linked_List::is_int(string num){
    if(num.at(0) != 45 && (num.at(0) > 57 || num.at(0) < 48))
        return 0;
    for(int i = 1; i < num.length(); i++){
        if(num.at(i) > 57 || num.at(i) < 48){
            return 0;
        }
    }
    return 1; 
}

bool Linked_List::again(){
    string temp;
    cout << "Would you like to do this again (yes or no): ";
    getline(cin, temp);
    while(temp != "yes" && temp != "no"){
        cout << "Invalid choice! Please enter either 'yes' or 'no' to do this again: ";
        getline(cin, temp);
    }
    if(temp == "yes"){
        return true;
    }else{
        return false;
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
    head = get_node(0);
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

Node * Linked_List::merge(Node * Left, Node * Right, bool descending){
    Node * temp1 = NULL;
    if(Left == NULL){
        return Right;
    }else if(Right == NULL){
        return Left;
    }
    if(descending == false){
        if(Left->val <= Right->val){
            temp1 = Left;
            temp1->next = merge(Left->next, Right, descending);
        }else{
            temp1 = Right;
            temp1->next = merge(Left, Right->next, descending);
        }
    }else if(descending == true){
        if(Left->val >= Right->val){
            temp1 = Left;
            temp1->next = merge(Left->next, Right, descending);
        }else{
            temp1 = Right;
            temp1->next = merge(Left, Right->next, descending);
        }
    }
    
    return temp1;
}

void Linked_List::merge_sort(Node ** head_temp, bool descending){
    Node * temp1 = *head_temp;
    Node * Left;
    Node * Right;
    if((temp1 == NULL) || (temp1->next == NULL)){
        return;
    }
    split_linked_list(temp1, &Left, &Right);
    merge_sort(&Left, descending);
    merge_sort(&Right, descending);
    *head_temp = merge(Left, Right, descending);
}

void Linked_List::split_linked_list(Node * head_temp, Node ** Left_Head, Node ** Right_Head){
    *Left_Head = head_temp;
    Node * ptr1, * ptr2;
    ptr1 = head_temp;
    ptr2 = head_temp->next;
    while(ptr2 != NULL){
        ptr2 = ptr2->next;
        if(ptr2 != NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    *Right_Head = ptr1->next;
    ptr1->next = NULL;
}

void Linked_List::sort_ascending(){
    Node * temp = get_node(0);
    merge_sort(&temp, false);
    head = temp;
}

void Linked_List::sort_descending(){
    Node * temp = get_node(0);
    merge_sort(&temp, true);
    head = temp;
}