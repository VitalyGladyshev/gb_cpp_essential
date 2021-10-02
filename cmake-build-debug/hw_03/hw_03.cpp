//
// Created by vitaly on 02.10.2021.
//

#include "DataCube.h"

#include<iostream>
#include<memory>

using namespace std;

/* Вычисление выражения a * (b + (c / d)) и вывод результата с плавающей точкой, где
 * a, b, c, d – целочисленные константы.
 * Используются static_cast или СStyle cast к float чтобы выполнить точное деление.
 */
double expression_calculating(const int iA,const int iB, const int iC, const int iD)
{
    return iA * (iB + (static_cast<double>(iC) / iD));
}

/* Дано целое число. Если оно меньше или равно 21, то выведите на экран разницу между этим числом и числом 21.
 * Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу между этим числом и 21.
 * При выполнении задания следует использовать тернарный оператор (?:)
 */
int ternary_operator(const int iA)
{
    return iA <= 21 ? iA - 21 : 2 * (iA - 21);
}

int main()
{
    //Задание 1
    const int a {19};
    const int b {20};
    const int c {21};
    const int d {22};
    cout << "1. Вычисление выражения: a * (b + (c / d))" << endl;
    cout << "\ta = " << a << "  b = " << b << "  c = " << c << "  d = " << d << endl;
    cout << "\ta * (b + (c / d)) = " << expression_calculating(a, b, c, d) << endl  << endl;
    
    //Задание 2
    cout << "2. Тернарный оператор a ? a - 21 : 2 * (a - 21)" << endl;
    cout << "\ta = " << a << " Результат: " << ternary_operator(a) << endl;
    cout << "\ta = " << c << " Результат: " << ternary_operator(c) << endl;
    cout << "\ta = " << d << " Результат: " << ternary_operator(d) << endl << endl;

    //Задание 3
    auto pcDataCube = make_unique<DataCube>();
    cout << "3. Трёхмерная матрица - куб данных" << endl;
    pcDataCube->PrintDataCube();
    pcDataCube->SetItem(1, 1, 1, d);
    pcDataCube->PrintDataCube();
    cout << endl;

    //Задание 4
    extern const int iU;
    extern const int iX;
    extern const int iY;
    extern const int iZ;
    cout << "4. Вычисление выражения: a * (b + (c / d)) Переменные в другом файле" << endl;
    cout << "\ta = " << iU << "  b = " << iX << "  c = " << iY << "  d = " << iZ << endl;
    cout.precision(8);
    cout << "\ta * (b + (c / d)) = " << expression_calculating(iU, iX, iY, iZ) << endl  << endl;
}