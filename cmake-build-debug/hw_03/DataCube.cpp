//
// Created by vitaly on 02.10.2021.
//

#include "DataCube.h"

#include<iostream>

using namespace std;

DataCube::DataCube()
{
    _pppiDataCube = new int**[_SIZE];
    for(int l = 0; l < _SIZE; l++)
    {
        _pppiDataCube[l] = new int*[_SIZE];
        for(int r = 0; r < _SIZE; r++)
            _pppiDataCube[l][r] = new int[_SIZE] {0, 0, 0};
    }
}

DataCube::~DataCube()
{
    for(int l = 0; l < _SIZE; l++)
    {
        for(int r = 0; r < _SIZE; r++)
            delete[] _pppiDataCube[l][r];
        delete[] _pppiDataCube[l];
    }
    delete[] _pppiDataCube;
}

int DataCube::GetItem(const unsigned int iLevel, const unsigned int iRow, const unsigned int iColumn) const
{
    if (iLevel && (iLevel < _SIZE))
        if (iRow && (iLevel < _SIZE))
            if (iColumn && (iLevel < _SIZE))
                return *(*(*(_pppiDataCube+iLevel)+iRow)+iColumn);
    return -1;
}

int DataCube::SetItem(const unsigned int iLevel, unsigned const int iRow, const unsigned int iColumn,
                      const unsigned int iItem)
{
    if (iLevel && (iLevel < _SIZE))
        if (iRow && (iLevel < _SIZE))
            if (iColumn && (iLevel < _SIZE))
            {
                *(*(*(_pppiDataCube+iLevel)+iRow)+iColumn) = iItem;
                return *(*(*(_pppiDataCube+iLevel)+iRow)+iColumn);
            }
    return -1;
}

void DataCube::PrintDataCube() const
{
    cout << "\tКуб данных (по уровням):" << endl;
    for(int l = 0; l < _SIZE; l++)
    {
        cout << "\t\tУровень " << l+1 << endl;
        for(int r = 0; r < _SIZE; r++)
        {
            cout << "\t\t\t";
            for(int c = 0; c < _SIZE; c++)
                cout << _pppiDataCube[l][r][c] << "\t";
            cout << endl;
        }
    }
}

//Переменные для задания 4
extern const int iU {29};
extern const int iX {30};
extern const int iY {31};
extern const int iZ {32};
