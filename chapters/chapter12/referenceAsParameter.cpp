#include <iostream>
#include <string>

void printValue(const std::string& y) {
    std::cout << y << std::endl;
} // y is destroyed here

int main() {
    std::string x {"Hello, std::string"};

    printValue(x);

    return EXIT_SUCCESS;
}