#include "circle.h"
#include <iostream>

using namespace std;

Circle::Circle(float new_radius) : Shape("Circle", "Blue"){
    radius = new_radius;
}

float Circle::area(){
    return 3.1415 * radius * radius;
}

float Circle::get_radius(){
    return radius;
}