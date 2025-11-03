#include <iostream>
#include <utility>

int main() {
    enum class Color {
        red, // red is considered part of Color's scope region
        blue,
        yellow,
    };

    enum class Fruit {
        apple,
        banana,
    };

    Color color {Color::red};
    Fruit fruit{Fruit::apple};
    // compile error: the compiler doesn't know how to
    // compare different types Color and Fruit
    //if (color == fruit)
        std::cout << "color and fruit are equal\n";
    //else
        std::cout << "color and fruit are not equal\n";

    std::cout << static_cast<int>(color) << '\n';
    std::cout << std::to_underlying(fruit) << '\n'; // c++ 23

    return EXIT_SUCCESS;
}