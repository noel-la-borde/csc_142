#include <iostream>
#include <cstdio>
using namespace std;

struct Goblin {
    Goblin(){
    std::cout<<"A Goblin has been summoned!" <<std::endl;

}

    ~Goblin(){
        std::cout<<"The Goblin has been vanquised!" <<std::endl;
    }
};

int main(){
{
    Goblin Goblin;
}

return 0;
}


