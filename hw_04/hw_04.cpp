//
// Created by vitaly on 06.10.2021.
//

#include <iostream>
#include <string>

using namespace std;

/* Функция проверяющая что сумма двух (введенных с клавиатуры) чисел лежит в пределах от 10 до 20 (включительно),
 * если да – вывести строку "true", в противном случае – "false";
 */
bool digits_pair_compare(const double& d_Digit_1, const double& d_Digit_2)
{
    double d_Sum = d_Digit_1 + d_Digit_2;
    if(d_Sum >= 10 && d_Sum <=20)
        return true;
    else
        return false;
}

// Функция считывания целого положительного числа из консоли
unsigned int get_unsigned_int(const string& str_request)
{
    string str_income;
    bool b_convert_fault = true;
    int i_res;

    do
    {
        cout << str_request;
        cin >> str_income;
        try
        {
            i_res = std::stoi(str_income);
            b_convert_fault = false;
        }
        catch(invalid_argument& err)
        {
            cout << "\tОшибка: " << err.what() << ". Введённое значение не является числом" << endl;
        }
        if(i_res < 0)
        {
            b_convert_fault = true;
            cout << "\tОшибка! Введённое значение должно быть положительным" << endl;
        }
    }
    while(b_convert_fault);

    return static_cast<unsigned int>(i_res);
}

bool prime_test(const unsigned int& ui_number)
{
    if(ui_number == 2)
        return true;
    if((ui_number < 2) || !(ui_number % 2))
        return false;

    for(int i = 3; i < ui_number; i += 2)
        if(!(ui_number % i))
            return false;

    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    //Задание 1
    cout << "Задание 1" << endl;
    unsigned int ui_Digit_1 {get_unsigned_int("\tВведите первое целое положительное число: ")};
    unsigned int ui_Digit_2 {get_unsigned_int("\tВведите второе целое положительное число: ")};

    if(digits_pair_compare(ui_Digit_1, ui_Digit_2))
        cout << "\tСумма чисел в диапазоне" << endl << endl;
    else
        cout << "\tСумма чисел не в диапазоне" << endl << endl;

    //Задание 2
    cout << "Задание 2" << endl;
    const int CONST_1 = 5;
    const int CONST_2 = 5;

    cout << ((((CONST_1 == 10)&&(CONST_2 == 10))||(CONST_1+CONST_2 == 10)) ? "\ttrue" : "\tfalse") << endl << endl;

    //Задание 3
    cout << "Задание 3" << endl;

    cout << "\t";
    for(int i = 1; i < 50; i+=2)
        cout << i << " ";
    cout << endl << endl;

    //Задание 4
    cout << "Задание 4 проверка является ли число простым " << endl;

    for(int i = 0; i < 24; i++)
    {
        if(prime_test(i))
            cout << "\tЧисло " << i << " простое " << endl;
        else
            cout << "\tЧисло " << i << " не является простым " << endl;
    }

    unsigned int ui_Digit {get_unsigned_int("\n\tВведите целое положительное число: ")};
    if(prime_test(ui_Digit))
        cout << "\tЧисло прострое" << endl << endl;
    else
        cout << "\tЧисло не является простым " << endl << endl;

    return 0;
}
