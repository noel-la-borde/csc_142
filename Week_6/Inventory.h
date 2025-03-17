#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h2"

#include <iostream>
#include <iomanip>
#include <string>


class Inventory
{
private:
    Book* books;
    int nextEntry;
    int length;

public:
    Inventory( int size ) ;
    ~Inventory();


bool addBook(const Book& theBook);
void changePrice (const std:: string& isbn, double newPrice);
void printInventory() const;


};

#endif