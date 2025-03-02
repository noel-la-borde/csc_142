/*
PrimeFactorial.cpp
This program will generate an integer less than 50 and will calculate wether the number is prime or not. 
It will also ask the user if thay want to repeat the process or not. 
Noel La Borde
02-22-2025
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to calculate factorial
double factorial(int num) {
    double fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    srand(time(0)); // Seed random number generator
    bool keepgoing = true;
    std:: string choice;

    
    while (keepgoing){ 
        int randomNum = rand() % 50; // Generate a random number less than 50
       std::cout << "Generated number: " << randomNum <<std::endl;
        
        if (isPrime(randomNum)) {
           std::cout << "The number is prime." << std::endl;
           std::cout << "Factorial of " << randomNum << " is " << factorial(randomNum) << std::endl;
        } else {
           std::cout << "The number is not prime." << std::endl;
        }
    
        std::cout << "Do you want to repeat? (y/n): ";
        std::getline(cin, choice); 
        
      if (choice != "y" && choice != "Y"){
        keepgoing = false;
    }
    }
    cout << "Goodbye!" << "\n";
    


return 0; 

}
    