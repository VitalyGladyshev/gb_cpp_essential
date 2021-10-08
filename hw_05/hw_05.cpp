//
// Created by vitaly on 08.10.2021.
//


#include <iostream>

using namespace std;

void print_array(const double* dbArray, const int& iSize)
{
    for(int i=0; i<iSize; i++)
        cout << "\tЭлемент " << i+1 << ":\t" << dbArray[i] << endl;
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

    //Задание 3
    cout << "Задание 3" << endl;

    //Задание 4
    cout << "Задание 4" << endl;

    //Задание 4
    cout << "Задание 4" << endl;

}
