#include "Inventory.h.cpp"
#include <iostream>
#include <iomanip>

// Constructor
Inventory::Inventory(int size) {
    length = size;
    books = new Book[length]; 
    nextEntry = 0; 
}

// Destructor 
Inventory::~Inventory() {
    delete[] books;
}

// Adding books to the inventory
bool Inventory::addBook(const Book& theBook) {
    if (nextEntry >= length) {
        return false; 
    }
    books[nextEntry] = theBook;
    nextEntry++;
    return true;
}

// Changing the price of a book by ISBN
void Inventory::changePrice(const std::string& isbn, double newPrice) {
    for (int i = 0; i < nextEntry; i++) {
        if (books[i].getISBN() == isbn) {
            books[i].setPrice(newPrice);
            return;
        }
    }
    std::cout << "Book with ISBN " << isbn << " not found in inventory.\n";
}

// Printing the inventory
void Inventory::printInventory() const {
    std::cout << "--------------------------------------------------------------\n";
    std::cout << "ISBN          AUTHOR           TITLE                 PRICE \n";
    std::cout << "--------------------------------------------------------------\n";
    for (int i = 0; i < nextEntry; i++) {
        books[i].display();
    }
    std::cout << "--------------------------------------------------------------\n";
}