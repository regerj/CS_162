#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

using namespace std;

class Circle : public Shape{
    private:
        float radius;
    public:
        float area();
        Circle(float);
        float get_radius();
        ////void set_radius(float);
};

#endif