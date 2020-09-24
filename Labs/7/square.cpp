#include "square.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Square::Square(float side) : Rectangle(side, side){
    set_name("Square");
    set_colour("Purple");
    if(area() == 0){
        throw invalid_argument("Invalid constructor argument");
    }
}

void Square::print_shape_info(){
    cout << endl << "Testing square object attributes." << endl;
    cout << endl << "\tExpected: \tActual:" << endl;
    cout << "\tName: Square\tName: " << get_name() << endl;
    cout << "\tColour: Purple \tColour: " << get_colour() << endl;
    cout << "\tHeigth: 2 \tHeigth: " << get_height() << endl;
    cout << "\tWidth: 2 \tWidth: " << get_width() << endl;
    cout << "\tArea: 4 \tArea: " << area() << endl;
}