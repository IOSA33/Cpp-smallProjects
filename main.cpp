#include <iostream>
#include "vec3.h"




int main() {
    int outer{ 1 };

    std::cout << "Enter a x_side:" << "\n";
    int x_side{};
    std::cin >> x_side;

    std::cout << "Enter a y_side:" << "\n";
    int y_side{};
    std::cin >> y_side;

    while (outer <= x_side) {
        int inner = y_side;

        while (inner >= 1) {
            if (inner > outer) {
                if (inner <= 9) {
                    std::cout << "X" << " ";
                } else {
                    std::cout << "XX" << " ";
                }
            } else if (
                inner == outer) {
                std::cout << inner << " ";
            } else if (inner < outer) {
                while (inner >= 1) {
                    std::cout << inner << " ";
                    inner--;
                }
            }
            if (inner <= 1) { std::cout << "\n"; }
            --inner;
        }
        ++outer;
    }
    return 0;
}