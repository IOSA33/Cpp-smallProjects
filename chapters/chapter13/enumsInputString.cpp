#include <iostream>
#include <string_view>
#include <optional>
#include <string>

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

constexpr std::optional<Color> getColorFromString(std::string_view color) {
    if (color == "black") return black;
    if (color == "blue") return blue;
    if (color == "red") return red;
    return {};
}

int main() {
    constexpr Color shirt{ blue };
    std::cout << shirt << '\n'; // Prints 1
    std::cout << getColor(shirt) << std::endl; // Prints blue

    int input{};
    // std::cin >> input;
    if (input < 0 || input > 2) {
        std::cout << "Wrong integer" << '\n';
    } else {
        Color tshirt{ static_cast<Color>(input) };
        std::cout << getColor(tshirt) << '\n';
    }

    std::string inputString{};
    std::cin >> inputString;
    std::optional<Color> color {getColorFromString(inputString)};
    if (color) {
        std::cout << "You entered an: " << getColor(*color) << '\n';
    } else {
        std::cout << "You entered an invalid string input" << '\n';
    }

    return EXIT_SUCCESS;
}