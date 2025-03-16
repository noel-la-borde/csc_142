#include "Inventory.h.cpp"
#include "InventoryDef.cpp"
#include <iostream>

int main() {
    // Inventory object with size 10
    Inventory inventory(10);

    // Books to the inventory
    Book book1("013478796X", "Tony Gaddis", "Starting Out With Java", 4, "PE", 121.75);
    Book book2("0321409493", "John Lewis", "Java Software Solutions", 5, "AW", 94.00);
    Book book3("0134743350", "Harvey Deitel", "Java How to Program", 12, "PE", 134.84);
    Book book4("002360692X", "Richard Johnsonbaugh", "Algorithms", 1, "PH", 109.00);
    Book book5("1593276036", "Eric Matthes", "Python Crash Course", 1, "NS", 39.95);
    Book book6("0143067889", "Ray Kurzweil", "The Singularity is Near", 1, "PG", 17.70);
    Book book7("0134444329", "Tony Gaddis", "Starting Out With Python", 4, "PE", 99.95);
    Book book8("0133582736", "Tony Gaddis", "Starting Out With Python", 3, "PE", 19.95);
    Book book9("013478796X", "Tony Gaddis", "Starting Out With Java: From Control Structures through Data Structures", 4, "PE", 145.38);
    Book book10("1119056553", "Cay Horstmann", "Python for Everyone", 2, "WI", 98.38);
    Book book11("0134802217", "Tony Gaddis", "Starting Out With Java: From Control Structures through Objects", 7, "PE", 188.95);
    Book book12("0134462017", "Tony Gaddis", "Starting Out With Java: Early Objects", 6, "PE", 58.50);



    inventory.addBook(book1);
    inventory.addBook(book2);
    inventory.addBook(book3);
    inventory.addBook(book4);
    inventory.addBook(book5);
    inventory.addBook(book6);
    inventory.addBook(book7);
    inventory.addBook(book8);
    inventory.addBook(book9);
    inventory.addBook(book10);
    inventory.addBook(book11);
    inventory.addBook(book12);
    
    // Printing Initial inventory
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