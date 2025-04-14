// 8_2 Exercise
#include "prime.hpp"
#include <cmath>

bool is_prime(unsigned n) {
    if (n < 2) return false;
    for (unsigned i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool PrimeIterator::operator!=(unsigned max) const {
    return current < max;
}

PrimeIterator& PrimeIterator::operator++() {
    do {
        ++current;
    } while (!is_prime(current));
    return *this;
}

unsigned PrimeIterator::operator*() const {
    return current;
}

PrimeIterator PrimeNumberRange::begin() const {
    PrimeIterator it{2};
    while (it.current < max && !is_prime(it.current)) {
        ++it.current;
    }
    return it;
}

unsigned PrimeNumberRange::end() const {
    return max;
}