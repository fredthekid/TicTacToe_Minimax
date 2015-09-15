//
// Created by fred on 9/13/15.
//
#include<iostream>
#include "GameBoard.h"
using namespace std;
GameBoard::GameBoard(){
    m_InitGameBoard();
};

void GameBoard::m_InitGameBoard(){
    m_DisplayBoard[0] = "    1     2     3  ";
    m_DisplayBoard[1] = "       |     |     ";
    m_DisplayBoard[2] = "1      |     |     ";
    m_DisplayBoard[3] = "  _____|_____|_____";
    m_DisplayBoard[4] = "       |     |     ";
    m_DisplayBoard[5] = "2      |     |     ";
    m_DisplayBoard[6] = "  _____|_____|_____";
    m_DisplayBoard[7] = "       |     |     ";
    m_DisplayBoard[8] = "3      |     |     ";
    m_DisplayBoard[9] = "       |     |     ";
}

bool GameBoard::m_checkIfEmpty(int x, int y){
    if(m_DisplayBoard[y][x] == ' ') return true;
    else return false;
}

int GameBoard::m_getXCoord(int x) {
    switch(x){
        case 1:
            return 4;
            break;
        case 2:
            return 10;
            break;
        case 3:
            return 16;
            break;
        default:
            cout << "Error in X Coordinate" << endl;
            return -1;
    }
}

int GameBoard::m_getYCoord(int y){
    switch(y){
        case 1:
            return 2;
            break;
        case 2:
            return 5;
            break;
        case 3:
            return 8;
            break;
        default:
            cout << "Error in Y Coordinate" << endl;
            return -1;
    }
}

bool GameBoard::insert(int x, int y, bool x_or_o) {
    int x_coord = m_getXCoord(x);
    int y_coord = m_getYCoord(y);
    if(!m_checkIfEmpty(x_coord,y_coord)) return false;
    char in = (x_or_o) ? 'X' : 'O';
    m_DisplayBoard[y_coord][x_coord] = in;
}

void GameBoard::printBoard(){
    cout << endl;
    for(int i = 0; i < 10; i++){
        cout << m_DisplayBoard[i] << endl;
    }
    cout << endl;
}