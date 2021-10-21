//
// Created by vitaly on 18.10.2021.
//

#ifndef GB_CPP_ESSENTIAL_TICTACTOE_H
#define GB_CPP_ESSENTIAL_TICTACTOE_H

#include <iostream>
#include <vector>

using namespace std;

class TicTacToe
{
//Перечисление с вариантами значений для игры в крестики-нолики
    enum ETicTacToe
    {
        Empty,
        XMark,
        OMark
    };

//Массив для игры в крестики-нолики
    vector<vector<ETicTacToe>> _vvGameField;

    const int _FieldSize;

public:
    TicTacToe();
    ~TicTacToe();

    //Вывод игрового поля на экран
    void PrintField();
    //Очистка экрана
    void Clear();
};

#endif //GB_CPP_ESSENTIAL_TICTACTOE_H
