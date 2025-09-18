#include "tictactoe.h"
#include <iostream>
#include <bits/ostream.tcc>
#include <random>
#include <ctime>


void printTable(int arr[][3], int rows);
int updateTable(int arr[][3], int inputX, int inputY, int value);

constexpr int rowsGame{3};
constexpr int valuePlayer{1};
constexpr int valueRobot{5};

int main() {
    std:: cout << "Hello it is a mini game tic-tac-toe:"<< "\n";

    // Array of our map game
    int array[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    printTable(array, rowsGame);

    while (true) {
        std::cout << "Enter a number for X and Y, format (0 2):" << "\n";
        // User inputs
        int inputX{};
        int inputY{};
        std::cin >> inputX >> inputY;

        // Game starts
        if (inputX >= 0 && inputY >= 0 && inputX < 3 && inputY < 3) {
            // Users move, and print table after input
            updateTable(array, inputX, inputY , valuePlayer);
            printTable(array, rowsGame);

            // For robot inputs
            int inputX1{};
            int inputY2{};

            // Random generator for robot by random library
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, 2);

            inputX1 = dist(gen);
            inputY2 = dist(gen);

            // Updating table and printing it again
            std::cout << "Robot makes move" << std::endl;
            std::cout << "My move is " << inputX1 << " " << inputY2 << "\n";

            updateTable(array, inputX1, inputY2, valueRobot);
            printTable(array, rowsGame);
        } else {
            std::cout<< "Invalid input! Try again! \n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        if (inputX == 10 || inputY == 10) {
            break;
        }
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

int updateTable(int arr[][3], const int inputX, const int inputY, int value) {
    if (inputX >= 0 && inputY >= 0 && inputX < 3 && inputY < 3) {
        return arr[inputX][inputY] = value;
    }
    return 0;
}