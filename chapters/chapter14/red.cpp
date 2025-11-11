#include <iostream>
#include <cmath>
#include <functional>

constexpr double tolerance = 0.00001;

template <typename F>
double fixedPoint(const F& func, double firstGuess) {
    auto close_enough = [](double v1, double v2) {
        return std::abs(v1 - v2) < tolerance;
    };

    std::function<double(double)> tryRecursive; // lambda recursion

    tryRecursive =[&](double guess) -> double {
        double next = func(guess);
        std::cout << guess << ": guess , next: " << next << std::endl;
        if (close_enough(guess, next)) {
            return next;
        }
        return tryRecursive(next);
    };

    return tryRecursive(firstGuess);
}

template <typename F>
double fixedPoint1(const F& func, double firstGuess) {
    auto close_enough = [](double v1, double v2) {
        return std::abs(v1 - v2) < tolerance;
    };

    double guess = firstGuess;
    while (true) {
        double next = func(guess);
        std::cout << guess << ": guess , next: " << next << std::endl;
        if (close_enough(guess, next)) {
            return next;
        }
        guess = next;
    }
}

int main() {
    auto result = fixedPoint([](double y){return std::sin(y) + std::cos(y);}, 1);
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}