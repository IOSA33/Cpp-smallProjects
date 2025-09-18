#include "tictactoe.h"
#include <list>
#include <string>
#include <iostream>
#include <bits/ostream.tcc>

void printTable(int arr[][3]);

int main() {
    std:: cout << "Hello it is a mini game tic-tac-toe:"<< "\n";

    int array[3][3] = {{1,2,3}, {1,2,3}, {1,2,3}};
    while (true) {

        int inputX{};
        int inputY{};

        std::cout << "Enter a number for X:" << "\n";

        std::cin >> inputX;

        printTable(array);

        if (inputX == 0 || !inputX) {
            break;
        }
    }

    return 0;
}

void printTable(int arr[][3]) {
    int size = sizeof(arr) / sizeof(arr[0][0]);

    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            std::cout << arr[i][j]<< " ";
        }
        std::cout << std::endl;
    }
}

int changeTable(int* arr[]) {
    return 0;
}