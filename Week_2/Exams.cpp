/* 
- Exams.cpp
- In this file, I'll create a main() function to prompt the user to input their name and three integers, 
  representing three different exam scores. Then, I'll calculate the average of the three exam scores and 
  store the result in a variable of type double. 
- Noel La Borde
- 01/27/2025
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){

std::string name;
int exam1;
int exam2;
int exam3;
double exams_avg;

std::cout<<"What is your name?";
std::cin>> name;
std::cout<<"Enter first exam score:";
std::cin>> exam1;
std::cout<<"Enter second exam score:";
std::cin>>exam2;
std::cout<<"Enter third exam score:";
std::cin>> exam3;

exams_avg= (exam1 + exam2 + exam3) / 3;


std::cout<<"\n";
std::cout<<"Hello,"<<name<<"."<<std::endl;
std::cout<<"Your three exams scores are "<<exam1<< ", " <<exam2<< ", and " <<exam3<< "."<<std::endl;
std::cout<<fixed<<setprecision(2)<< "Your average exam score is " <<exams_avg<< " points."<<std::endl;


return 0;
}

