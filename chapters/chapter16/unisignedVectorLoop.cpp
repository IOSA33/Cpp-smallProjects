#include <iostream>
#include <vector>

template<typename T>
void printReverse(const std::vector<T>& vec) {
    for (int index{static_cast<int>(vec.size()) - 1}; index >= 0; --index) {
        std::cout << vec[static_cast<std::size_t>(index)] << " ";
    }
    std::cout << std::endl;
}

int main() {
    return 0;
}