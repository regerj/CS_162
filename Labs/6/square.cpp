#include "square.h"

using namespace std;

Square::Square(float side) : Rectangle(side, side){
    set_name("Square");
    set_colour("Purple");
}