#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= static_cast<int>(std::sqrt(n)); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

class PrimeNumberRange {
public:
    class Iterator {
    public:
        Iterator(int current, int stop) : current_(current), stop_(stop) {
            advance_to_next_prime();
        }

        int operator*() const { return current_; }

        Iterator& operator++() {
            ++current_;
            advance_to_next_prime();
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current_ != other.current_;
        }

    private:
        int current_;
        int stop_;

        void advance_to_next_prime() {
            while (current_ < stop_ && !is_prime(current_)) {
                ++current_;
            }
        }
    };

    PrimeNumberRange(int start, int stop) : start_(start), stop_(stop) {}

    Iterator begin() const { return Iterator(start_, stop_); }
    Iterator end() const { return Iterator(stop_, stop_); }

private:
    int start_;
    int stop_;
};

int main() {
    for (int prime : PrimeNumberRange(2, 5000)) {
        std::cout << prime << ' ';
    }
    std::cout << std::endl;
    return 0;
}