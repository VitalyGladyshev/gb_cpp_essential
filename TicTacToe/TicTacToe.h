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

    enum EPlayerType
    {
        Human,
        Computer
    };

//Массив для игры в крестики-нолики
    vector<vector<ETicTacToe>> _vvGameField;
    const int _FieldSize;
    EPlayerType _Player1;
    EPlayerType _Player2;
    bool bCurrentPlayerIs1;
    int _iTurnNumber;

public:
    TicTacToe();
    ~TicTacToe();

    // Функция считывания типа игрока из консоли
    EPlayerType GetPlayerType(const std::string& str_request);
    //Стартовый диалог
    void StartDialog();
    //Вывод игрового поля на экран
    void PrintField();
    // Функция считывания строки\столбца
    int GetCoord(const std::string& str_request);
    //Очистка экрана
    void Clear();
    //Проверка на выигрыш
    bool CheckWin(pair<int, int>LastTurnCoord);
    //Сделать ход
    bool MakeTurn();
};

#endif //GB_CPP_ESSENTIAL_TICTACTOE_H
