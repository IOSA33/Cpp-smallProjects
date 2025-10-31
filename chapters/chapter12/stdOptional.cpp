#include <iostream>
#include <optional>

std::optional<int> doIntDivision(int x, int y) {
    if (y == 0) {
        return {};
    }

    return x/y;
}

void printIDNumber(const std::optional<const int> id = std::nullopt) {
    if (id)
        std::cout << "Your ID number is " << id.value() << ".\n";
    else
        std::cout << "Your ID number is not known.\n";
}

int main () {
    std::optional<int> result1 {doIntDivision(20, 5)};

    if (result1) {
        std::cout << "Result 1: " << *result1 << '\n';
    } else {
        std::cout << "Result 1: failed \n";
    }

    std::optional<int> result2 { doIntDivision(5, 0) };

    if (result2)
        std::cout << "Result 2: " << *result2 << '\n';
    else
        std::cout << "Result 2: failed\n";

    const int id { 34 };
    printIDNumber();
    printIDNumber(id);

    return 0;
}