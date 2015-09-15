//
// Created by fred on 9/13/15.
//

#ifndef TICTACTOE_GAMENODE_H
#define TICTACTOE_GAMENODE_H


class GameNode {
public:
    GameNode();
    GameNode(char board[3][3]);
    void UpdateBoard(int x, int y, bool X_or_O); //true = X, false = O;
    int GetX();
    int GetY();
    int GetScore();
    void SetX(int x_coord);
    void SetY(int y_coord);
    void SetScore(int);
    char current_board[3][3];
private:
    int x;
    int y;
    int score;
};


#endif //TICTACTOE_GAMENODE_H
