//
// Created by vitaly on 08.10.2021.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//Выводит массив чисел на экран. Параметры функции это сам массив и его размер.
template <typename T>
void print_array(const T* pArray, const int& iSize)
{
    for(int i=0; i<iSize; i++)
        cout << "\tЭлемент " << i+1 << ":\t" << pArray[i] << endl;
}

//Выводит массив на экран. Параметры функции это ссылка на вектор
template <typename TD>
void print_array(const vector<TD>& vArray)
{
    cout << "\t\t";
    for(auto el : vArray)
        cout << static_cast<int>(el) << "\t";
    cout << endl;
}

//Функция, заменяющая в принятом массиве 0 на 1, 1 на 0
void array_inversion(vector<unsigned char>& vArray)
{
    for(auto& el : vArray)
        el = el ? 0 : 1;
}

//Функция, инициализирует массив последовательностью 1 4 7 10 13 16 19 22
void array_initialisation(int* pArray, const int iSize)
{
    for(int i = 0, mlt = 1; i<iSize; i++, mlt+=3)
        pArray[i] = mlt;
}

//Функция, сдвига массива на iDisplacement позиций
void array_displacement(vector<int>& vArray, int iDisplacement)
{
    bool bNeg = false;
    if(iDisplacement < 0)
        bNeg = true;

    unsigned long ulDisplacement = abs(iDisplacement);
    ulDisplacement %= vArray.size();

    if(!ulDisplacement)
        return;

    if(bNeg)
        ulDisplacement = vArray.size() - ulDisplacement;

    deque<int> deqTemp;
    for(unsigned long iterator = vArray.size() - ulDisplacement, i = 0;
        i < vArray.size();
        i++,  iterator = iterator + 1 < vArray.size() ? iterator + 1: 0)
            deqTemp.push_back(vArray[iterator]);

    for(int i = 0; i < vArray.size(); i++)
        vArray[i] = deqTemp[i];
}

//Функция поиска баланса в массиве
int balance_search(vector<int>& vArray)
{
    if(vArray.size() < 2)
        return 0;
    for(int iBorder = 1; iBorder < vArray.size(); iBorder++)
    {
        int iL = vArray[0], iR = vArray[vArray.size()-1];
        for(int iIter = 1; iIter < vArray.size()-1;iIter++)
        {
            if(iIter < iBorder)
                iL += vArray[iIter];
            else
                iR += vArray[iIter];
        }
        cout << "\t\tborder: " << iBorder << " iL: " << iL << " iR: " << iR << endl;
        if(iL == iR)
            return iBorder;
        if(iL > iR)
            return 0;
    }
    return 0;
}

//Выводит массив на экран и уазывает границу баланса
template <typename TD>
void print_array_border(const vector<TD>& vArray, const int& iBorder)
{
    cout << "\t\t";
    for(unsigned long i = 0; i < vArray.size(); i++)
    {
        if(i == iBorder)
            cout << "||\t";
        cout << vArray[i] << "\t";
    }
    cout << endl << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    //Задание 1
    cout << "Задание 1" << endl;
    const int SIZE = 10;
    double pdbArray[] {10., 8., 6., 4., 2., 0., -1.5, -3.5, -5.5, -7.5};
    print_array(pdbArray, SIZE);
    cout << endl;

    //Задание 2
    cout << "Задание 2" << endl;
    vector<unsigned char>(vucArray) {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
    cout << "\tМассив до инверсии:" << endl;
    print_array(vucArray);
    array_inversion(vucArray);
    cout << "\tМассив после инверсии:" << endl;
    print_array(vucArray);
    cout << endl;

    //Задание 3
    cout << "Задание 3" << endl;
    const int SIZE_ARRAY = 8;
    int* piArrayOf8 = new int[SIZE_ARRAY];
    array_initialisation(piArrayOf8, SIZE_ARRAY);
    print_array(piArrayOf8, SIZE_ARRAY);
    cout << endl;
    delete[] piArrayOf8;

    //Задание 4
    cout << "Задание 4" << endl;

    vector<int>(viDisplacement) {-7, -2, -1, 0, 1, 2, 3, 8, 9, 10};
    for(auto displacement : viDisplacement)
    {
        vector<int>(viArray) {2, 4, 6, 8, 10, 12, 14, 16, 18};
        cout << "\tСдвиг: " << displacement << endl;
        cout << "\tМассив до сдвига:" << endl;
        print_array(viArray);
        array_displacement(viArray, displacement);
        cout << "\tМассив после сдвига:" << endl;
        print_array(viArray);
        cout << endl;
    }
    cout << endl;

    //Задание 5
    cout << "Задание 5 " << endl;
    cout << "\tТестовый массив:" << endl;
    vector<int> vTest_1 {1, 1, 1, 2, 1};
    print_array(vTest_1);
    if(int iBalance = balance_search(vTest_1))
    {
        cout << "\tТочка баланса: " << iBalance << endl;
        print_array_border(vTest_1, iBalance);
    }
    else
        cout << "\tТочка баланса отсутствует" << endl << endl;

    cout << "\tТестовый массив:" << endl;
    vector<int> vTest_2 {2, 1, 1, 2, 1};
    print_array(vTest_2);
    if(int iBalance = balance_search(vTest_2))
    {
        cout << "\tТочка баланса: " << iBalance << endl;
        print_array_border(vTest_2, iBalance);
    }
    else
        cout << "\tТочка баланса отсутствует" << endl << endl;

    cout << "\tТестовый массив:" << endl;
    vector<int> vTest_3 {10, 1, 2, 3, 4};
    print_array(vTest_3);
    if(int iBalance = balance_search(vTest_3))
    {
        cout << "\tТочка баланса: " << iBalance << endl;
        print_array_border(vTest_3, iBalance);
    }
    else
        cout << "\tТочка баланса отсутствует" << endl << endl;

    cout << "\tТестовый массив:" << endl;
    vector<int> vTest_4 {10, 10, 10, 10, 10, 10, 20, 20};
    print_array(vTest_4);
    if(int iBalance = balance_search(vTest_4))
    {
        cout << "\tТочка баланса: " << iBalance << endl;
        print_array_border(vTest_4, iBalance);
    }
    else
        cout << "\tТочка баланса отсутствует" << endl << endl;
}
