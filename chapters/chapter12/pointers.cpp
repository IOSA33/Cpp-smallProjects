#include <iostream>





int main() {
    int x{5};
    int& ref{x};
    int* ptr;
    int* ptr2{ nullptr }; // NUll pointer, best practice
    int* ptr3{&x};

    int* ptr4 {&x};
    ptr4 = nullptr;

    // explicit test for equivalence
    if (ptr2 == nullptr || ptr3 == nullptr)
        std::cout << "ptr is null\n";
    else
        std::cout << "ptr is non-null\n";

    if (!ptr2) // Boolean value
        std::cout << "ptr is non-null\n";


    std::cout << &x << std::endl;
    std::cout << ref << std::endl;
    std::cout << ptr2 << std::endl;
    std::cout << ptr3 << std::endl;
    //  Dereferencing a pointer means
    //  “go to the address the pointer is pointing at
    //  and access the value there”
    std::cout << *ptr3 << std::endl;

    return 0;
}