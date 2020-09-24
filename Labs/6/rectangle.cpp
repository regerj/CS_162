#include "rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(float new_height, float new_width) : Shape("Rectangle", "Red"){
    width = new_width;
    height = new_height;
}

float Rectangle::area(){
    return width * height;
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
