//
// Created by vitaly on 18.10.2021.
//

#include <iostream>

#include "TicTacToe.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string sAnswer;
    do{
        TicTacToe TTTGame;
        while(!TTTGame.MakeTurn());

        std::cout << "Хотите сыграть ещё раз? (Д/н): ";
        std::cin >> sAnswer;
    }while(sAnswer == "Д" || sAnswer == "д" || sAnswer == "Y" || sAnswer == "y");

    return 0;
}