#include "tictactoe.h"
#include <list>
#include <string>
#include <iostream>
#include <bits/ostream.tcc>

void printTable(int arr[][3], int);
int updateTable(int arr[][3], int, int);

constexpr int rowsGame{3};

int main() {
    std:: cout << "Hello it is a mini game tic-tac-toe:"<< "\n";
    int array[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    printTable(array, rowsGame);

    while (true) {
        std::cout << "Enter a number for X and Y, format (0 2):" << "\n";
        int inputX{};
        int inputY{};
        std::cin >> inputX >> inputY;

        if (inputX >= 0 && inputY >= 0 && inputX < 3 && inputY < 3) {
            updateTable(array, inputX, inputY);
            printTable(array, rowsGame);
        } else {
            std::cout<< "Invalid input! Try again! \n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        break;
    }

    return 0;
}

void printTable(int arr[][3], const int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            std::cout << arr[i][j]<< " ";
        }
        std::cout << std::endl;
    }
}

int updateTable(int arr[][3], int inputX, int inputY) {
    if (inputX >= 0 && inputY >= 0 && inputX < 3 && inputY < 3) {
        return arr[inputX][inputY] = 1;
    }
    return 0;
}