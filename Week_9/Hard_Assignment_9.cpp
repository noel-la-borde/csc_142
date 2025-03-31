#include <iostream>
#include <string>
using namespace std;

// enum class with the 4 values specified 

enum class CharacterClass { 
    Warrior, 
    Mage, 
    Archer, 
    Rogue };

// Structure Character

struct Character {
    std::string name;
    CharacterClass type;
    int health;
    float strength;
};

std::string classToString(CharacterClass type) {
    switch(type) {
        case CharacterClass::Warrior: return "Warrior";
        case CharacterClass::Mage:    return "Mage";
        case CharacterClass::Archer:  return "Archer";
        case CharacterClass::Rogue:   return "Rogue";
        default:                      return "Unknown";
    }
}

int main() {
    const int numCharacters = 4;  

    // Array of 4 character structs

    Character characters[numCharacters]{
        {"Aragon",  CharacterClass::Warrior, 100, 90.5f},
        {"Gandalf", CharacterClass::Mage,    120, 75.0f},
        {"Legolas", CharacterClass::Archer,   85, 80.0f},
        {"Frodo",   CharacterClass::Rogue,    80, 60.5f}
    };

    std::cout << "Characters:\n------------\n";

    // for loop to display character details 
    for (int i = 0; i < numCharacters; i++) {
        std::cout << "Name: " << characters[i].name << ", Type: " << classToString(characters[i].type)
                  << ", Health: " << characters[i].health << ", Strength: " << characters[i].strength << std::endl;
    }

    // average health calculation 
    
    int sumHealth = 0;
    for (int i = 0; i < 4; i++) {
        sumHealth += characters[i].health;
    }


    float avgHealth = static_cast<float>(sumHealth) / numCharacters;

    std::cout << "\nAverage Health: " << avgHealth << std::endl;

    return 0;
}