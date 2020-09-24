#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"
#include "shape.h"

using namespace std;

class Square : public Rectangle{
    public:
        Square(float);
        void print_shape_info();
};

#endif