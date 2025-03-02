#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    // Rectangle Constructor
    Rectangle();

    // Getters
    double getLength() const;
    double getWidth() const;
    double getArea() const;

    // Setters
    void setLength(double len);
    void setWidth(double wid);
};

#endif  // RECTANGLE_H