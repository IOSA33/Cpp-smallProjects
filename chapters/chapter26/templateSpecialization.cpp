#include <iostream>

template<typename T>
void print(const T& t) {
    std::cout << t << '\n';
}

template<>
void print<double>(const double& d) {
    std::cout << std::scientific << d << '\n';
}

int main() {
    print(3);
    print(53.53);
}