//
// Created by vitaly on 15.10.2021.
//

# include "mylib.h"

#include <iostream>
#include <vector>

#define IS_IN_RANGE(iNumber, iBorder) cout << (((iNumber >= 0)&&(iNumber < iBorder)) ? \
    "true" : "false") << endl << endl;

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //Задание 1/5
    cout << "Задание 1/5" << endl;
    vector<float> vfFloatVector;
    vfFloatVector.resize(10);
    MyLib::FillByProgression(vfFloatVector);
    MyLib::PrintArray(vfFloatVector);
    cout << "\tКоличество отрицательных чисел: " <<MyLib::NegativeNumberCount(vfFloatVector) << endl << endl;

    //Задание 2
    cout << "Задание 2" << endl;
    int iNumber = MyLib::GetInt("\tВведите целое число для проверки: ");
    int iBorder = MyLib::GetInt("\tВведите верхнюю границу диапазона для проверки числа: ");
    cout << "\tРезультат проверки числа на попадание в диапазон [0, " << iBorder << "): ";
    IS_IN_RANGE(iNumber, iBorder);

    //Задание 3
    cout << "Задание 3" << endl;

    cout << endl;

    //Задание 4
    cout << "Задание 4" << endl;

    cout << endl;
}
