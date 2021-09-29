//
// Created by viv232 on 29.09.2021.
//

#include<iostream>

using namespace std;

//Перечисление с вариантами значений для игры в крестики-нолики
enum ETicTacToe
{
    Empty,
    XMark,
    OMark
};

//Структура для игры в крестики-нолики
struct STicTacToe
{

};

int main(int argc, char* argv[])
{
//1. Встроенные типы данных
    short int i16NumObj { 1024 };
    int i32Dist { 2'123'456 };
    long long ll64StarNumber { 434'234'345'345'456 };
    char c8SymbolZ { 'Z' };
    bool bFlag { false };
    float fFraction { 456.36789564738475387456 };
    double dbNewPrecision { 456.36789564738475387456  };

    cout << "1. Встроенные типы данных" << endl << endl;
    cout << "i16NumObj: " << i16NumObj << endl;
    cout << "i32Dist: " << i32Dist << endl;
    cout << "ll64StarNumber: " << ll64StarNumber << endl;
    cout << "c8SymbolZ: " << c8SymbolZ << endl;
    cout << "bFlag: " << bFlag << endl;
    cout << "fFraction: " << fFraction << endl;
    cout << "dbNewPrecision: " << dbNewPrecision << endl << endl;

    return 0;
}
