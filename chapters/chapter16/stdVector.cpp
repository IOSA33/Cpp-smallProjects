#include <iostream>
#include <vector>

template <typename T>
void passByRef(const T& arr) {
    std::cout << arr[0] << std::endl;
}

template <typename T>
void passTempalte(const std::vector<T> arr, int index) {
    if (index >= static_cast<int>(arr.size()) || index < 0) {
        std::cout << "Error";
    } else {
        std::cout << arr[index] << std::endl;
    }
}


int main() {
    std::vector prime{2, 3, 4};
    // There is no func for .length() as string has, only .size() for containers
    std::cout << prime.size() << std::endl;

    // Does not do runtime bounds checking
    std::cout << prime[2];
    // .at does runtime bounds checking
    std::cout << prime.at(2);

    std::vector<char> hello{'h', 'e', 'l', 'l', 'o'};
    std::cout << std::size(hello) << std::endl;
    std::cout << hello[1] << std::endl;
    std::cout << hello.at(1) << std::endl;

    // Right for loop
    std::size_t length{prime.size()};
    int average {0};
    for (std::size_t i {0}; i < length; i++) {
        average += prime[i];
    }
    average /= static_cast<int>(length);
    std::cout << average << std::endl;
}
