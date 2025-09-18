#include "tictactoe.h"
#include <list>
#include <string>
#include <iostream>
#include <bits/ostream.tcc>

void printTable(int arr[][3]);
int updateTable(int arr[][3], int, int);

int main() {
    std:: cout << "Hello it is a mini game tic-tac-toe:"<< "\n";

    int array[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};

    while (true) {
        std::cout << "Enter a number for X and Y, format (3 3):" << "\n";

        printTable(array);

        int inputX{};
        int inputY{};
        std::cin >> inputX >> inputY;

        if (inputX >= 0 && inputY >= 0 && inputX < 4 && inputY < 4) {
            updateTable(array, inputX, inputY);
            printTable(array);

        } else {
            std::cout<< "Invalid input! Try again! \n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        break;
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

int updateTable(int* arr[][3], int inputX, int inputY) {


    return 0;
}