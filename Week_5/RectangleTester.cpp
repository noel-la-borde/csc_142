/*
RectangleTestercpp
In this program my task is to create the complete Rectangle class 
and test it as specified by m instructor. 
Noel La Borde
02-22-2025
*/

#include "Rectangle.h.cpp"
#include "RectangleDefinitions.cpp"
#include <iostream>
#include <iomanip>
//#include "Rectangle.h.cpp"

using namespace std;

int main() {
    // Calling the Rectangle constructor to create three Rectangle objects for different rooms
    Rectangle kitchen, bedroom, livingRoom;
    
    double length, width;

    // Getting dimensions for Kitchen
    cout << "Enter the length of the kitchen: ";
    cin >> length;
    cout << "Enter the width of the kitchen: ";
    cin >> width;
    kitchen.setLength(length);
    kitchen.setWidth(width);

    // Getting Dimensions for Bedroom
    cout << "Enter the length of the bedroom: ";
    cin >> length;
    cout << "Enter the width of the bedroom: ";
    cin >> width;
    bedroom.setLength(length);
    bedroom.setWidth(width);

    // Getting dimensions for Living Room
    cout << "Enter the length of the living room: ";
    cin >> length;
    cout << "Enter the width of the living room: ";
    cin >> width;
    livingRoom.setLength(length);
    livingRoom.setWidth(width);

    // The output of this program will be displayed using the following format:
    cout << fixed << setprecision(2);
    cout << "\nRoom Sizes and Areas:\n";
    cout << "-------------------------------------\n";
    cout << left << setw(15) << "Room" << setw(10) << "Size" << setw(10) << "Area\n";
    cout << "-------------------------------------\n";
    cout << left << setw(15) << "Kitchen" 
         << setw(5) << kitchen.getLength() << " x " << setw(5) << kitchen.getWidth() 
         << setw(10) << kitchen.getArea() << "\n";

    cout << left << setw(15) << "Bedroom" 
         << setw(5) << bedroom.getLength() << " x " << setw(5) << bedroom.getWidth() 
         << setw(10) << bedroom.getArea() << "\n";

    cout << left << setw(15) << "Living Room" 
         << setw(5) << livingRoom.getLength() << " x " << setw(5) << livingRoom.getWidth() 
         << setw(10) << livingRoom.getArea() << "\n";

    cout << "-------------------------------------\n";

    // Calculating total apartment area
    double totalArea = kitchen.getArea() + bedroom.getArea() + livingRoom.getArea();
    cout << "Total apartment area: " << totalArea << " square units\n";

    return 0;
}