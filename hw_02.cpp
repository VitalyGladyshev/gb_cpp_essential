//
// Created by viv232 on 29.09.2021.
//

#include<iostream>
#include<vector>

#define FRACTION 456.36789564738475387456
#define FIELD_SIZE 3

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
    STicTacToe();
    vector<vector<ETicTacToe>> vvGameField;
};

STicTacToe::STicTacToe()
{
    for(int i=0; i<FIELD_SIZE; ++i)
    {
        vector<ETicTacToe> a {Empty, Empty, Empty};
        vvGameField.push_back(a);
    }
}

//Структура для задания 5
struct MyVariant
{
    void SetValue(const int i)
    {
        SMyData.iIntD = i;
        _bInt = true;
        _bFloat = false;
        _bSymbol = false;
    }

    void SetValue(const float f)
    {
        SMyData.fFloatD = f;
        _bInt = false;
        _bFloat = true;
        _bSymbol = false;
    }

    void SetValue(const char c)
    {
        SMyData.cSymbol = c;
        _bInt = false;
        _bFloat = false;
        _bSymbol = true;
    }

    string print_type() const
    {
        if(_bInt)
            return "int";
        else if(_bFloat)
            return "float";
        else if(_bSymbol)
            return "char";
        else
            return "other type";
    }

    union MyData
    {
        int iIntD;
        float fFloatD;
        char cSymbol;
    }SMyData;
private:
    bool _bInt = true;
    bool _bFloat = false;
    bool _bSymbol = false;
};

int main()
{
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

    cout << "2. Перечисление ETicTacToe:" << endl;
    cout << "\tEmpty: " << Empty << endl;
    cout << "\tXMark: " << XMark << endl;
    cout << "\tOMark: " << OMark << endl;

    cout << "\n3. Массив значений поля в игре:" << endl;
    vector<ETicTacToe> vtrFieldStatus {Empty, XMark, OMark};
    for(auto el : vtrFieldStatus)
        cout << "\tСостояние поля: " << el << endl;

    cout << "\n4. Структура для игрового поля:" << endl;
    STicTacToe stGameField;
    for(auto& row: stGameField.vvGameField)
    {
        for(auto& element: row)
            cout << "\t" << element;
        cout << endl;
    }

    MyVariant newMyVariant;
    cout << "\n5. Структура MyVariant:" << endl;
    newMyVariant.SetValue(0);
    cout << "\tТип: " << newMyVariant.print_type() << endl;
    newMyVariant.SetValue(12.23f);
    cout << "\tТип: " << newMyVariant.print_type() << endl;
    newMyVariant.SetValue('k');
    cout << "\tТип: " << newMyVariant.print_type() << endl;

    return 0;
}
