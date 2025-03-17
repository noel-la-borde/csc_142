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
        Book() {
            isbn = "Unknown";
            author = "Unknown";
            title = "Unknown";
            edition = 0;
            publisherCode = "Unknown";
            price = 0.0;
        }
    
        // Constructor
        Book(std::string cn, std::string au, std::string ti, int ed, std::string pc, double pr) {
            isbn = cn;
            author = au;
            title = ti;
            edition = ed;
            publisherCode = pc;
            price = pr;
        }
    
        // Getter method for ISBN 
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
                      << edition << " | " << publisherCode << " | $" << price << "\n";
        }
    };

    #endif

