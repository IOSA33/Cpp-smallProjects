cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled algorithms/matriceXbyY.cpp
        chapters/chapter8/doWhile.cpp
        experiments/pattern_print.cpp
        chapters/chapter8/while.cpp)

add_executable(tictactoe
        tic-tac-toe/tictactoe.cpp
        tic-tac-toe/tictactoeLogic.cpp)
