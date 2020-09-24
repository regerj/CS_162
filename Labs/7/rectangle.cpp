#include "rectangle.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Rectangle::Rectangle(float new_height, float new_width) : Shape("Rectangle", "Red"){
    width = new_width;
    height = new_height;
    if(area() == 0){
        throw domain_error("Invalid constructor argument");
    }
}

float Rectangle::area(){
    return width * height;
}

void Rectangle::print_shape_info(){
    cout << endl << "Testing rectangle object attributes." << endl;
    cout << endl << "\tExpected: \tActual:" << endl;
    cout << "\tName: Rectangle\tName: " << get_name() << endl;
    cout << "\tColour: Red \tColour: " << get_colour() << endl;
    cout << "\tHeigth: 2 \tHeigth: " << get_height() << endl;
    cout << "\tWidth: 3 \tWidth: " << get_width() << endl;
    cout << "\tArea: 6 \tArea: " << area() << endl;
}

float Rectangle::get_width(){
    return width;
}

float Rectangle::get_height(){
    return height;
}

void Rectangle::set_width(float new_width){
    width = new_width;
}

void Rectangle::set_height(float new_height){
    height = new_height;
}

bool Rectangle::operator>(Rectangle & r2){
    return area() > r2.area();
}

bool Rectangle::operator<(Rectangle & r2){
    return area() < r2.area();
}
