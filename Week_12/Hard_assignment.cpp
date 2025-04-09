#include <iostream>
#include <string>

class Inventory {
private:
    std::string* items;
    int capacity;
    int count;

public:
    Inventory(int cap = 10) : capacity(cap), count(0), items(new std::string[cap]) {}

    Inventory(const Inventory& other)
        : capacity(other.capacity), count(other.count), items(new std::string[other.capacity]) {
        for (int i = 0; i < count; ++i)
            items[i] = other.items[i];
    }

    ~Inventory() { delete[] items; }

    void addItem(const std::string& item) {
        if (count < capacity)
            items[count++] = item;
        else
            std::cout << "Inventory full!\n";
    }

    void showInventory() const {
        for (int i = 0; i < count; ++i)
            std::cout << "- " << items[i] << "\n";
    }
};

int main() {
    Inventory inventory1;
    inventory1.addItem("Magic Sword");
    inventory1.addItem("Potion of Healing");

    Inventory inventory2 = inventory1;
    inventory2.addItem("Bag of Holding");

    std::cout << "Inventory 1:\n";
    inventory1.showInventory();

    std::cout << "\nInventory 2:\n";
    inventory2.showInventory();
}
