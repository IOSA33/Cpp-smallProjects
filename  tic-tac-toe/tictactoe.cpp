#include "tictactoe.h"
#include <list>
#include <string>
#include <iostream>
#include <bits/ostream.tcc>



int main() {
    std:: cout << "Hello it it a mini game tic-tac-toe:"<< "\n";

    int outer{1};
    int inner{2};

    int cars[] = {(1,2,3), (1,2,3), (1,2,3)};

    while (true) {

        int inputX{};
        int inputY{};

        std::cout << "Enter a number for X:" << "\n";

        std::cin >> inputX;

        while (outer <= 3) {
            std::cout << "X" << " ";
            while (inner >= 1) {
                std::cout << "Y" << " ";
                --inner;
            }
            std::cout << std::endl;
            inner = 2;
            outer++;
        }

        if (inputX == 0 || !inputX) {
            break;
        }
    }

    return 0;
}

void printTable (int arr[]) {
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        for (int j = 0; j < size; j++) {
            std::cout << arr[j] << " ";
        }
    }
}

int changeTable(int* arr[]) {
    return 0;
}