#include <iostream>
#include <random>
#include <string>

std::string generate_password(std::size_t length) {
    const char alphabet[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    const std::size_t alphabet_size = sizeof(alphabet) - 1; 

    std::random_device rd;
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937_64 engine(seed);
    std::uniform_int_distribution<std::size_t> dist(0, alphabet_size - 1);

    std::string password;
    password.reserve(length);

    for (std::size_t i = 0; i < length; ++i) {
        password += alphabet[dist(engine)];
    }

    return password;
}

int main() {
    std::size_t password_length = 16; 
    std::string password = generate_password(password_length);
    std::cout << "Generated password: " << password << '\n';
    return 0;
}