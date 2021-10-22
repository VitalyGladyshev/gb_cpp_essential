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

    do {
        TTTGame.MakeTurn();
    } while(false);

    return 0;
}