#include "tictactoe.h"
#include <iostream>
#include <bits/ostream.tcc>
#include <vector>

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

// Check is anyone won or not
bool winCheck(int arr[][3], const int currentPlayer) {
    // Check win for rows
    for (int row = 0; row < 3; ++row) {
        int sumCounter{0};
        for (int i = 0; i < 3; i++) {
             if (arr[row][i] == currentPlayer) {
                ++sumCounter;
             }
        }
        if (sumCounter == 3) {
            return true;
        }
    }

    // Check win for columns
    for (int column = 0; column < 3; ++column) {
        int sumCounter{0};
        for (int i = 0; i < 3; i++) {
            if (arr[i][column] == currentPlayer) {
                ++sumCounter;
            }
        }
        if (sumCounter == 3) {
            return true;
        }
    }

    return false;
}

// Infinite loop check for Robot and Player
bool infiniteCheck(int arr[][3]) {
    return false;
}

int nullifyVector(std::vector<std::vector<int>>& arrV) {
    return 0;
}