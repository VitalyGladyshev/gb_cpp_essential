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
    enum class ETicTacToeMark
    {
        Empty,
        XMark,
        OMark
    };

    enum class EPlayerType
    {
        Human,
        Computer
    };

//Массив для игры в крестики-нолики
    vector<vector<ETicTacToeMark>> _vvGameField;
    const int _FieldSize;
    vector<EPlayerType> _PlayerTypeVector;
    bool _bCurrentPlayerIsNotOne;
    int _iTurnNumber;
    int _iEmptyFieldsCount;
    int _AILevel;

    // Функция считывания типа игрока из консоли
    EPlayerType GetPlayerType(const std::string& str_request);
    //Стартовый диалог
    void StartDialog();
    //Вывод игрового поля на экран
    void PrintField();
    // Функция считывания строки\столбца игрока человека
    int GetCoord(const std::string& str_request);
    // Запрос уровня сложности
    int GetAILevel();
    // Поптка AI выиграть/предотвратить поражение одним ходом
    pair<int, int> AIAttempt(const bool bCurrentPlayerIsNotOne);
    // Функция вычисления строки\столбца игрока компьютера
    std::pair<int, int> GetAICoord();
    //Очистка экрана
    void Clear();
    //Проверка на выигрыш
    bool CheckWin(pair<int, int>LastTurnCoord);

public:
    TicTacToe();
    ~TicTacToe();

    //Сделать ход
    bool MakeTurn();
};

#endif //GB_CPP_ESSENTIAL_TICTACTOE_H
