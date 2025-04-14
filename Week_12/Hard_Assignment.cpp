#include <iostream>
#include <cstdlib>
#include <ctime>

int roll(int sides) {
    return rand() % sides + 1;
}

void take_turn(const std::string& attacker, int& targetHP, int targetAC, int attackDie, int damageDie) {
    std::cout << "-- " << attacker << "'s turn --" << std::endl;
    int attackRoll = roll(attackDie);
    std::cout << attacker << " rolls a " << attackRoll;

    if (attackRoll >= targetAC) {
        std::cout << " and hits!" << std::endl;
        int damage = roll(damageDie);
        targetHP = std::max(0, targetHP - damage);
        std::cout << attacker << " deals " << damage << " damage. Target has " << targetHP << " HP left.\n" << std::endl;
    } else {
        std::cout << " and misses!\n" << std::endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int heroHP = 20, heroAC = 15;
    int goblinHP = 10, goblinAC = 12;

    std::cout << "Combat begins between Hero and Goblin!\n" << std::endl;

    while (heroHP > 0 && goblinHP > 0) {
        take_turn("Hero", goblinHP, goblinAC, 20, 8);
        if (goblinHP <= 0) break;

        take_turn("Goblin", heroHP, heroAC, 20, 6);
    }

    std::cout << (heroHP > 0 ? "Goblin is defeated! Hero wins!" : "Hero has fallen! Goblin wins!") << std::endl;

    return 0;
}