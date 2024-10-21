// #ifndef LAB6_1_H
// #define LAB6_1_H

// void generateArray(int arr[], int size, int min_value, int max_value);
// void printArray(const int arr[], int size);
// void countAndSumElements(const int arr[], int size, int &count, int &sum);
// void replaceSpecificElements(int arr[], int size);

// #endif

#ifndef LAB6_1_REC_H
#define LAB6_1_REC_H

#include <cstdlib> // для rand()

// Функція для генерації масиву з випадковими числами (рекурсивно)
void generateArray(int *arr, int size, int Low, int High, int i = 0)
{
    if (i < size)
    {
        arr[i] = Low + rand() % (High - Low + 1);
        generateArray(arr, size, Low, High, i + 1);
    }
}

// Функція для підрахунку кількості елементів < 0 або непарних, і обчислення їх суми (рекурсивно)
void countAndSumElements(int *arr, int size, int &count, int &sum, int i = 0)
{
    if (i < size)
    {
        if (arr[i] < 0 || arr[i] % 2 != 0)
        {
            count++;
            sum += arr[i];
        }
        countAndSumElements(arr, size, count, sum, i + 1);
    }
}

// Функція для заміни непарних і від'ємних елементів на нуль (рекурсивно)
void replaceSpecificElements(int *arr, int size, int i = 0)
{
    if (i < size)
    {
        if (arr[i] < 0 || arr[i] % 2 != 0)
        {
            arr[i] = 0;
        }
        replaceSpecificElements(arr, size, i + 1);
    }
}

#endif // LAB6_1_REC_H
