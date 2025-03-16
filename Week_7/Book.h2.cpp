#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <iomanip>
#include <string>

class Book {
private:
    std::string isbn, author, title, publisherCode;
    int edition;
    double price;

public:
    // Default Constructor 
    Book() : isbn("Unknown"), author("Unknown"), title("Unknown"), edition(0), publisherCode("Unknown"), price(0.0) {}

    // Constructor
    Book(std::string cn, std::string au, std::string ti, int ed, std::string pc, double pr)
        : isbn(cn), author(au), title(ti), edition(ed), publisherCode(pc), price(pr) {}

    // Getter for ISBN 
    std::string getISBN() const {
        return isbn;
    }

    // Setter for price 
    void setPrice(double newPrice) {
        price = newPrice;
    }

    // Display method 
    void display() const {
        std::cout << isbn << " | " << author << " | " << title << " | " 
                  << edition << " | " << publisherCode << " | $" << std::fixed << std::setprecision(2) << price << "\n";
    }

    // Overloading << operator for formatted output
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << std::left << std::setw(12) << book.isbn
           << std::setw(20) << book.author
           << std::setw(45) << book.title
           << std::setw(4)  << book.edition
           << std::setw(5)  << book.publisherCode
           << "$" << std::fixed << std::setprecision(2) << std::setw(8) << book.price;
        return os;
    }

    // Overloading == operator to compare books based on ISBN
    bool operator==(const Book& other) const {
        return this->isbn == other.isbn;
    }
};

#endif
