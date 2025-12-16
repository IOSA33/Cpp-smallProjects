#include <iostream>
#include <vector>

size_t bits(size_t n) {
    size_t res{};

    while(n != 0) {
        if (n % 2 != 0) {
            ++res;
        }
        n >>= 1;
    }
    
    return res;
}

int main() {
    std::cout << bits(2147483645);
}