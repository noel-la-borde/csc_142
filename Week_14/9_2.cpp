#include <iostream>
#include <map>
#include <string>

int main(int argc, char* argv[]) {
    std::map<size_t, int> length_counts;

    for (int i = 1; i < argc; ++i) {
        size_t len = std::string(argv[i]).size();
        ++length_counts[len];
    }

    for (const auto& [length, count] : length_counts) {
        std::cout << "Length " << length << ": ";
        for (int i = 0; i < count; ++i)
            std::cout << '*';
        std::cout << '\n';
    }

    return 0;
}