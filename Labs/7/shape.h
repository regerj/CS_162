#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;

class Shape {
    private:
        string name;
        string colour;
    public:
        Shape(string, string);
        string get_name();
        string get_colour();
        void set_name(string);
        void set_colour(string);
        ////float area();
        virtual float area() = 0;
        virtual void print_shape_info() = 0;
        // virtual float get_height() = 0;
        // virtual float get_width() = 0;
        // virtual float get_radius() = 0;
};

#endif