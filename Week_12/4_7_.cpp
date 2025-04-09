#include <iostream>
#include <cstring>
#include <stdexcept>

struct SimpleString {
private:
    size_t max_size;
    size_t length;
    char* buffer;

public:
    
    SimpleString(size_t size)
        : max_size(size), length(0), buffer(nullptr) {
        if (size == 0) {
            throw std::runtime_error("Max size must be at least 1.");
        }
        buffer = new char[max_size];
        buffer[0] = '\0'; 
    }

    
    ~SimpleString() {
        delete[] buffer;
    }

    
    SimpleString(const SimpleString& other)
        : max_size(other.max_size), length(other.length) {
        buffer = new char[max_size];
        std::strncpy(buffer, other.buffer, max_size);
    }

    
    SimpleString(SimpleString&& other) noexcept
        : max_size(other.max_size), length(other.length), buffer(other.buffer) {
        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;
    }

    
    SimpleString& operator=(const SimpleString& other) {
        if (this == &other) return *this;

        char* new_buffer = new char[other.max_size];
        std::strncpy(new_buffer, other.buffer, other.max_size);

        delete[] buffer;
        buffer = new_buffer;
        max_size = other.max_size;
        length = other.length;

        return *this;
    }

    
    SimpleString& operator=(SimpleString&& other) noexcept {
        if (this == &other) return *this;

        delete[] buffer;

        buffer = other.buffer;
        max_size = other.max_size;
        length = other.length;

        other.buffer = nullptr;
        other.max_size = 0;
        other.length = 0;

        return *this;
    }

    
    bool append_line(const char* text) {
        size_t text_len = std::strlen(text);
        if (length + text_len + 2 > max_size) {
            return false;
        }

        std::strncpy(buffer + length, text, max_size - length);
        length += text_len;

        buffer[length++] = '\n';
        buffer[length] = '\0';

        return true;
    }

    
    void print(const char* tag) const {
        std::printf("%s: %s", tag, buffer);
    }
};