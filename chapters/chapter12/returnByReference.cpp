#include <iostream>

// The returning value we cannot change via reference
const int& maxConst(const int& x, const int& y) {
    return (x > y) ? x : y;
}

// In this case we can, no const
int& max(int& x, int& y) {
    return (x > y) ? x : y;
}

int main() {
    int a{5};
    int b{8};

    maxConst(a,b);
    std::cout << a << b << std::endl;

    max(a,b) = 7;
    std::cout << a << b << std::endl;
}