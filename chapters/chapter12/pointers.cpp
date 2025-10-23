#include <iostream>





int main() {
    int x{5};
    int& ref{x};
    int* ptr;
    int* ptr2{ nullptr }; // NUll pointer, best practice
    int* ptr3{&x};

    int* ptr4 {&x};
    ptr4 = nullptr;

    someFunction(nullptr);

    std::cout << &x << std::endl;
    std::cout << ptr << std::endl;
    std::cout << ptr2 << std::endl;
    std::cout << ptr3 << std::endl;
    std::cout << *ptr3 << std::endl;

    return 0;
}