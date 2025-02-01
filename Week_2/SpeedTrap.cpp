/*
SpeedTrap.cpp
This program will make use of conditional statements by checking
if someone is speeding or not
Noel La Borde
*/

#include <iostream>
using namespace std;
#include <string>

int main(){

int speed_limit;
double driver_speed;

std::cout<<"What is your speed limit? ";
std::cin>> speed_limit;
std::cout<<"What is your driving speed? ";
std::cin>> driver_speed;

if (driver_speed <= speed_limit)
    std::cout<<"Your speed is legal"<<std::endl;
else 
    std::cout<<"Your speed is not legal, I'll have to give you a speeding ticket."<<std::endl;

return 0;

}

