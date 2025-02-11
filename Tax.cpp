/*
Tax.cpp
In this file, I'll create a program that will get information about a purchase from the user,
calculate the tax and total purchase amount, and display the results.
Noel La Borde
02-03-2025
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double slstx( double i, double t){
return (i * t);
}

double ttl_a(double i, double s){
return(i + s);
}
// I decided to create two functions to handle the calculations, following Wilfredo's Intro Slide example. 

int main(){

    const double Tax = 0.06;
    std:: string purchase_description, initial_cost;
    double initial_cost_value;
    double sales_tax;
    double total_amount;
    bool keepGoing = true;
    std:: string user_Response;


    while(keepGoing){
        std::cout<< "What item did you purchase? " ;
        
        std::getline(cin, purchase_description); 
        
         
        std::cout<<"What was the cost of your item? ";
    
        std::getline(cin, initial_cost);
        // std::cin>>initial_cost;
        initial_cost_value = std:: stod(initial_cost);
        
        while (initial_cost_value <= 0){
            std::cout<<"Invalid input, please enter another amount: ";
            std::getline(cin, initial_cost);
            // std::cin>> initial_cost;
        }

        std::cout<<fixed<<setprecision(2);
        std::cout<<"You purchased a/an: " <<purchase_description<< std::endl;
        std::cout<<"The selling price for your item is: $"<< initial_cost<< std::endl;

        sales_tax= slstx (initial_cost_value, Tax);
        std::cout<<"The sales tax applied on your purchase is: $" << sales_tax<<std::endl;

        total_amount= ttl_a (initial_cost_value, sales_tax);
        std::cout<<"The total Amount of your purchase is: $" << total_amount<<std::endl;

        std::cout<<"Do you want to enter another purchase? (Y/N)";
        std::getline(cin, user_Response);
    
        if (user_Response != "Y'" && user_Response != "y"){
            keepGoing= false;
        }
    }
        
       
    return 0;
}

 


