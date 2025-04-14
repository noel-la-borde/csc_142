// 8_2 Exercise
#pragma once

struct PrimeIterator {
    unsigned current;

    bool operator!=(unsigned max) const;
    PrimeIterator& operator++();
    unsigned operator*() const;
};

struct PrimeNumberRange {
    unsigned max;

    PrimeIterator begin() const;
    unsigned end() const;
};
