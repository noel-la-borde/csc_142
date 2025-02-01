/*
Roman.cpp
In this program I'll use a do-while loop to prompt the user for an integer input in the range 1
through 10, inclusive. If the input is not in range I will let them try again. The programm will 
loop until the user successfully enters a correct value. Once a valid value is entered, it will 
print a descriptive message that reports the roman numeral that is equal to the value given.
Noel La Borde
*/

#include <iostream>
using namespace std;

int main(){

    int number;

    do {
        std::cout << "Please enter an integer from 1 to 10: ";
        std::cin >> number;

        if (number < 1 || number > 10) {
            std::cout << "Invalid input. Please enter a number between 1 and 10.\n";
        }
    } while (number < 1 || number > 10);

    
    std::cout << "The Roman numeral for " << number << " is ";
    if (number == 1)
        std::cout << "I";
    else if (number == 2)
        std::cout << "II";
    else if (number == 3)
        std::cout << "III";
    else if (number == 4)
        std::cout << "IV";
    else if (number == 5)
        std::cout << "V";
    else if (number == 6)
        std::cout << "VI";
    else if (number == 7)
        std::cout << "VII";
    else if (number == 8)
        std::cout << "VIII";
    else if (number == 9)
        std::cout << "IX";
    else if (number == 10)
        std::cout << "X";

    std::cout << "\n";



return 0;
}

