#include <iostream>
using namespace std;

void countdown_to_lightspeed(int seconds){

    
    for (int i = seconds; i > 0; --i) {
        std::cout << "Jumping in  " << i << "...\n";
    }
    std::cout << "Punch it, Chewie!\n";
}

int main() {
    countdown_to_lightspeed(5);

    return 0;
}    

