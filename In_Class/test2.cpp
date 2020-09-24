#include <iostream>

using namespace std;

class Pet {
public:
   virtual void print();
   string name;
};

void Pet::print(){
   cout << "My name is " << name;
}

class Dog : public Pet {
public:
   void print();
   string breed;
};

void Dog::print(){
   Pet::print();
   cout << ", and my breed is a " << breed << endl;
}

int main(){
    Pet pPtr;
    Dog dPtr;
    dPtr.name = "Rover";
    dPtr.breed = "Weiner";
    pPtr = dPtr;
    pPtr.print();
}