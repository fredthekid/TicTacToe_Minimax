//
// Created by fred on 9/13/15.
//

#include "GameNode.h"
GameNode::GameNode(){
    x = 1;
    y = 1;
}
GameNode::GameNode(char board[3][3]){
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            current_board[y][x] = board[y][x];
        }
    }
}
void GameNode::SetX(int x_coord){
    x = x_coord;
}

void GameNode::SetY(int y_coord){
    y = y_coord;
}

void GameNode::SetScore(int s){
    score = s;
}

void GameNode::UpdateBoard(int x, int y, bool X_or_O){
    char symb = X_or_O?'X':'O';
    current_board[y][x] = symb;
}
int GameNode::GetX() {
    return x;
}
int GameNode::GetY(){
    return y;
}
int GameNode::GetScore() {
    return score;
}
