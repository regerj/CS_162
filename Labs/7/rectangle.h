#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

using namespace std;

class Rectangle : public Shape{
    private:
        float width;
        float height;
    public:
        Rectangle(float, float);
        float get_width();
        float get_height();
        void set_width(float);
        void set_height(float);
        float area();
        virtual void print_shape_info();
        bool operator> (Rectangle &);
        bool operator< (Rectangle &);
};

#endif