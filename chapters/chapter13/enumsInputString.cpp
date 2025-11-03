#include <iostream>
#include <limits>
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

constexpr std::optional<Color> getColorFromString(const std::string_view color) {
    if (color == "black") return black;
    if (color == "blue") return blue;
    if (color == "red") return red;
    return {};
}

std::ostream& operator<<(std::ostream& out, Color color) {
    out << getColor(color);
    return out;
}

std::istream& operator>>(std::istream& in, Color& color) {
    std::string s{};
    in >> s;

    std::optional<Color> match { getColorFromString(s)};
    if (match) {
        color = *match;
        return in;
    }

    in.setstate(std::ios_base::failbit);

    return in;
}

int main() {
    constexpr Color shirt{ blue };
    // Prints 1, after operator<< overload "blue"
    std::cout << shirt << '\n';
    std::cout << getColor(shirt) << std::endl; // Prints blue

    int input{};
    std::cin >> input;
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

    std::cout << "Enter a pet: cat, dog, pig, or whale: ";
    Color color1{};
    std::cin >> color1;

    if (std::cin) // if we found a match
        std::cout << "You chose: " << getColor(color1) << '\n';
    else
    {
        std::cin.clear(); // reset the input stream to good
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Your pet was not valid\n";
    }

    return EXIT_SUCCESS;
}