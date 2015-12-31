//
// Created by fred on 9/13/15.
//

#include "TicTacToe.h"

//X ALWAYS GOES FIRST
//O GOES SECOND

TicTacToe::TicTacToe() {
    humanFirst = true;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = 'c';
        }
    }
}

int TicTacToe::StateMachine() {
    //1: human turn
    //2: computer turn
    //3: human wins
    //4: computer wins
    //5: cats game

    int state = humanFirst? 1:2;
    m_GameBoard.printBoard();
    while(state < 6){
        switch(state){
            case 1:
                getHumanInput();
                state = UpdateState(state);
                m_GameBoard.printBoard();
                break;
            case 2:
                ComputerMakeMove();
                state = UpdateState(state);
                m_GameBoard.printBoard();
                break;
            case 3:
                human_win_msg();
                state = 6;
                break;
            case 4:
                comp_win_msg();
                state = 6;
                break;
            case 5:
                cats_game_msg();
                state = 6;
                break;
        }
    }
}

bool TicTacToe::run(int humanturn){
    if(humanturn == 1) humanFirst = true;
    else humanFirst = false;
    StateMachine();
}

int TicTacToe::UpdateState(int CurrentState){
    //CurrentState == 1: Human just moved;
    //CurrentState == 0:
    int winner = checkWinner(board);
    if(!AvailableMoves(board) && winner == 0 ) return 5;
    switch(winner){
        case 0:
            return CurrentState == 1? 2: 1;
        case 10:
            return humanFirst?3:4;
        case -10:
            return humanFirst?4:3;
        default:
            cout << "error" << endl;
    }

    //code shouldnt reach here;
    return -1;
}

void TicTacToe::printBoard(char printthis [3][3] ) {
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            cout << printthis[y][x];
        }
        cout << endl;
    }
    cout << endl << endl;
}


//humanFirst == true, computer should minimize
//humanFirst == false, computer should maximize


GameNode TicTacToe::MiniMax(GameNode& Node, bool humanOrComputer){ //humanOrComputer: true == human move, false = computer move
    if(!AvailableMoves(Node.current_board)){
        if(checkWinner(Node.current_board) == 10){
            Node.SetScore(10);
            return Node;
        }

        if(checkWinner(Node.current_board) == -10){
            Node.SetScore(-10);
            return Node;
        }

        if(checkWinner(Node.current_board) == 0){
            Node.SetScore(0);
            return Node;
        }
    }
    vector<GameNode> scores;
    for(int y = 0; y < 3; y ++){
        for(int x = 0; x < 3; x++){
            GameNode ComputerMove(Node.current_board);
            //cout << Node.current_board[y][x] << endl;
            if(Node.current_board[y][x] == 'c'){
                ComputerMove.SetX(x);
                ComputerMove.SetY(y);

                //HUMAN MOVE
                if(humanOrComputer == true) ComputerMove.UpdateBoard(x,y, humanFirst);
                //COMPUTER MOVE
                else ComputerMove.UpdateBoard(x,y, !humanFirst);
                ComputerMove.SetScore(MiniMax(ComputerMove,!humanOrComputer).GetScore());
                scores.push_back(ComputerMove);
            }
        }
    }

    //return min or max depending on if computer or human went first
    GameNode Min;
    Min.SetScore(1000);
    GameNode Max;
    Max.SetScore(-1000);
    for(int i = 0; i < scores.size(); i++){
        if(scores[i].GetScore() > Max.GetScore()) Max = scores[i];
        if(scores[i].GetScore() < Min.GetScore()) Min = scores[i];
    }

    if(humanOrComputer == true){
        if(humanFirst) return Max;
        else return Min;
    }
    else {
        if(humanFirst) return Min;
        else return Max;
    }
}


bool TicTacToe::AvailableMoves(char curr_board[3][3]){
    if(checkWinner(curr_board) != 0) {
        return false;
    }
    for(int i = 0; i < 3; i++){
        for(int j =0; j < 3; j++){
            if(curr_board[i][j] == 'c') return true;
        }
    }
    return false;
}

void TicTacToe::getHumanInput(){

    int x = 0;
    int y = 0;
    do{
        x = getHumanXCoord();
        y = getHumanYCoord();
    }while(boardCollision(x,y));
    m_GameBoard.insert(x,y,humanFirst);
    char x_o = humanFirst?'X':'O';
    board[y-1][x-1] = x_o;
}

void TicTacToe::ComputerMakeMove() {
    GameNode ComputerMove(board);
    ComputerMove = MiniMax(ComputerMove, false);
    m_GameBoard.insert(ComputerMove.GetX()+1,ComputerMove.GetY()+1,!humanFirst);
    char x_o = !humanFirst?'X':'O';
    board[ComputerMove.GetY()][ComputerMove.GetX()] = x_o;
}
bool TicTacToe::boardCollision(int x, int y){
    if(board[y-1][x-1] != 'c') {
        cout << endl << "OMG U NUB!! THERES A MARK THERE ALREADY!!" << endl << endl;
        return true;
    }
    else return false;
}
int TicTacToe::getHumanXCoord(){
    int x = 0;
    cout << "Where would you like to move?" << endl;
    cout << "Enter Column: ";
    cin >> x;
    while(x > 3 || x < 1){
        cout << "Stop being a bum, where would you like to move?" << endl;
        cout << "Enter Column (1-3): ";
        cin >> x;
    }
    return x;
}
int TicTacToe::getHumanYCoord(){
    int y = 0;
    cout << "Enter row: ";
    cin >> y;
    while(y > 3 || y < 1){
        cout << "sdfjk;l LEGGO, where would you like to move?" << endl;
        cout << "Enter row (1-3): ";
        cin >> y;
    }
    return y;
}
int TicTacToe::checkWinner(char currBoard[3][3]){
    //return 10: X wins;
    //return -10: O Wins;
    //return 0: no winner
    char symb = 'c';

    //Check Horizontals and Verticals
    for(int i = 0; i < 3; i++){
        if(currBoard[i][0] == currBoard[i][1] && currBoard[i][1] == currBoard[i][2] && currBoard[i][0] != 'c') symb = currBoard[i][0];
        if(currBoard[0][i] == currBoard[1][i] && currBoard[1][i] == currBoard[2][i] && currBoard[i][0] != 'c') symb = currBoard[0][i];
    }

    //Check Diagonals
    if(currBoard[0][0] == currBoard[1][1] && currBoard[1][1] == currBoard[2][2] && currBoard[0][0] != 'c') symb = currBoard[0][0];
    if(currBoard[2][0] == currBoard[1][1] && currBoard[1][1] == currBoard[0][2] && currBoard[2][0] != 'c') symb = currBoard[2][0];

    switch(symb){
        case 'X':
            return 10;
        case 'O':
            return -10;
        default:
            return 0;
    }
}
void TicTacToe::human_win_msg(){
    cout << endl <<  "You pretty good doe..."  << endl;
}
void TicTacToe::comp_win_msg(){
    cout << endl <<  "HAH YOURE A NUB! >:)"  << endl;
}
void TicTacToe::cats_game_msg(){
    cout << endl <<  "MEOW MEOW MEOW! ^_^"  << endl;
}
