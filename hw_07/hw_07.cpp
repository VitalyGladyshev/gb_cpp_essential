//
// Created by vitaly on 15.10.2021.
//

# include "mylib.h"

#include <iostream>
#include <vector>

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

    cout << endl;

    //Задание 3
    cout << "Задание 3" << endl;

    cout << endl;

    //Задание 4
    cout << "Задание 4" << endl;

    cout << endl;
}
