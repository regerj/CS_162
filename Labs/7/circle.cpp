#include "circle.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Circle::Circle(float new_radius) : Shape("Circle", "Blue"){
    radius = new_radius;
    if(area() == 0){
        throw invalid_argument("Invalid constructor argument");
    }
}

float Circle::area(){
    return 3.1415 * radius * radius;
}

void Circle::print_shape_info(){
    cout << endl << "Testing circle object attributes." << endl;
    cout << endl << "\tExpected: \tActual:" << endl;
    cout << "\tName: Circle\tName: " << get_name() << endl;
    cout << "\tColour: Blue \tColour: " << get_colour() << endl;
    cout << "\tRadius: 2 \tRadius: " << radius << endl;
    cout << "\tArea: 12.566 \tArea: " << area() << endl;
}

float Circle::get_radius(){
    return radius;
}