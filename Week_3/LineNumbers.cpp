/*
LineNumbers.cpp
In this file, I'll create a program that will prompt the user to enter the name of an input file that
contains the text to which line numbers will be added, and then an output file that will contain the 
numbered text. 
Noel La Borde
02-12-2025
*/


#include <iostream>
#include <fstream>
#include <string>
#include <format>

using namespace std;

int main(){

    int lines= 1;
    std::string filename; 

    
    // Code that prompts the user to enter a file name for reading 

    std::cout<< "Please enter the name of your file for reading: ";
    std::getline(cin, filename);
    std::ifstream inFile;
    inFile.open(filename);
    std::string text;

    
    // Code tha prompts the user to enter a file name for the output file that will contain the format specified in the program. 

    std::cout << "Please enter the name of your output file: "; 
    std::getline(cin, filename);
    std::ofstream outFile;
    outFile.open(filename);
    
    while (std::getline(inFile, text)) {

        /* 
        I went to tuttoring for this part of the
        program. We both Evan and myself tried the 
        following lines of code but we weren't able
        to get it working. "int lines" right under
        int main() was set to "5" in the previous 
        method we used:
        
        std::string formatted = std::format("{:<5d}", lines);
        outFile << text << formatted <<std::endl;
       */

       /* I found a different way to do it online but I don't know if it's 
        good enough to meet the assignment requirements */
       outFile << setw(5) << lines << "." << text << "\n" <<std::endl;
        lines++;

    }
    outFile.close();
    inFile.close();
    
    return 0; 

}













