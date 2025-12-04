#include <iostream>
#include <vector>

std::vector<int> bits(const size_t n) {
    std::vector<int> vec(n+1, 0);

    for (int i = 0; i < vec.size(); ++i) {
        size_t a = i;
        while(a != 0) {
            if (a % 2 != 0) {
                vec[i]++;
            }
            a /= 2;
        }
    }

    return vec;
}

int main() {
    std::vector<int> vec = bits(5);

    for (const auto& i: vec) {
        std::cout << i << ", ";
    }
}