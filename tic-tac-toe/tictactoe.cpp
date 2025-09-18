#include "tictactoe.h"
#include <iostream>
#include <bits/ostream.tcc>
#include <random>

void printTable(int arr[][3], int rows);
int updateTable(int arr[][3], int inputX, int inputY, int value);
bool checkInputArray(int arr[][3], int inputX, int inputY);

constexpr int rowsGame{3};
constexpr int valuePlayer{1};
constexpr int valueRobot{5};

constexpr int outOfArrayX{0};
constexpr int outOfArrayY{0};
constexpr int outOfArrayX1{3};
constexpr int outOfArrayY1{3};

constexpr int exitGameX{10};
constexpr int exitGameY{10};


int main() {
    std:: cout << "Hello it is a mini game tic-tac-toe:"<< "\n";

    // Array of our map game
    int array[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    printTable(array, rowsGame);

    while (true) {
        // User inputs
        int inputX{};
        int inputY{};

        do {
            std::cout << "Enter a number for X and Y, format (0 2):" << "\n";
            std::cin >> inputX >> inputY;
        } while (!checkInputArray(array, inputX, inputY));

        // Game starts
        if (inputX >= outOfArrayX && inputY >= outOfArrayY && inputX < outOfArrayX1 && inputY < outOfArrayY1) {
            // Users move, and print table after input
            updateTable(array, inputX, inputY , valuePlayer);
            printTable(array, rowsGame);

            // For robot inputs
            int inputX1{};
            int inputY2{};

            std::cout << "Robot thinking!\n";
            // Check for robots input
            do {
                std::cout << "Robot thinking again!\n";
                // Random generator for robot by random library
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dist(0, 2);

                inputX1 = dist(gen);
                inputY2 = dist(gen);
            } while (!checkInputArray(array, inputX1, inputY2));

            // Updating table and printing it again
            std::cout << "Robot makes move" << std::endl;
            std::cout << "My move is " << inputX1 << " " << inputY2 << "\n";

            // TODO: Check for winning

            updateTable(array, inputX1, inputY2, valueRobot);
            printTable(array, rowsGame);

            // TODO: Check for winning

        } else {
            std::cout<< "Invalid input! Try again! \n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        // For exit the game
        if (inputX == exitGameX || inputY == exitGameY) {
            break;
        }
    }

    return EXIT_SUCCESS;
}

// Printing current state of the game (array) for console
void printTable(int arr[][3], const int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            std::cout << arr[i][j]<< " ";
        }
        std::cout << std::endl;
    }
}

// Updating table after users and robots input
int updateTable(int arr[][3], const int inputX, const int inputY, int value) {
    if (inputX >= 0 && inputY >= 0 && inputX < 3 && inputY < 3) {
        return arr[inputX][inputY] = value;
    }
    return 0;
}

// Checking is robots move is on top
bool checkInputArray(int arr[][3], const int inputX, const int inputY) {
    if (arr[inputX][inputY] == 1 || arr[inputX][inputY] == 5) {
        return false;
    }
    return true;
}

