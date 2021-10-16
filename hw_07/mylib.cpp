//
// Created by vitaly on 15.10.2021.
//

#include "mylib.h"

namespace MyLib
{
    //Заполняем масив прогрессией чисел от отрицательных до положительных
    void FillByProgression(std::vector<float>& vfArray)
    {
        int iValue = static_cast<int>(vfArray.size()) / 2 * -10;
        for(auto& el : vfArray)
        {
            el = static_cast<float>(iValue);
            iValue += 10;
        }
    }

    //Выводит массив чисел на экран.
    void PrintArray(const std::vector<float>& vfArray)
    {
        int i = 1;
        for(auto& el : vfArray)
            std::cout << "\tЭлемент " << i++ << ":\t" << el << std::endl;
    }

    //Подсчитываем количество отрицательных чисел
    int NegativeNumberCount(const std::vector<float>& vfArray)
    {
        int cnt = 0;
        for(auto el : vfArray)
            if(el < 0)
                cnt++;
        return cnt;
    }
}
