#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "square.h"
#include <iostream>
#include <iomanip>

using namespace std;

void print_shape_info(Shape &);

int main(){
    // Shape shape1("Shape", "Green");
    // cout << endl << "Testing shape object attributes." << endl;
    // cout << endl << "\tExpected: \tActual:" << endl;
    // cout << "\tName: Shape \tName: " << shape1.get_name() << endl;
    // cout << "\tColour: Green \tColour: " << shape1.get_colour() << endl << endl; 

    Rectangle rectangle1(2, 3);

    print_shape_info(rectangle1);

    Circle circle1(2);

    print_shape_info(circle1);

    Square square1(2);

    print_shape_info(square1);

    try{
        Rectangle rectangle2(2, 0);
    }
    catch(exception & inv_arg){
        cout << inv_arg.what() << endl;
    }
    ////Rectangle rectangle2(2, 0);

    ////print_shape_info(rectangle2);
    
    // Rectangle r1(2, 2);
    // Rectangle r2(4, 4);
    // cout << endl << "Testing if rectangle 1 with an area of 4 is greater than rectangle 2 with an area of 16." << endl;
    // if(r1 > r2){
    //     cout << "Success!" << endl;
    // }else{
    //     cout << "Failed!" << endl;
    // }

    // cout << endl << "Testing if rectangle 1 with an area of 4 is less than rectangle 2 with an area of 16." << endl;
    // if(r1 < r2){
    //     cout << "Success!" << endl;
    // }else{
    //     cout << "Failed!" << endl;
    // }

    return 0;
}

void print_shape_info(Shape & shape){
    shape.print_shape_info();
    // if(shape.get_name() == "Rectangle"){
    //     cout << endl << "Testing rectangle object attributes." << endl;
    //     // cout << endl << "\tExpected: \tActual:" << endl;
    //     // cout << "\tName: Rectangle\tName: " << rectangle1.get_name() << endl;
    //     // cout << "\tColour: Red \tColour: " << rectangle1.get_colour() << endl;
    //     // cout << "\tHeigth: 2 \tHeigth: " << rectangle1.get_height() << endl;
    //     // cout << "\tWidth: 3 \tWidth: " << rectangle1.get_width() << endl;
    //     // cout << "\tArea: 6 \tArea: " << rectangle1.area() << endl;
    // }
    // else if(shape.get_name() == "Circle"){
    //     cout << endl << "Testing circle object attributes." << endl;
    //     // cout << endl << "\tExpected: \tActual:" << endl;
    //     // cout << "\tName: Circle\tName: " << circle1.get_name() << endl;
    //     // cout << "\tColour: Blue \tColour: " << circle1.get_colour() << endl;
    //     // cout << "\tRadius: 2 \tRadius: " << circle1.get_radius() << endl;
    //     // cout << "\tArea: 12.566 \tArea: " << circle1.area() << endl;
    // }
    // else if(shape.get_name() == "Square"){
    //     cout << endl << "Testing square object attributes." << endl;
    //     // cout << endl << "\tExpected: \tActual:" << endl;
    //     // cout << "\tName: Square\tName: " << square1.get_name() << endl;
    //     // cout << "\tColour: Purple \tColour: " << square1.get_colour() << endl;
    //     // cout << "\tHeigth: 2 \tHeigth: " << square1.get_height() << endl;
    //     // cout << "\tWidth: 2 \tWidth: " << square1.get_width() << endl;
    //     // cout << "\tArea: 4 \tArea: " << square1.area() << endl;
    // }
    // cout << endl << "\tExpected: \tActual:" << endl;
    // cout << "\tName: Square\tName: " << shape.get_name() << endl;
    // cout << "\tColour: Purple \tColour: " << shape.get_colour() << endl;
    // if(shape.get_name() == "Circle"){
    //     cout << "\tRadius: 2 \tRadius: " << shape.get_radius() << endl;
    // }else{
    //     cout << "\tHeigth: 2 \tHeigth: " << shape.get_height() << endl;
    //     cout << "\tWidth: 2 \tWidth: " << shape.get_width() << endl;
    // }
    // cout << "\tArea: 4 \tArea: " << shape.area() << endl;
}