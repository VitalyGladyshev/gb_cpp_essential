//
// Created by vitaly on 15.10.2021.
//

# include "mylib.h"

#include <iostream>
#include <vector>
#include <fstream>

#define IS_IN_RANGE(iNumber, iBorder) cout << (((iNumber >= 0)&&(iNumber < iBorder)) ? \
    "true" : "false") << endl << endl;

#define SIZE 8

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //Задание 1/5
    cout << "Задание 1/5" << endl;
    vector<float> vfFloatVector;
    vfFloatVector.resize(10);
    MyLib::FillByProgression(vfFloatVector);
    MyLib::PrintArray(vfFloatVector); //
    cout << "\tКоличество отрицательных чисел: " <<MyLib::NegativeNumberCount(vfFloatVector) << endl << endl;

    //Задание 2
    cout << "Задание 2" << endl;
    int iNumber = MyLib::GetInt("\tВведите целое число для проверки: ");
    int iBorder = MyLib::GetInt("\tВведите верхнюю границу диапазона для проверки числа: ");
    cout << "\tРезультат проверки числа на попадание в диапазон [0, " << iBorder << "): ";
    IS_IN_RANGE(iNumber, iBorder)

    //Задание 3
    cout << "Задание 3 Сортировка пузырьком" << endl;
    vector<int> viVectorForSort;
    viVectorForSort.resize(SIZE);
    for (auto& el : viVectorForSort)
        el = MyLib::GetInt("\tВведите целое число: ");
    cout << endl << "\tМассив до сортировки: " << endl;
    MyLib::PrintArray(viVectorForSort);
    MyLib::BubbleSorting(viVectorForSort);
    cout << endl << "\tМассив после сортировки: " << endl;
    MyLib::PrintArray(viVectorForSort);
    cout << endl;

    //Задание 4
    cout << "Задание 4" << endl;
    auto pEmployees = new MyLib::Employee[2];

    pEmployees[0].uiSalary = 70000;
    pEmployees[0].sRoom = 6504;
    pEmployees[0].sDepartment = 23024;
    pEmployees[0].sScore = 90;
    pEmployees[0].ucAge = 34;
    pEmployees[0].ucCode = 127;

    pEmployees[1].uiSalary = 50000;
    pEmployees[1].sRoom = 6302;
    pEmployees[1].sDepartment = 23124;
    pEmployees[1].sScore = 78;
    pEmployees[1].ucAge = 23;
    pEmployees[1].ucCode = 164;

    MyLib::EmployeePrint(pEmployees, 0);
    MyLib::EmployeePrint(pEmployees, 1);

    ofstream file_out;
    bool file_open_success = true;
    try
    {
        file_out.open("Employees.dat", ofstream::out | ofstream::trunc | ofstream::binary);
    }
    catch(ofstream::failure& err)
    {
        cout << "\tОшибка открытия файла!" << endl;
        file_open_success = false;
    }
    if(file_open_success)
    {
        file_out.write(reinterpret_cast<char*>(pEmployees), sizeof(MyLib::Employee) * 2);
        file_out.close();
    }

    delete[] pEmployees;
}
