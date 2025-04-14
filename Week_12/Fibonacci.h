#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iterator>


class FibonacciIterator {
public:
    FibonacciIterator(int first, int second)
        : first_(first), second_(second) {}

    int operator*() const {
        return first_;
    }

    FibonacciIterator& operator++() {
        int next = first_ + second_;
        first_ = second_;
        second_ = next;
        return *this;
    }

    bool operator!=(const FibonacciIterator& other) const {
        return first_ != other.first_;
    }

private:
    int first_;
    int second_;
};


class FibonacciRange {
public:
    FibonacciRange(int n)
        : n_(n) {}

    FibonacciIterator begin() const {
        return FibonacciIterator(0, 1);
    }

    FibonacciIterator end() const {
        return FibonacciIterator(n_, n_);
    }

private:
    int n_;
};

#endif 