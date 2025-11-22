#include <iostream>
#include <vector>

// Good option, but in the main the best
template<typename T>
void printReverse(const std::vector<T>& vec) {
    for (int index{static_cast<int>(vec.size()) - 1}; index >= 0; --index) {
        std::cout << vec[static_cast<std::size_t>(index)] << " ";
    }
    std::cout << std::endl;
}


//     --------------- Best practise ---------------
// Avoid array indexing with integral values whenever possible.


int main() {
    using Index = std::ptrdiff_t;

    std::vector<int> arr{9,7,5,3,2,5};

    // Best option for forloop indexing
    auto length{static_cast<Index>(arr.size())};
    for (auto index{ length - 1}; index >= 0; --index) {
        // Since data() returns the array data as a C-style array,
        // and C-style arrays allow indexing with both signed and
        // unsigned values, this avoids sign conversion issues.
        std::cout << arr.data()[index] << std::endl;
    }

    return 0;
}