#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main() {
    TicTacToe Game;
    int humanFirst = 0;
    cout << "Do you want to go 1st or 2nd? (Enter 1 or 2)"<< endl;
    cin >> humanFirst;
    humanFirst = humanFirst%2;
    Game.run(humanFirst);
}