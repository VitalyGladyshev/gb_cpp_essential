//
// Created by vitaly on 02.10.2021.
//

#include "DataCube.h"

#include<iostream>

using namespace std;

DataCube::DataCube()
{


}

DataCube::~DataCube()
{


}

int DataCube::GetItem(const unsigned int iLevel, const unsigned int iRow, const unsigned int iColumn) const
{

    return -1;
}

int DataCube::SetItem(const unsigned int iLevel, unsigned const int iRow, const unsigned int iColumn,
                      const unsigned int iItem)
{

    return -1;
}

void DataCube::PrintDataCube() const
{

}

//Переменные для задания 4
extern const int iU {29};
extern const int iX {30};
extern const int iY {31};
extern const int iZ {32};
