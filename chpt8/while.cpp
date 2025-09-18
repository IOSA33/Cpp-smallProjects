#include<iostream>

int main() {
    int selection{};

    while (selection < 1 || selection > 4) {
        std::cout << "Enter a number: ";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }

    std::cout << "You selected option:" << selection << std::endl;

    return 0;
}