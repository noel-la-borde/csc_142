#include "Inventory.h.cpp"
#include "InventoryDef.cpp"
#include <iostream>

int main() {
    // Inventory object with size 10
    Inventory inventory(10);

    // Adding books to the inventory
    Book book1("013478796X", "Tony Gaddis", "Starting Out With Java", 4, "PE", 121.75);
    Book book2("0321409493", "John Lewis", "Java Software Solutions", 5, "AW", 94.00);
    Book book3("0134743350", "Harvey Deitel", "Java How to Program", 12, "PE", 134.84);
    Book book4("002360692X", "Richard Johnsonbaugh", "Algorithms", 1, "PH", 109.00);
    Book book5("1593276036", "Eric Matthes", "Python Crash Course", 1, "NS", 39.95);
    Book book6("0143067889", "Ray Kurzweil", "The Singularity is Near", 1, "PG", 17.70);

    inventory.addBook(book1);
    inventory.addBook(book2);
    inventory.addBook(book3);
    inventory.addBook(book4);
    inventory.addBook(book5);
    inventory.addBook(book6);

    // Printing initial inventory
    std::cout << "\nInitial Inventory:\n";
    inventory.printInventory();

    // Changing prices
    inventory.changePrice("013478796X", 50.00);
    inventory.changePrice("0143067889", 9.95);
    inventory.changePrice("0134743350", 100.00);

    // Printing updated inventory
    std::cout << "\nUpdated Inventory:\n";
    inventory.printInventory();

    return 0;
}