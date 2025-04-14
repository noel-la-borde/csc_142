// 8_1 Exercise
#include "fibonacci.hpp"

bool FibonacciIterator::operator!=(unsigned x) const {
    return a <= x;
}

FibonacciIterator& FibonacciIterator::operator++() {
    auto next = a + b;
    a = b;
    b = next;
    return *this;
}

unsigned FibonacciIterator::operator*() const {
    return a;
}

FibonacciIterator FibonacciRange::begin() const {
    return FibonacciIterator{};
}

unsigned FibonacciRange::end() const {
    return max;
}