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

    //Подсчитываем количество отрицательных чисел
    int NegativeNumberCount(const std::vector<float>& vfArray)
    {
        int cnt = 0;
        for(auto el : vfArray)
            if(el < 0)
                cnt++;
        return cnt;
    }

    // Функция считывания целого числа из консоли
    int GetInt(const std::string& str_request)
    {
        std::string str_income;
        bool b_convert_fault = true;
        int i_res;

        do
        {
            std::cout << str_request;
            std::cin >> str_income;
            try
            {
                i_res = std::stoi(str_income);
                b_convert_fault = false;
            }
            catch(std::invalid_argument& err)
            {
                std::cout << "\tОшибка: " << err.what() << ". Введённое значение не является числом" << std::endl;
            }
        }
        while(b_convert_fault);

        return i_res;
    }
}
