#include <iostream>


void passByPointer(const int* x) {
    std::cout << x[0];
}


int main() {
    constexpr int arr1[2] {1, 2};
    constexpr int arr2[4] {1, 2, 3, 4};

    const int* begin{arr1};
    const int* end{arr1 + std::size(arr1)};

    for (; begin != end; ++begin) {
        std::cout << *begin;
    }

    passByPointer(arr1);
    passByPointer(arr2);
}