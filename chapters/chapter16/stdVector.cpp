#include <iostream>
#include <vector>


void passByRef(const std::vector<int>& arr) {
    std::cout << arr[0] << std::endl;
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
}
