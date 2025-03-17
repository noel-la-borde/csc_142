/*
Book.h.cpp
In this program I will implement the Book class defined by a diagram given by the intructor.
Noel La Borde
02-22-2025
*/


#include "Book.h"
#include "BookDef"
#include <iostream>
#include <iomanip>
using namespace std; 

// Here's my function printBook that sets the layout of the program's output to be printed using the following style:

void printBooks(const Book &b1, const Book &b2, const Book &b3) {
    std::cout << "-----------------------------------------------------------------------------------------\n";
    std::cout << std::left << std::setw(12) << "ISBN" 
              << std::setw(15) << "AUTHOR" 
              << std::setw(45) << "TITLE"
              << std::setw(5)  << "ED" 
              << std::setw(5)  << "PUB"
              << std::right << std::setw(10) << "PRICE" << "\n";
    std::cout << "-----------------------------------------------------------------------------------------\n";

    std::cout << std::left << std::setw(12) << b1.getISBN() 
              << std::setw(15) << b1.getAuthor().substr(0, 13)
              << std::setw(45) << b1.getTitle().substr(0, 40)
              << std::setw(5)  << b1.getEdition()
              << std::setw(5)  << b1.getPubCode()
              << std::right << std::setw(10) << std::fixed << std::setprecision(2) << "$ " << b1.getPrice() << "\n";

    std::cout << std::left << std::setw(12) << b2.getISBN() 
              << std::setw(15) << b2.getAuthor().substr(0, 13)
              << std::setw(45) << b2.getTitle().substr(0, 40)
              << std::setw(5)  << b2.getEdition()
              << std::setw(5)  << b2.getPubCode()
              << std::right << std::setw(10) << std::fixed << std::setprecision(2) << "$ " << b2.getPrice() << "\n";

    std::cout << std::left << std::setw(12) << b3.getISBN() 
              << std::setw(15) << b3.getAuthor().substr(0, 13)
              << std::setw(45) << b3.getTitle().substr(0, 40)
              << std::setw(5)  << b3.getEdition()
              << std::setw(5)  << b3.getPubCode()
              << std::right << std::setw(10) << std::fixed << std::setprecision(2) << "$ " << b3.getPrice() << "\n";

    std::cout << "-----------------------------------------------------------------------------------------\n";
}

int main() {
    // Here is where book objects are created
    Book book1("013478796X", "Tony Gaddis", "Starting Out With Java: From Control Structures through Data Structures", 4, "PE", 118.30);
    Book book2("0321409493", "John Lewis", "Java Software Solutions: Foundations of Program Design", 5, "AW", 94.05);
    Book book3("0134743350", "Harvey Deitel", "Java How to Program, Early Objects", 12, "PE", 134.84);

    // Print books before price change
    printBooks(book1, book2, book3);

    // Changing book prices
    std::cout << "\nChanging book1 price from $ 118.30 to $ 145.68\n";
    book1.changePrice(145.68);
    std::cout << "Changing book2 price from $ 94.05 to $ 117.79\n";
    book2.changePrice(117.79);
    std::cout << "Changing book3 price from $ 134.84 to $ 59.99\n";
    book3.changePrice(59.99);

    // Print books after price change
    std::cout << "\n";
    printBooks(book1, book2, book3);

    return 0;
}


