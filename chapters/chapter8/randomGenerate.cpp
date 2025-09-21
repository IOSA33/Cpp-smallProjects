#include <iostream>
#include <bits/ostream.tcc>

int plusOne() {
    static int s_state{3};

    ++s_state;
    return s_state;
}


int main() {
    std::cout << plusOne() << std::endl;
    std::cout << plusOne() << std::endl;
    std::cout << plusOne() << std::endl;

    return EXIT_SUCCESS;
}