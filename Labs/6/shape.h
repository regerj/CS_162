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
        float area();
        string get_name();
        string get_colour();
        void set_name(string);
        void set_colour(string);
};

#endif