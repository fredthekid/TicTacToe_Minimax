cmake_minimum_required(VERSION 3.2)
project(TicTacToe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(TicTacToe ${SOURCE_FILES} TicTacToe.cpp TicTacToe.h GameNode.cpp GameNode.h GameBoard.cpp GameBoard.h)