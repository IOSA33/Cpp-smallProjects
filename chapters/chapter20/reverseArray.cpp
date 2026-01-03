#include <iostream>
#include <vector>

template<typename T>
void readReverse(const std::vector<T> vec) {
    auto length {std::ssize(vec)};
    for (auto i {length - 1}; i >= 0; --i){
        std::cout << vec[static_cast<size_t>(i)] << '\n'; 
    }
}


int countNegatives(std::vector<std::vector<int>>& grid) {
    int result{};
    auto lengthI {std::ssize(grid)};
    auto lengthJ {std::ssize(grid[0])};
    for (auto i {lengthI - 1}; i >= 0; --i) {
        for (auto j {lengthJ - 1}; j >= 0; --j) {
            if (grid[static_cast<size_t>(i)][static_cast<size_t>(j)] >= 0) {
                break;
            } else {
                ++result;
            }
        }
    }

    return result;
}

int main() {

}