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


    // Dangling pointer example.
    int* ptr6 {};
    {
        int newDanglingValue{12};
        ptr6 = &newDanglingValue;
    }  // ptr is now dangling and pointing to invalid object

    if (ptr) // condition evaluates to true because ptr is not nullptr
        std::cout << *ptr; // undefined behavior

    int v{5};
    int* ptr0 { &v };             // points to an "int" but is not const itself.  We can modify the value or the address.
    const int* ptr10 { &v };       // points to a "const int" but is not const itself.  We can only modify the address.
    int* const ptr20 { &v };       // points to an "int" and is const itself.   We can only modify the value.
    const int* const ptr30 { &v }; // points to a "const int" and is const itself.  We can't modify the value nor the address.

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