//
// Created by vitaly on 15.10.2021.
//

#ifndef GB_CPP_ESSENTIAL_MYLIB_H
#define GB_CPP_ESSENTIAL_MYLIB_H

#include <vector>
#include <iostream>

namespace MyLib
{
    //Заполняем масив прогрессией чисел от отрицательных до положительных
    void FillByProgression(std::vector<float>& vfArray);

    //Выводит массив чисел на экран.
    template <typename T>
    void PrintArray(const std::vector<T>& vArray)
    {
        int i = 1;
        for(auto& el : vArray)
            //std::cout << "\tЭлемент " << i++ << ":\t" << el << std::endl;
            std::cout << "\t" << el;
        std::cout << std::endl;
    }

    //Подсчитываем количество отрицательных чисел
    int NegativeNumberCount(const std::vector<float>& vfArray);

    // Функция считывания целого числа из консоли
    int GetInt(const std::string& str_request);

    //Сортировка массива пузырьком
    void BubbleSorting(std::vector<int>& viVectorForSort);

#pragma pack(push, 1)
    struct Employee
    {
        unsigned int uiSalary;
        short sRoom;
        short sDepartment;
        short sScore;
        unsigned char ucAge;
        unsigned char ucCode;
    };
#pragma pack(pop)

    //Вывод структуры Employee
    void EmployeePrint(const Employee* pEmployee, const unsigned int& Iter);
}

#endif //GB_CPP_ESSENTIAL_MYLIB_H
