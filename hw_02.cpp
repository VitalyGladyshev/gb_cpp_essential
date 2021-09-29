//
// Created by viv232 on 29.09.2021.
//

#include<iostream>
#include<sstream>

#define FRACTION 456.36789564738475387456

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
    float fFraction { FRACTION };
    double dbNewPrecision { FRACTION  };

    cout << "1. Встроенные типы данных:" << endl;
    cout << "\ti16NumObj: " << i16NumObj << endl;
    cout << "\ti32Dist: " << i32Dist << endl;
    cout << "\tll64StarNumber: " << ll64StarNumber << endl;
    cout << "\tc8SymbolZ: " << c8SymbolZ << endl;
    cout << "\tbFlag: " << bFlag << endl;
    cout.precision(25);
    cout << "\tДробь:\t\t\t456.36789564738475387456" << endl;
    cout << "\tfFraction:\t\t" << fFraction << endl;
    cout << "\tdbNewPrecision:\t" << dbNewPrecision << endl << endl;

    return 0;
}
