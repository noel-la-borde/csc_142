#include <iostream>
#include <string>
using namespace std;

void drinkPotion(int& hp, int h_potion){
    hp = hp += h_potion;
   

}

void damageHero(int* hp, int damage){
    *hp -= damage;
     
}

int main() {

    int hero_hp= 10;

    std::cout<< "Hero's starting HP: " << hero_hp << endl;

    std::cout << "Hero drinks a healing potion (+5 HP)." << std::endl;
    drinkPotion(hero_hp, 5);
    std::cout << "Hero's current HP: " << hero_hp << std::endl;

    std::cout << "Hero takes damage from a goblin (-3 HP)." << std::endl;
    damageHero(&hero_hp, 3);
    std::cout << "Hero's current HP: " << hero_hp << std::endl;

    return 0;

}

