#include <iostream>
#include <fstream>
#include "DynamicArray.h"
DynamicArray<int> getMatrixFromFile(std::fstream&);
int** convertToDiagonalFormat(DynamicArray<int>&);
void autoInput();
void manualInput();
void convertToCCS(int**, DynamicArray<int>);
int main()
{
    int choice;
    std::cout << "Autoinput(1) or manual(2)?: ";
    std::cin >> choice;
    if (choice == 1)
    {
        autoInput();
    }
    else if (choice == 2)
    {
        manualInput();
    }
    else
    {
        throw std::string("input error");
    }
    return 0;
}
//------------------------------------------------------------------------
void manualInput()
{
    int rc;
    DynamicArray<int> firstMatrix, secondMatrix;
    std::cin >> rc;
    if (rc <= 1)
    {
        throw std::string("err");
    }
    std::cout << "first matrix input:\n";
    for (int i = 0, value; i < rc * rc; i++)
    {
        std::cin >> value;
        firstMatrix.push(value);
    }
    std::cout << "\nSecond matrix input:\n";
    for (int i = 0, value; i < rc * rc; i++)
    {
        std::cin >> value;
        secondMatrix.push(value);
    }
    firstMatrix.print();
    secondMatrix.print();
    // Сложение матриц
    for (int i = 0; i < (firstMatrix.numColumns * firstMatrix.numRows); i++)
    {
        firstMatrix.setValue(i, secondMatrix.at(i) + firstMatrix.at(i));
    }
    firstMatrix.print();
    int** array = convertToDiagonalFormat(firstMatrix);

    convertToCCS(array, firstMatrix);
}
//------------------------------------------------------------------------
void autoInput()
{
    std::fstream firstMatrixFile, secondMatrixFile;
    firstMatrixFile.open("firstMatrix.txt");
    secondMatrixFile.open("secondMatrix.txt");
    DynamicArray<int> firstMatrix, secondMatrix;
    firstMatrix = getMatrixFromFile(firstMatrixFile);
    secondMatrix = getMatrixFromFile(secondMatrixFile);
    firstMatrix.print();
    secondMatrix.print();
    // Сложение матриц
    for (int i = 0; i < (firstMatrix.numColumns * firstMatrix.numRows); i++)
    {
        firstMatrix.setValue(i, secondMatrix.at(i) + firstMatrix.at(i));
    }
    firstMatrix.print();
    int** array = convertToDiagonalFormat(firstMatrix);

    convertToCCS(array, firstMatrix);
}
//------------------------------------------------------------------------
void convertToCCS(int** array, DynamicArray<int> matrix)
{
    int countA = 0;
    std::cout << "Massive A: ";
    for (int i = 0; i < (matrix.numRows * 2 - 1); i++)
    {
        for (int j = 0; j < matrix.numRows; j++)
        {
            if (array[i][j] != 0)
            {
                //std::cout << array[i][j] <<" ";
                countA++;
            }
        }
    }
    int* A = new int[countA];
    for (int i = 0, f = 0; i < (matrix.numRows * 2 - 1); i++)
    {
        for (int j = 0; j < matrix.numRows; j++)
        {
            if (array[i][j] != 0)
            {
                A[f++] = array[i][j];
                std::cout << A[f-1] << " ";
            }
        }
    }
    std::cout << std::endl;
    std::cout << "Massive LI: ";
    int* LI = new int[countA];
    int mainIndex = matrix.numRows - 1;
    for (int j = mainIndex, i = 0, asd = 0; j < (matrix.numRows * 2 - 1); j++)
    {
        for (int g = j, f = 0; f < matrix.numRows; f++, g--)
        {
            if (array[g][f] != 0)
            {
                LI[asd++] = f + 1;
                std::cout << LI[asd - 1] << " ";
            }
        }
    }
    std::cout << std::endl;
    std::cout << "Massive LJ: ";
    int* LJ = new int[countA];
    for (int j = mainIndex, i = 0, asd = 0; j < (matrix.numRows * 2 - 1); j++)
    {
        for (int g = j, f = 0; f < matrix.numRows; f++, g--)
        {
            if (array[g][f] != 0)
            {
                LJ[asd++] = f + 1;
                std::cout << LJ[asd - 1] << " ";
                break;
            }
        }
    }
    // Заполнение верхнего треугольника
}
//------------------------------------------------------------------------
DynamicArray<int> getMatrixFromFile(std::fstream& inputFile)
{
    int numRows, numColumns, number;
    inputFile >> numRows >> numColumns;
    if (numRows != numColumns)
    {
        throw std::string("input error");
    }
    DynamicArray<int> array;
    for (int i = 0; i < numRows * numColumns; i++)
    {
        inputFile >> number;
        array.push(number);
    }
    array.numRows = numRows;
    array.numColumns = numColumns;
    return array;
}
//------------------------------------------------------------------------
DynamicArray<int> foldMatrices(DynamicArray<int> firstMatrix, DynamicArray<int> secondMatrix)
{
    DynamicArray<int> summa;
    if ((firstMatrix.numColumns != secondMatrix.numColumns) || (firstMatrix.numRows != secondMatrix.numColumns))
    {
        throw std::string("BRUH");
    }
    summa.numColumns = firstMatrix.numColumns;
    summa.numRows = firstMatrix.numRows;
    for (int i = 0; i < firstMatrix.size(); i++)
    {
        summa.push(firstMatrix.at(i) + secondMatrix.at(i));
    }
    return summa;
}
//------------------------------------------------------------------------
int** convertToDiagonalFormat(DynamicArray<int>& matrix)
{
    int size = (matrix.numRows * 2) - 1;
    int mainIndex = matrix.numRows - 1;
    int* indexes = new int[size];
    for (int i = 0, j = -(matrix.numRows - 1); i < size; i++, j++)
    {
        indexes[i] = j;
    }
    // вывод массива индексов (не отредактированного)
    for (int i = 0; i < size; i++)
    {
        //std::cout << indexes[i]<< " ";
    }
    // создание массива в котором будут храниться ВСЕ диагонали
    int** array = new int* [size + 1];
    for (int i = 0; i < size; i++)
    {
        array[i] = new int[matrix.numRows]{};
    }
    // главная диагональ
    for (int i = 0; i < matrix.numRows; i++)
    {
        array[mainIndex][i] = matrix.at(i * matrix.numRows + i);
    }
    // Заполнение нижнего треугольника
    for (int g = 1; g < (matrix.numRows); g++)
    {
        for (int i = g, f = g, j = 0; i < matrix.numRows; i++, f++, j++)
        {
            array[mainIndex - g][f] = matrix.at(i * matrix.numRows + j);
        }
    }
    // Заполнение верхнего треугольника
    for (int g = 1; g < (matrix.numRows); g++)
    {
        for (int i = 0, f = 0, j = g; j < matrix.numRows; i++, f++, j++)
        {
            array[mainIndex + g][f] = matrix.at(i * matrix.numRows + j);
        }
    }
    // подсчет ненулевых диагоналей
    int countNotZeroIndexes = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < matrix.numRows; j++)
        {
            if (array[i][j] != 0)
            {
                countNotZeroIndexes++;
                break;
            }
        }
    }
    //int *NotZeroindexes = new int[countNotZeroIndexes];
    array[size + 1] = new int[countNotZeroIndexes];
    // Ввод индексов ненулевых диагоналей
    for (int i = 0, ii = 0; i < size; i++)
    {
        bool isNull = true;
        for (int j = 0; j < matrix.numRows; j++)
        {
            if (array[i][j] != 0)
            {
                isNull = false;
                break;
            }
        }
        if (!isNull)
        {
            array[size + 1][ii++] = indexes[i];
        }
    }
    // вывод ненулевых индексов
    for (int i = 0; i < countNotZeroIndexes; i++)
    {
        //std::cout<< array[size + 1][i] << std::endl;
    }
    // Вывод всех диагоналей
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < matrix.numRows; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return array;
}