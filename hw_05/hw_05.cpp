//
// Created by vitaly on 08.10.2021.
//

#include <iostream>
#include <vector>

using namespace std;

//Выводит массив double чисел на экран. Параметры функции это сам массив и его размер.
void print_array(const double* dbArray, const int& iSize)
{
    for(int i=0; i<iSize; i++)
        cout << "\tЭлемент " << i+1 << ":\t" << dbArray[i] << endl;
}

//Выводит массив unsigned char чисел на экран. Параметры функции это ссылка на вектор
void print_array(const vector<unsigned char>& vArray)
{
    cout << "\t\t";
    for(auto el : vArray)
        cout << static_cast<int>(el) << " ";
    cout << endl;
}

//Функция, заменяющая в принятом массиве 0 на 1, 1 на 0
void array_inversion(vector<unsigned char>& vArray)
{
    for(auto& el : vArray)
        el = el ? 0 : 1;
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

    //Задание 4
    cout << "Задание 4" << endl;

    //Задание 5
    cout << "Задание 5" << endl;

}
