#include <iostream>

constexpr int perfectSquares[] {1, 4, 9};

int main() {
    while (true) {
        std::cout << "Enter a single digit integer, or -1 to quit:";
        int input{};
        std::cin >> input;
        if (input == -1) {
            break;
        }
        if (!std::cin) {
            std::cout << "This is not a integer. Try again!";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        } else {
            bool found{false};
            for (const auto& i: perfectSquares) {
                if (input == i) {
                    std::cout << "Input " << input << " is a perfect square!";
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << input << " is not a perfect square";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "\nBye!";
}