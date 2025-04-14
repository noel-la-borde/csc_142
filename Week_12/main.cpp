// 8_2 Exercise

#include <cstdio>
#include "prime.hpp"

int main() {
    for (const auto p : PrimeNumberRange{50}) {
        std::printf("%u ", p);
    }
    std::puts("");
    return 0;
}