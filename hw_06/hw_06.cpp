//
// Created by vitaly on 13.10.2021.
//

#include <iostream>
#include <ios>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция считывания целого положительного числа из консоли спроверкой на диапазон
unsigned int get_unsigned_int_border(const string& str_request, const int& iBorder)
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
        else if(i_res > iBorder)
        {
            b_convert_fault = true;
            cout << "\tОшибка! Введённое число не должно превышать: " << iBorder << endl;
        }
    }
    while(b_convert_fault);

    return static_cast<unsigned int>(i_res);
}

//Заполняем ммасив возрастающими значениями - степени двойки
void fill_degrees_two(int* pArray, const unsigned int& iSize)
{
    for(unsigned int uiValue = 1, i = 0; i < iSize; i++)
    {
        pArray[i] = static_cast<int>(uiValue);
        uiValue <<= 1;
    }
}

//Выводит массив чисел на экран. Параметры функции это сам массив и его размер.
template <typename T>
void print_array(const T* pArray, const unsigned int& iSize)
{
    for(int i=0; i<iSize; i++)
        cout << "\tЭлемент " << i+1 << ":\t" << static_cast<unsigned int>(pArray[i]) << endl;
}

//Выводим квадратную матрицу на экран
void print_matrix(int** ppArray, const int& SIZE)
{
    cout << "\tМатрица:" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << "\t\t";
        for(int j = 0; j < SIZE; j++)
            cout << ppArray[i][j] << "\t";
        cout << endl;
    }
}

//Заполняем квадратную матрицу случайными числами
void fill_by_random(int** ppArray, const int& SIZE)
{
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            ppArray[i][j] = 1 + rand() % 10;
}

//Функция открытия файла для записи. Имя файла вводится пользователем
string text_file_to_write(ofstream& file, const string& str_request, const _Ios_Openmode open_mode)
{
    bool file_creation_fault = false;
    string str_income;

    do
    {
        cout << str_request;
        cin >> str_income;
        str_income += ".txt";

        try
        {
            file.open(str_income, open_mode);
        }
        catch(ofstream::failure& err)
        {
            cout << "\tОшибка открытия файла!" << endl;
            file_creation_fault = true;
        }
    }
    while(file_creation_fault);

    return str_income;
}

// Функция генерации произвольного содержимого текстового файла
void text_file_generate_context(ofstream& file)
{
    for(int iFileLength = 50 + rand() % 50; iFileLength; iFileLength--)
        file << static_cast<char>(48 + rand() % 74);
}

//Функция копирования содержимого файла
bool file_copy(const string& source_file_name, ofstream& destination_file)
{
    ifstream file_source;
    file_source.open(source_file_name, ifstream::binary);
    if(file_source.is_open())
    {
        long lSize = file_source.seekg(0, ios::end).tellg();
        file_source.seekg(0);
        auto* cBuf = new char[lSize+1];
        file_source.read(cBuf, lSize);
        destination_file.write(cBuf, lSize);
        delete[] cBuf;
        file_source.close();
    }
    else
        return false;
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    //Задание 1
    cout << "Задание 1" << endl;
    unsigned int uiSize {get_unsigned_int_border("\tВведите размер массива (не более 50): ", 50)};

    bool bGood_alloc = true;
    int* pArray;
    try
    {
        pArray = new int[uiSize];
    }
    catch(bad_alloc& err)
    {
        cout << "\tОшибка при выделени памяти!" << endl;
        bGood_alloc = false;
    }
    if(bGood_alloc)
    {
        fill_degrees_two(pArray, uiSize);
        print_array(pArray, uiSize);
        delete[] pArray;
    }
    cout << endl;

    //Задание 2
    cout << "Задание 2" << endl;

    srand(static_cast<unsigned int>(time(nullptr)));

    int** ppArray;
    const int SIZE = 4;

    ppArray = new int*[SIZE];
    for(int i = 0; i<SIZE; i++)
        ppArray[i] = new int[SIZE];

    fill_by_random(ppArray, SIZE);
    print_matrix(ppArray, SIZE);

    for(int i = 0; i < SIZE; i++)
        delete ppArray[i];
    delete[] ppArray;
    cout << endl;

    //Задание 3
    cout << "Задание 3" << endl;
    ofstream file_out;
    string first_file_name = text_file_to_write(file_out,
                                                "\tВведите имя первого файла: ",
                                                ofstream::out | ofstream::trunc);
    text_file_generate_context(file_out);
    file_out.close();

    string second_file_name = text_file_to_write(file_out,
                                                 "\tВведите имя второго файла: ",
                                                 ofstream::out | ofstream::trunc);
    text_file_generate_context(file_out);
    file_out.close();

    cout << endl;

    //Задание 4
    cout << "Задание 4" << endl;
    text_file_to_write(file_out,
                       "\tВведите имя файла для конкатенации содержимого первых двух файлов: ",
                       ofstream::out | ofstream::app | ofstream::binary);

    if(file_copy(first_file_name, file_out))
        cout << "\tУспешно скопирован первый файл" << endl;
    else
        cout << "\tОшибка копирования первого файла" << endl;

    if(file_copy(second_file_name, file_out))
        cout << "\tУспешно скопирован второй файл" << endl;
    else
        cout << "\tОшибка копирования второго файла" << endl;

    file_out.close();
    cout << endl;

    //Задание 5
    cout << "Задание 5" << endl;

    cout << endl;
}
