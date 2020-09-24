#include "node.h"
#include "linked_list.h"

using namespace std;

//TODO Error handle the value inputs

int main() {

    Linked_List L1;
    //L1.push_front(1);
    //L1.insert(2, 1);
    L1.print();
    //L1.choose_order();
    L1.print();
    L1.prime_number_find();
    L1.clear();

    return 0;
}