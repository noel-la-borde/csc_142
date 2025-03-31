#include <iostream>
#include <string>
using namespace std;

int main(){

    std::string name;
    int age;
    
        // Prompting the user to enter their name 

        std::cout<<"Please enter your name: "; 
        std::getline(cin, name);
        // Prompting the user to enter their age

        std::cout<<"Please enter your age: ";
        std::cin >> age;

        // int daysOld variable value
    int daysOld= 365 * age;
    
        std::cout<< "Hello, " << name << "!  You are aproximately " << daysOld << " days old." << endl;

return 0;

}