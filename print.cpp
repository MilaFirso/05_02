#include "print.h"

//Печать исходного массива
void PrintArray(int* arr, const int arrSize)
{
    std::cout << "Исходный массив:";

    for (int i = 0; i < arrSize; i++)
    {
        std::cout << " ";
        std::cout << arr[i];
    };
    std::cout << std::endl;
};

//Определение на каком уровне тот или иной индекс пирамиды
int PyramidLevelNow(int* levelOfpyramid, const int countLevelsOfPyramid, int i)
{
    for (int j = 0; j < countLevelsOfPyramid; j++)
    {
        if (i < levelOfpyramid[j])
        {
            return j + 1;
        }
    };
    return EXIT_FAILURE;
};

//Печать пирамиды
void PrintPyramid(int* arr, const int arrSize, int* levelOfpyramid, const int countLevelsOfPyramid)
{
    std::cout << "Пирамида:\n";
    std::cout << "Уровень: 0. Root.\t " << arr[0] << std::endl;

    // Заполняем массив конечными числами уровней пирамиды
    for (int i = 0; i < countLevelsOfPyramid; i++)
    {
        levelOfpyramid[i] = pow(2, i);
    }

    for (int i = 0; i < arrSize; i++)
    {
        int indexLeft = 2 * i + 1;
        if (indexLeft < arrSize)
        {
            std::cout << "Уровень: " << PyramidLevelNow(levelOfpyramid, countLevelsOfPyramid, i) << ". Left(" << arr[i] << ")" << ".\t " << arr[2 * i + 1] << std::endl;
        }

        int indexRight = 2 * i + 2;
        if (indexRight < arrSize)
        {
            std::cout << "Уровень: " << PyramidLevelNow(levelOfpyramid, countLevelsOfPyramid, i) << ". Right(" << arr[i] << ")" << ".\t " << arr[2 * i + 2] << std::endl;
        }
    }
    std::cout << std::endl;
};