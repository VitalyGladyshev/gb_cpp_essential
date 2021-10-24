//
// Created by vitaly on 18.10.2021.
//

#include "TicTacToe.h"

#include <ctime>

//------------------------------------------------------------------
TicTacToe::TicTacToe() : _FieldSize { 3 },
                         _PlayerTypeVector {EPlayerType::Human, EPlayerType::Human },
                         _bCurrentPlayerIsNotOne {false },
                         _iTurnNumber { 1 },
                         _iEmptyFieldsCount { 9 },
                         _AILevel { 0 }
{
    srand(static_cast<unsigned int>(time(nullptr)));

    for(int i=0; i<_FieldSize; ++i)
    {
        vector<ETicTacToeMark> a {ETicTacToeMark::Empty, ETicTacToeMark::Empty, ETicTacToeMark::Empty};
        _vvGameField.push_back(a);
    }

    StartDialog();
}
//------------------------------------------------------------------
TicTacToe::~TicTacToe()
{
}
//------------------------------------------------------------------
// Функция считывания типа игрока из консоли
TicTacToe::EPlayerType TicTacToe::GetPlayerType(const string& str_request)
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
            i_res = stoi(str_income);
        }
        catch(invalid_argument& err)
        {
            cout << "\tОшибка: " << err.what() << ". Введённое значение не является корректным значением" << \
                endl;
        }
        i_res -= 1;
        if((static_cast<EPlayerType>(i_res) == EPlayerType::Human) ||
            (static_cast<EPlayerType>(i_res) == EPlayerType::Computer))
            b_convert_fault = false;
        else
            cout << "\tВведённое значение не является корректным значением" << endl;
    }
    while(b_convert_fault);

    return static_cast<EPlayerType>(i_res);
}
//------------------------------------------------------------------
// Запрос уровня сложности
int TicTacToe::GetAILevel()
{
    string str_income;
    bool b_convert_fault = true;
    int i_res;

    do
    {
        cout << "\nВведите уровень сложности:\n"
                "\t1 Лёгкий\n"
                "\t2 Средний\n"
                "\t3 Без шансов :)\n"
                "\t4 Случайный\n"
                "\tВведите номер: ";
        cin >> str_income;
        try
        {
            i_res = stoi(str_income);
        }
        catch(invalid_argument& err)
        {
            cout << "\tОшибка: " << err.what() << ". Введённое значение не является корректным значением" << endl;
        }
        if((i_res >= 1) && (i_res <= 4))
            b_convert_fault = false;
        else
            cout << "\tВведённое значение не является корректным значением" << endl;
    }
    while(b_convert_fault);

    if (i_res == 4)
        return rand() % 3;

    return i_res-1;
}
//------------------------------------------------------------------
// Функция считывания строки\столбца
int TicTacToe::GetCoord(const string& str_request)
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
            i_res = stoi(str_income);
        }
        catch(invalid_argument& err)
        {
            cout << "\tОшибка: " << err.what() << ". Введённое значение не является корректным значением" << \
                endl;
        }
        if((i_res >= 1) && (i_res <= 3))
            b_convert_fault = false;
        else
            cout << "\tВведённое значение не является корректным значением" << endl;
    }
    while(b_convert_fault);

    return i_res-1;
}
//------------------------------------------------------------------
// Поптка AI выиграть/предотвратить поражение одним ходом
pair<int, int> TicTacToe::AIAttempt(const bool bCurrentPlayerIsNotOne)
{
    for(auto i : {0, 1, 2})
        for(auto j : {0, 1, 2})
        {
            if(_vvGameField[i][j] == ETicTacToeMark::Empty)
            {
                _vvGameField[i][j] = static_cast<ETicTacToeMark>(static_cast<int>(bCurrentPlayerIsNotOne) + 1);
                if (CheckWin(pair(i,j)))
                {
                    _vvGameField[i][j] = ETicTacToeMark::Empty;
                    return pair(i, j);
                }
                _vvGameField[i][j] = ETicTacToeMark::Empty;
            }
        }
    return pair(-1, -1);
}
//------------------------------------------------------------------
// Координаты хода игрока компьютера
pair<int, int> TicTacToe::GetAICoord()
{
    pair<int, int> Coord;
    //Попытка выиграть одним ходом
    if (_AILevel > 0)
    {
        Coord = AIAttempt(_bCurrentPlayerIsNotOne);
        if (Coord.first != -1)
            return Coord;
    }
    // Попытка предотвратить выигрыш
    if (_AILevel == 2)
    {
        Coord = AIAttempt(!_bCurrentPlayerIsNotOne);
        if(Coord.first != -1)
            return Coord;
    }

    if (_vvGameField[1][1] == ETicTacToeMark::Empty)
        return pair(1, 1);
    if (_vvGameField[0][0] == ETicTacToeMark::Empty)
        return pair(0, 0);
    if (_vvGameField[2][2] == ETicTacToeMark::Empty)
        return pair(2, 2);
    if (_vvGameField[0][2] == ETicTacToeMark::Empty)
        return pair(0, 2);
    if (_vvGameField[2][0] == ETicTacToeMark::Empty)
        return pair(2, 0);

    do
    {
        Coord.first = rand() % 3;
        Coord.second = rand() % 3;
    }while(_vvGameField[Coord.first][Coord.second] != ETicTacToeMark::Empty);
    return Coord;
}
//------------------------------------------------------------------
//Стартовый диалог
void TicTacToe::StartDialog()
{
    Clear();
    cout << "Игра Крестики-нолики" << endl << endl;

    _PlayerTypeVector[0] = \
        GetPlayerType("Кто будет первым игроком?\n"
                "\t1 Человек\n"
                "\t2 Компьютер\n"
                "Введите номер: ");
    if (_PlayerTypeVector[0] == EPlayerType::Computer)
        _AILevel = GetAILevel();
    _PlayerTypeVector[1] = \
        GetPlayerType("\nКто будет вторым игроком?\n"
                "\t1 Человек\n"
                "\t2 Компьютер\n"
                "Введите номер: ");
    if (_PlayerTypeVector[1] == EPlayerType::Computer)
        _AILevel = GetAILevel();
}
//------------------------------------------------------------------
//Вывод игрового поля на экран
void TicTacToe::PrintField()
{
    Clear();
    cout << "\nХод " << _iTurnNumber << (_bCurrentPlayerIsNotOne ? " второго" : " первого") << \
        " игрока:" << endl << endl;
    cout << "\t-------------" << endl;
    for (int i = 0; i < _FieldSize; i++)
    {
        cout << "\t|";
        for (int j = 0; j < _FieldSize; j++)
        {
            switch(_vvGameField[i][j])
            {
                case ETicTacToeMark::Empty:
                    cout << "   |";
                    break;
                case ETicTacToeMark::XMark:
                    cout << " X |";
                    break;
                case ETicTacToeMark::OMark:
                    cout << " O |";
                    break;
            }
        }
        cout << endl << "\t-------------" << endl;
    }
}
//------------------------------------------------------------------
//Очистка экрана
void TicTacToe::Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}
//------------------------------------------------------------------
//Проверка на выигрыш
bool TicTacToe::CheckWin(pair<int, int>LastTurnCoord)
{
    if(((_vvGameField[LastTurnCoord.first][0] == _vvGameField[LastTurnCoord.first][1]) &&
            (_vvGameField[LastTurnCoord.first][1] == _vvGameField[LastTurnCoord.first][2]))     ||

            ((_vvGameField[0][LastTurnCoord.second] == _vvGameField[1][LastTurnCoord.second]) &&
            (_vvGameField[1][LastTurnCoord.second] == _vvGameField[2][LastTurnCoord.second]))   ||

            ((_vvGameField[LastTurnCoord.first][LastTurnCoord.second] == _vvGameField[0][0]) &&
            (_vvGameField[0][0] == _vvGameField[1][1]) &&
            (_vvGameField[1][1] == _vvGameField[2][2]))      ||

            ((_vvGameField[LastTurnCoord.first][LastTurnCoord.second] == _vvGameField[0][2]) &&
            (_vvGameField[0][2] == _vvGameField[1][1]) &&
            (_vvGameField[1][1] == _vvGameField[2][0])))
        return true;
    else
        return false;
}
//------------------------------------------------------------------
//Сделать ход
bool TicTacToe::MakeTurn()
{
    PrintField();
    pair<int, int> LastTurn;
    if(_PlayerTypeVector[_bCurrentPlayerIsNotOne] == EPlayerType::Human)
    {
        cout << "\nХод " << (_bCurrentPlayerIsNotOne ? "второго" : "первого") << " игрока:" << endl;
        do{
            LastTurn.first = GetCoord("\tВведите номер строки (1-3): ");
            LastTurn.second = GetCoord("\tВведите номер столбца (1-3): ");
            if(_vvGameField[LastTurn.first][LastTurn.second] != ETicTacToeMark::Empty)
                cout << "\tПоле занято!" << endl;
        }while(_vvGameField[LastTurn.first][LastTurn.second] != ETicTacToeMark::Empty);
    }
    else
        LastTurn = GetAICoord();
    _vvGameField[LastTurn.first][LastTurn.second] = \
        static_cast<ETicTacToeMark>(static_cast<int>(_bCurrentPlayerIsNotOne) + 1);
    _iEmptyFieldsCount--;
    PrintField();

    if (CheckWin(LastTurn))
    {
        cout << "\nИгрок " << (_bCurrentPlayerIsNotOne ? "2" : "1") << " победил!!!" << endl;
        return true;
    }
    else if(!_iEmptyFieldsCount)
    {
        cout << "\nВсе поля заняты. Ничья! :(" << endl;
        return true;
    }
    else
    {
        if (_bCurrentPlayerIsNotOne)
            _iTurnNumber++;
        _bCurrentPlayerIsNotOne = !_bCurrentPlayerIsNotOne;
        return false;
    }
}
//------------------------------------------------------------------
