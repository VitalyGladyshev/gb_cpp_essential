//
// Created by vitaly on 18.10.2021.
//

#include "TicTacToe.h"

//------------------------------------------------------------------
TicTacToe::TicTacToe() : _FieldSize { 3 }
{
    for(int i=0; i<_FieldSize; ++i)
    {
        vector<ETicTacToe> a {Empty, Empty, Empty};
        _vvGameField.push_back(a);
    }
}
//------------------------------------------------------------------
TicTacToe::~TicTacToe()
{
}
//------------------------------------------------------------------
//Вывод игрового поля на экран
void TicTacToe::PrintField()
{
    Clear();
    cout << "-------------" << endl;
    for (int i = 0; i < _FieldSize; i++)
    {
        cout << "|";
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
        cout << endl << "-------------" << endl;
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
