#include <iostream>
#include <cstddef> 
#include <cstdio>  
using namespace std;

template <typename Fn, typename In>
constexpr bool all(Fn function, In* input, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        if (!function(input[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int data[]{ 100, 200, 300, 400, 500 };
    size_t data_len = 5;

    auto all_gt100 = all([](auto x) { return x > 100; }, data, data_len);
    if (all_gt100)
        printf("All elements greater than 100.\n");
    else
        printf("Not all elements are greater than 100.\n");

    auto all_positive = all([](auto x) { return x > 0; }, data, data_len);
    if (all_positive)
        printf("All elements are positive.\n");

    return 0;
}