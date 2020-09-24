#include "shape.h"
#include <iostream>

using namespace std;

Shape::Shape(string new_name, string new_colour){
    ////cout << "Creating shape object for part 1." << endl;
    ////cout << "\tSetting shape object name to be: Shape." << endl;
    ////cout << "\tSetting shape object colour to be: Green." << endl;
    name = new_name;
    colour = new_colour;
}

string Shape::get_name(){
    return name;
}

string Shape::get_colour(){
    return colour;
}

void Shape::set_name(string new_name){
    name = new_name;
}

void Shape::set_colour(string new_colour){
    colour = new_colour;
}
