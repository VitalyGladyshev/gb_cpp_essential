//
// Created by vitaly on 18.10.2021.
//

#include "TicTacToe.h"

//------------------------------------------------------------------
TicTacToe::TicTacToe() :    _FieldSize { 3 },
                            _Player1 { Human },
                            _Player2 { Human },
                            bCurrentPlayerIs1 { true },
                            _iTurnNumber { 1 }
{
    for(int i=0; i<_FieldSize; ++i)
    {
        vector<ETicTacToe> a {Empty, Empty, Empty};
        _vvGameField.push_back(a);
    }

    StartDialog();
}
//------------------------------------------------------------------
TicTacToe::~TicTacToe()
{
}
//------------------------------------------------------------------
// Функция считывания типа игрока из консоли
TicTacToe::EPlayerType TicTacToe::GetPlayerType(const std::string& str_request)
{
    std::string str_income;
    bool b_convert_fault = true;
    int i_res;

    do
    {
        std::cout << str_request;
        std::cin >> str_income;
        try
        {
            i_res = std::stoi(str_income);
        }
        catch(std::invalid_argument& err)
        {
            std::cout << "\tОшибка: " << err.what() << ". Введённое значение не является корректным значением" << \
                std::endl;
        }
        if((i_res == Human) || (i_res == Computer))
            b_convert_fault = false;
        else
            std::cout << "\tВведённое значение не является корректным значением" << std::endl;
    }
    while(b_convert_fault);

    return static_cast<EPlayerType>(i_res);
}
//------------------------------------------------------------------
// Функция считывания строки\столбца
int TicTacToe::GetCoord(const std::string& str_request)
{
    std::string str_income;
    bool b_convert_fault = true;
    int i_res;

    do
    {
        std::cout << str_request;
        std::cin >> str_income;
        try
        {
            i_res = std::stoi(str_income);
        }
        catch(std::invalid_argument& err)
        {
            std::cout << "\tОшибка: " << err.what() << ". Введённое значение не является корректным значением" << \
                std::endl;
        }
        if((i_res >= 1) && (i_res <= 3))
            b_convert_fault = false;
        else
            std::cout << "\tВведённое значение не является корректным значением" << std::endl;
    }
    while(b_convert_fault);

    return i_res-1;
}
//------------------------------------------------------------------
//Стартовый диалог
void TicTacToe::StartDialog()
{
    Clear();
    cout << "Игра Крестики-нолики" << endl << endl;

    _Player1 = GetPlayerType("Кто будет первым игроком?\n\t1 Человек\n\t2 Компьютер\nВведите номер: ");
    _Player2 = GetPlayerType("\nКто будет вторым игроком?\n\t1 Человек\n\t2 Компьютер\nВведите номер: ");
}
//------------------------------------------------------------------
//Вывод игрового поля на экран
void TicTacToe::PrintField()
{
    Clear();
    cout << "\nХод " << _iTurnNumber << endl << endl;
    cout << "\t-------------" << endl;
    for (int i = 0; i < _FieldSize; i++)
    {
        cout << "\t|";
        for (int j = 0; j < _FieldSize; j++)
        {
            switch(_vvGameField[i][j])
            {
                case Empty:
                    cout << "   |";
                    break;
                case XMark:
                    cout << " X |";
                    break;
                case OMark:
                    cout << " O |";
                    break;
            }
        }
        cout << endl << "\t-------------" << endl;
    }
}
//------------------------------------------------------------------
//Очистка экрана
void TicTacToe::Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}
//------------------------------------------------------------------
//Проверка на выигрыш
bool TicTacToe::CheckWin(pair<int, int>LastTurnCoord)
{
    if((_vvGameField[LastTurnCoord.first][0] ==
       _vvGameField[LastTurnCoord.first][1] == _vvGameField[LastTurnCoord.first][2]) ||

       (_vvGameField[0][LastTurnCoord.second] ==
       _vvGameField[1][LastTurnCoord.second] == _vvGameField[2][LastTurnCoord.second]) ||

       (_vvGameField[0][0] == _vvGameField[1][1] == _vvGameField[2][2]) ||

       (_vvGameField[0][2] == _vvGameField[1][1] == _vvGameField[2][0]))
        return true;
    else
        return false;
}
//------------------------------------------------------------------
//Сделать ход
bool TicTacToe::MakeTurn()
{
    PrintField();

    if(true)
    {
        cout << "\nСделайте ход:" << endl;
        auto row = GetCoord("\tВведите номер строки (1-3): ");
        auto col = GetCoord("\tВведите номер столбца (1-3): ");
        _vvGameField[row][col] = XMark;
    }

    PrintField();

    if (CheckWin(pair(1, 1)))
    {
        cout << "\nИгрок " << (bCurrentPlayerIs1 ? "1" : "2") << " победил!!!" << endl;
        return true;
    }
    else
    {
        if (!bCurrentPlayerIs1)
            _iTurnNumber++;
        bCurrentPlayerIs1 = !bCurrentPlayerIs1;
        return false;
    }
}
//------------------------------------------------------------------
