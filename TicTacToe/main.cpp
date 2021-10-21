//
// Created by vitaly on 18.10.2021.
//

#include <iostream>

#include "TicTacToe.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    TicTacToe TTTGame;

    TTTGame.PrintField();
    TTTGame.PrintField();

    return 0;
}