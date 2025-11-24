#include <algorithm>
#include <random>
#include <iostream>
#include <vector>

namespace MinMax{
    constexpr int max = 100;
    constexpr int min = 0;
    constexpr int vecSize = 100;
    constexpr int tests = 10;
};

bool binarySearchVector(const std::vector<int>& v, const int value) {
    int left { 0 };
    int right { static_cast<int>(v.size()) - 1 };
    
    int count { 0 };
    
    std::cout << "Searching for a value: " << value << '\n';

    while (left <= right) {
        const int mid = (right + left) / 2;
        ++count;

        if (v[mid] == value) {
            std::cout << "Binary Search count: " << count << '\n';
            std::cout << "Value Founds! \n";
            return true;
        }
        if (v[mid] > value)
            right = mid - 1;

        else {
            left = mid + 1;
        }
    }
    std::cout << "Binary Search count: " << count << '\n';
    std::cout << "Value Not Found! \n";
    return false;
}

int main() {
    std::random_device rd; // non-deterministic generator
    std::mt19937 gen(rd()); // to seed mersenne twister
    std::uniform_int_distribution<> dist(MinMax::min, MinMax::max); // distribute results between 0 and 1000
    
    std::vector<int> vec{};
    vec.reserve(MinMax::vecSize);

    for (int i{0}; i < MinMax::vecSize; ++i) {
        vec.emplace_back(dist(gen));
    }

    std::ranges::sort(vec);

    std::cout << "Vector length is: " << vec.size() << '\n';
    std::cout << '\n';
    
    for (int i{ 1 }; i <= MinMax::tests; ++i) {
        std::cout << "Test number: " << i << '\n';
        binarySearchVector(vec, dist(gen));
        std::cout << std::endl;
    }
    
    return 0;
}
