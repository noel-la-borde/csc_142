#include <iostream>
using namespace std;

int main(){

    int adventurer_gold = 100;
    int h_potions = 10; 
    int b_potions;
    //int b2_potions= b_potions * h_potions;
    //int gold_left= b2_potions - adventurer_gold;

    std::cout<<"Welcome to the Potion Shop!" << std::endl;
    std::cout<<"Each Potion costs 10 gold pieces." << std::endl;

    std::cout<<"How many potions would you like to buy?"<<std::endl;
    std::cin >> b_potions;
    
    int b2_potions= b_potions * h_potions;
    
     if (b2_potions <= adventurer_gold) {
        adventurer_gold -= b2_potions;
            
            std::cout<<"You bought " << b_potions << " potions for " << b2_potions << " gold pieces.";
            
            int gold_left= adventurer_gold - b2_potions;
            
            std::cout<<" You now have " << gold_left << " gold pieces left. Safe travels, adventurer! ";
     } else {
        cout << "You do not have enough gold to buy " << b_potions << " potions.\n";
        cout << "You only have " << adventurer_gold << " gold pieces.\n";
    }

return 0;

}
