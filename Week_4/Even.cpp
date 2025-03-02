/*
Even.cpp
This program will make use of randomly generated integers to determine whether 
a number is even or odd.
Noel La Borde
02-22-2025
*/

#include <iostream>
#include <ctime>
using namespace std;

// Boolean method that executes the calculation to determine wheter a number is Even or Odd.

bool isEven(int myNum){
    return(myNum % 2 == 0);
     
}
int main() {

// Random number generator followed by the variables that hold the numbers. 

srand(time(0));
int total_num= 1000;
int even_count= 0;
int odd_count= 0;

/*For loop that defines the random_num variable and 
separates the numbers into the two groups,
to then be added to the counters. */

for (int i= 1; i <= total_num; i++){
     int random_num= rand() % 101; 
     if (isEven(random_num)){
        even_count++;
    } 
    else {
        odd_count++;
    }
     
}
// Simple but at the same time creative way to display the output of the program. 

std::cout<<"================================" << std::endl;
std::cout<< "The number of random numbers is: " << total_num <<std::endl;
std::cout<< "The number of even numbers is: " << even_count<< std::endl;
std::cout<<"The number of odd numbers is: " << odd_count << std::endl;
std::cout<<"================================"; 


    return 0;

}