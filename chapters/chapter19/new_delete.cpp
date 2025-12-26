#include <iostream>
#include <array>
#include <string>
#include <algorithm>

int main() {

    std::cout << "How many names would you like to enter? ";
    size_t length {};
    std::cin >> length;

    auto* arr { new std::string[length]{} };

    for (size_t i = 0; i < length; ++i) {
        std::cout << "Enter name #" << i + 1 << ": ";
        std::string input{};
        std::cin >> input;
        arr[i] = input;
    }

    std::cout << '\n';
    std::cout << "Here is your sorted list:\n";
    std::sort(arr, arr + length);
    for (size_t i = 0; i < length; ++i) {
        std::cout << "Name #" << i + 1 << ": " << arr[i] << '\n';
    }

    delete[] arr;
}