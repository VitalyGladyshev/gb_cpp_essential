//
// Created by vitaly on 15.10.2021.
//

#include "mylib.h"

#define SwapINT(a, b)  if(viVectorForSort[j-1] > viVectorForSort[j]) { \
int temp = viVectorForSort[j]; \
viVectorForSort[j] = viVectorForSort[j-1]; \
viVectorForSort[j-1] = temp; }

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

    //Сортировка массива пузырьком
    void BubbleSorting(std::vector<int>& viVectorForSort)
    {
        for(unsigned long i = 1; i < viVectorForSort.size(); i++)
            for(unsigned long j = 1; j < viVectorForSort.size(); j++)
                SwapINT(a, b)
    }

    //Вывод структуры Employee
    void EmployeePrint(const Employee* pEmployee, const unsigned int& uiIter)
    {
        std::cout << "\tСотрудник " << uiIter + 1 << std::endl;
        std::cout << "\t\tВозраст: " << static_cast<int>(pEmployee[uiIter].ucAge) << std::endl;
        std::cout << "\t\tКод: " << static_cast<int>(pEmployee[uiIter].ucCode) << std::endl;
        std::cout << "\t\tОтдел: " << pEmployee[uiIter].sDepartment << std::endl;
        std::cout << "\t\tКомната: " << pEmployee[uiIter].sRoom << std::endl;
        std::cout << "\t\tРейтинг: " << pEmployee[uiIter].sScore << std::endl;
        std::cout << "\t\tЗарплата: " << pEmployee[uiIter].uiSalary << std::endl;
        std::cout << "\t\tРазмер структуры Employee: " << sizeof(pEmployee[uiIter]) << std::endl << std::endl;
    }
}
