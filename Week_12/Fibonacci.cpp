#include <iostream>
#include "fibonacci.h"

int main() {
    int n = 10; 
    FibonacciRange range(n);

    for (auto it = range.begin(); it != range.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    return 0;
}