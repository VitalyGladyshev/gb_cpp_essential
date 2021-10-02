//
// Created by vitaly on 02.10.2021.
//

#ifndef GB_CPP_ESSENTIAL_DATACUBE_H
#define GB_CPP_ESSENTIAL_DATACUBE_H

#define DATACUBE_SIZE 3

//Класс Куб данных с фиксированным размером 3
//Предназначен для хранения целых положительных значений
class DataCube{
public:
    DataCube();
    ~DataCube();

    /**
     * Метод для задания значени элементу
     * @param iLevel "уровень" куба
     * @param iRow строка
     * @param iColumn колонка в строке
     * @return содержимое ячейки или код ошибки -1
     */
    int GetItem(const unsigned int iLevel, const unsigned int iRow, const unsigned int iColumn) const;


    /**
     * Метод для получения значения элемента
     * @param iLevel "уровень" куба
     * @param iRow строка
     * @param iColumn колонка в строке
     * @param iItem Элемент для записи
     * @return код 0 если успешно или код ошибки -1
     */
    int SetItem(const unsigned int iLevel, unsigned const int iRow, const unsigned int iColumn,
                 const unsigned int iItem);

    /**
     * Метод для вывода на экран
     */
    void PrintDataCube() const;

private:
    int*** _pppiDataCube;
    int _iDataCubeSize = DATACUBE_SIZE;
};

#endif //GB_CPP_ESSENTIAL_DATACUBE_H
