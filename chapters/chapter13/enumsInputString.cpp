#include <iostream>
#include <string_view>

enum Color {
    black,
    blue,
    red,
};

constexpr std::string_view getColor(Color color) {
    switch (color) {
        case black:
            return "black";
        case blue:
            return "blue";
        case red:
            return "red";
        default:
            return "no color";
    }
}

int main() {
    constexpr Color shirt{ blue };

    std::cout << shirt << '\n'; // Prints 1

    std::cout << getColor(shirt) << std::endl;

    return EXIT_SUCCESS;
}