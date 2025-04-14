#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <limits>
using namespace std;

class UnsignedBigInteger {
    std::vector<uint8_t> digits; 

    void trim() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
    }

public:
    UnsignedBigInteger(int value = 0) {
        if (value < 0) throw std::invalid_argument("Only unsigned values allowed");
        if (value == 0) digits.push_back(0);
        while (value > 0) {
            digits.push_back(value % 10);
            value /= 10;
        }
    }

    UnsignedBigInteger(const std::string& s) {
        for (int i = s.size() - 1; i >= 0; --i) {
            if (!isdigit(s[i])) throw std::invalid_argument("Invalid digit");
            digits.push_back(s[i] - '0');
        }
        trim();
    }

    UnsignedBigInteger operator+(const UnsignedBigInteger& other) const {
        UnsignedBigInteger result;
        result.digits.clear();

        int carry = 0, i = 0;
        while (i < digits.size() || i < other.digits.size() || carry) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
            ++i;
        }
        return result;
    }

    UnsignedBigInteger operator-(const UnsignedBigInteger& other) const {
        if (*this < other) throw std::overflow_error("Negative result");

        UnsignedBigInteger result;
        result.digits.clear();
        int borrow = 0;

        for (size_t i = 0; i < digits.size(); ++i) {
            int diff = digits[i] - borrow - (i < other.digits.size() ? other.digits[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else borrow = 0;
            result.digits.push_back(diff);
        }
        result.trim();
        return result;
    }

    UnsignedBigInteger operator*(const UnsignedBigInteger& other) const {
        UnsignedBigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (size_t i = 0; i < digits.size(); ++i)
            for (size_t j = 0; j < other.digits.size(); ++j) {
                int prod = digits[i] * other.digits[j] + result.digits[i + j];
                result.digits[i + j] = prod % 10;
                result.digits[i + j + 1] += prod / 10;
            }

        result.trim();
        return result;
    }

    bool operator<(const UnsignedBigInteger& other) const {
        if (digits.size() != other.digits.size())
            return digits.size() < other.digits.size();
        for (int i = digits.size() - 1; i >= 0; --i)
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        return false;
    }

    explicit operator int() const {
        UnsignedBigInteger maxInt(std::to_string(std::numeric_limits<int>::max()));
        if (*this < maxInt || *this == maxInt) {
            int value = 0;
            for (int i = digits.size() - 1; i >= 0; --i)
                value = value * 10 + digits[i];
            return value;
        }
        throw std::overflow_error("Value too large for int");
    }

    bool operator==(const UnsignedBigInteger& other) const {
        return digits == other.digits;
    }

    friend std::ostream& operator<<(std::ostream& os, const UnsignedBigInteger& num) {
        for (int i = num.digits.size() - 1; i >= 0; --i)
            os << (char)(num.digits[i] + '0');
        return os;
    }

    // Int overloads
    UnsignedBigInteger operator+(int val) const { return *this + UnsignedBigInteger(val); }
    UnsignedBigInteger operator-(int val) const { return *this - UnsignedBigInteger(val); }
    UnsignedBigInteger operator*(int val) const { return *this * UnsignedBigInteger(val); }
};

int main() {
    UnsignedBigInteger a("12345678901234567890");
    UnsignedBigInteger b(9999999);
    std::cout << "a + b = " << a + b << "\n";
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "a * b = " << a * b << "\n";

    try {
        int narrowed = static_cast<int>(a);
        std::cout << "int conversion: " << narrowed << "\n";
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
