#include <iostream>
#include <string>
using namespace std;


int main(){   
    // Constant declarations
    const double KM_PER_MILE = 1.60934;
    const double LITERS_PER_GALLON = 3.78541;
    
    // Variable declarations
    std::string desc;
    int miles; 
    float gallons;     
    float mpg, liters_per_100km; 

    // Prompt for user inputs
    // Ensure that when typing input in the console, you give a whole number for miles,
    // otherwise you might run into miscalculations
    std::cout<<"Please enter a description of your car: ";
    std::getline(std::cin, desc);
    std::cout<<"How many miles did you drive? ";
    std::cin>>miles;
    std::cout<<"How many gallons of gas did you use? ";
    std::cin>>gallons;
    
    // Calculate the results
    mpg = miles / gallons;
    double kilometers= miles * KM_PER_MILE;
    double liters= gallons * LITERS_PER_GALLON;
    liters_per_100km = liters / kilometers * 100; 

    // Print the user inputs and final results
    std::cout<<"\n";
    std::cout<<"Fuel efficiency of your " + desc + ":"<<std::endl;
    std::cout<<"You drove " << miles << " miles, and used " 
    << gallons << " gallons. " <<std::endl;
    std::cout<<"Your fuel efficiency is " << mpg << " miles per gallon of gas. "<<std::endl;
    
    // Print the user inputs and final results
    std::cout<<"\n";
    std::cout<<"Fuel efficiency of your " + desc + ":"<<std::endl;
    std::cout<<"You drove " << kilometers << " kilometers , and used " 
    << liters << " liters of gas." <<std::endl;
    std::cout<<"Your fuel efficiency is " <<liters_per_100km<<" liters per 100 kilometer." <<std::endl;

    return 0;
}