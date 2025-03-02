#include "Rectangle.h.cpp"

// Here's my constructor that Initializes length and width to 0
Rectangle::Rectangle() : length(0), width(0) {}

// here are the getter methods
double Rectangle::getLength() const { return length; }
double Rectangle::getWidth() const { return width; }
double Rectangle::getArea() const { return length * width; }

// Here are the setter methods
void Rectangle::setLength(double len) {
    if (len > 0) length = len;
    else std::cerr << "Invalid length value!\n";
}

void Rectangle::setWidth(double wid) {
    if (wid > 0) width = wid;
    else std::cerr << "Invalid width value!\n";
}