#include <iostream>
#include "print.h"
#include "journeyThroughThePyramid.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    
   // int arr[] = { 1, 3, 6, 5, 9, 8 };

    int arr[] = {94, 67, 18, 44, 55, 12, 6, 42};
    //int arr[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int arrSize = std::size(arr);


  
    PrintArray(arr, arrSize);

    int countLevelsOfPyramid = log2(arrSize) + 1;
    int* levelOfpyramid = new int[countLevelsOfPyramid];

    PrintPyramid(arr, arrSize, levelOfpyramid, countLevelsOfPyramid);

    journeyThroughThePyramid(arr, arrSize, levelOfpyramid, countLevelsOfPyramid);


    delete[] levelOfpyramid;  // Удаляем массив
    

    
    
}