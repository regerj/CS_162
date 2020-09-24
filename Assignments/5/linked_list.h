#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdlib>
#include "node.h"

using namespace std;

class Linked_List {
    private:
        unsigned int length = 0;
        Node * head = NULL;
    public:
        Linked_List(); //TODO// Code constructor
        int get_length(); //TODO// Code accessor
        void print(); //TODO// Code print
        void clear(); //TODO// Code clear
        Node * get_node(int); //TODO// Code get_node
        unsigned int push_front(int); //TODO// Code push_front
        unsigned int push_back(int); //TODO// Code push_back
        unsigned int insert(int, unsigned int); //TODO// Code insert
        void sort_ascending(); //TODO// Code sort_ascending
        void sort_descending(); //TODO// Code sort_descending
        void merge(bool, int, int, int);
        void merge_sort(bool, int, int);
        void prime_number_find();
        void choose_order();
};

#endif