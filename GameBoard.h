//
// Created by fred on 9/13/15.
//

#ifndef TICTACTOE_GAMEBOARD_H
#define TICTACTOE_GAMEBOARD_H

#include<vector>
#include<string>
using namespace std;
class GameBoard {
public:
    GameBoard();
    bool insert(int row, int column, bool x_or_o); //x: true, o: false
    void printBoard();

private:
    string m_DisplayBoard[10];
    bool m_checkIfEmpty(int x, int y);
    int m_getXCoord(int x);
    int m_getYCoord(int y);
    void m_InitGameBoard();
};


#endif //TICTACTOE_GAMEBOARD_H
