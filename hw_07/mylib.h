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
    void PrintArray(const std::vector<float>& vfArray);

    //Подсчитываем количество отрицательных чисел
    int NegativeNumberCount(const std::vector<float>& vfArray);
}

#endif //GB_CPP_ESSENTIAL_MYLIB_H
