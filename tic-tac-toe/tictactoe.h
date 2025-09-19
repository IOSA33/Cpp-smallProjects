#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <vector>

void printTable(int arr[][3], int rows);
int updateTable(int arr[][3], int inputX, int inputY, int value);
bool checkInputArray(int arr[][3], int inputX, int inputY);
bool winCheck(int arr[][3], std::vector<std::vector<int>>& arrV, int inputX, int inputY, int currentPlayer);
bool infiniteCheck(int arr[][3]);

#endif //TICTACTOE_H
