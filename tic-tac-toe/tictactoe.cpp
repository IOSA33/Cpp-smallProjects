#include "tictactoe.h"
#include <iostream>
#include <bits/ostream.tcc>
#include <random>

constexpr int rowsGame{3};
constexpr int valuePlayer{1};
constexpr int valueRobot{5};

constexpr int outOfArrayX{0};
constexpr int outOfArrayY{0};
constexpr int outOfArrayX1{3};
constexpr int outOfArrayY1{3};

constexpr int exitGameX{10};
constexpr int exitGameY{10};

// Command for compile: "g++ tictactoe.cpp tictactoeLogic.cpp -o tictactoe.exe"
// Command for run (Needs to be in a folder): "./tictactoe.exe"
int main() {
    std::cout << "Hello it is a mini game tic-tac-toe:"<< "\n";

    // Array of our map game
    int array[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    printTable(array, rowsGame);

    while (true) {
        // User inputs
        int inputX{};
        int inputY{};

        if (const int winner{winCheck(array, valuePlayer)}) {
            std::cout << "And winner is: NUMBER" << " " << winner << std::endl;
            break;
        }

        do {
            std::cout << "Enter a number for X and Y, example (0 2):" << "\n";
            std::cin >> inputX >> inputY;
        } while (!checkInputArray(array, inputX, inputY));

        if (const int winner{winCheck(array, valuePlayer)}) {
            std::cout << "And winner is: NUMBER" << " " << winner << std::endl;
            break;
        }

        // Game starts
        if (inputX >= outOfArrayX && inputY >= outOfArrayY && inputX < outOfArrayX1 && inputY < outOfArrayY1) {
            // Users move, and print table after input
            updateTable(array, inputX, inputY , valuePlayer);
            printTable(array, rowsGame);

            // Checking if table is full
            if (isFull(array)) {
                std::cout << "Table is full" << std::endl;
                break;
            }

            if (const int winner{winCheck(array, valuePlayer)}) {
                std::cout << "And winner is: NUMBER" << " " << winner << std::endl;
                break;
            }

            // For robot inputs
            int inputX1{};
            int inputY2{};

            // Check for robots input
            do {
                std::cout << "Robot thinking!\n";
                // Random generator for robot by random library
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dist(0, 2);

                inputX1 = dist(gen);
                inputY2 = dist(gen);
            } while (!checkInputArray(array, inputX1, inputY2));

            // Updating table and printing it again
            std::cout << "Robot makes move: " << "My move is (" << inputX1 << ", " << inputY2 << "):" << std::endl;

            updateTable(array, inputX1, inputY2, valueRobot);
            printTable(array, rowsGame);

            if (const int winner{winCheck(array, valueRobot)}) {
                std::cout << "And winner is: NUMBER" << " " << winner << std::endl;
                break;
            }
        } else {
            std::cout<< "Invalid input! Try again! \n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        // For exit the game
        if (inputX == exitGameX || inputY == exitGameY) {
            std::cout << "Thanks for playing!" << std::endl;
            break;
        }
    }

    return EXIT_SUCCESS;
}