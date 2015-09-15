//
// Created by fred on 9/13/15.
//

#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H

#include"GameBoard.h"
#include"GameNode.h"
#include<iostream>
#include<vector>
using namespace std;

class TicTacToe {
public:
    TicTacToe();
    bool run(int humanturn);

private:

    //Variables
    GameBoard m_GameBoard;
    char board[3][3];
    bool humanFirst;

    //Human Input Functions
    int getHumanXCoord();
    int getHumanYCoord();
    void getHumanInput();

    //AI Functions
    GameNode MiniMax(GameNode&, bool);
    void ComputerMakeMove();

    //Game State Functions
    int StateMachine();
    bool AvailableMoves(char curr_board[3][3]);
    int checkWinner(char currBoard[3][3]);
    int UpdateState(int);
    bool boardCollision(int x, int y);

    //Display Messages
    void human_win_msg();
    void comp_win_msg();
    void cats_game_msg();

    //Test Functions
    void printBoard(char printthis [3][3]);
};


#endif //TICTACTOE_TICTACTOE_H
