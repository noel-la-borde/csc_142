//8_1 Exercise
struct FibonacciIterator {
    unsigned a = 0, b = 1;

    bool operator!=(unsigned x) const;
    FibonacciIterator& operator++();
    unsigned operator*() const;
};

struct FibonacciRange {
    unsigned max;

    FibonacciIterator begin() const;
    unsigned end() const;
};