#ifndef BOOK_H
#define BOOK_H


#include <iostream>
#include <iomanip>
#include <string>

class Book {
private:
    std::string codeNum;
    std::string author;
    std::string title;
    int edition;
    std::string pubCode;
    double price;

public:
    // Constructor
    Book(std::string cn, std::string au, std::string ti, int ed, std::string pc, double pr);

    // Here are the accessor methods or getters
    std::string getTitle() const;
    std::string getAuthor() const;
    double getPrice() const;
    int getEdition() const;
    std::string getISBN() const;
    std::string getPubCode() const;

    // Mutator method or setter
    void changePrice(double newPrice);
};

#endif 