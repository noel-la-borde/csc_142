#include "Book.h2.cpp"

// Here's the constructor definition
Book::Book() {
    codeNum = 0;
    author = 0;
    title = 0;
    edition = 0;
    pubCode = 0;
    price = 0;
}


// Here are the getter methods
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
double Book::getPrice() const { return price; }
int Book::getEdition() const { return edition; }
std::string Book::getISBN() const { return codeNum; }
std::string Book::getPubCode() const { return pubCode; }

// Setter method
void Book::changePrice(double newPrice) {
    price = newPrice;
}