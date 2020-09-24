#ifndef NODE_H
#define NODE_H

#include <cstdlib>

using namespace std;

/******************************************************
** Class: Node
** Purpose: A class to hold an integer value as the 
** data type as well as a pointer to the next member of 
** a linked list. This is a simple struct style class 
** to store the relevant information for a single node
** within a linked list.
******************************************************/

class Node {
    public:
        int val;
        Node * next = NULL;
};
#endif