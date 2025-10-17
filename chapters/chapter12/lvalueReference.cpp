#include <iostream>

int main() {
    int x{5};
    int& ref {x};
    int ref1 {x};

    // Invalid: non const lvalue reference cant bind to an r value
    // int& invalidRed {0};

    ref = 10;

    std::cout << x << ":" << ref << ":" << ref1 << std::endl;
}