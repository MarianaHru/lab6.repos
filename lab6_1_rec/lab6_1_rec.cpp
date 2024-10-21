// #include <iostream>
// #include <iomanip>
// #include <random>

// using namespace std;

// void generateArray(int arr[], int size, int min_value, int max_value)
// {
//     random_device rd;
//     mt19937 generator(rd());
//     uniform_int_distribution<int> distribution(min_value, max_value);

//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = distribution(generator);
//     }
// }

// void printArray(const int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         cout << setw(4) << arr[i];
//     }
//     cout << endl;
// }

// void countAndSumElements(const int arr[], int size, int &count, int &sum)
// {
//     count = 0;
//     sum = 0;

//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] < 0 || arr[i] % 2 != 0)
//         {
//             count++;
//             sum += arr[i];
//         }
//     }
// }

// void replaceSpecificElements(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] < 0 || arr[i] % 2 != 0)
//         {
//             arr[i] = 0;
//         }
//     }
// }

// #ifndef UNIT_TESTING

// int main()
// {
//     const int SIZE = 24;
//     const int MIN_VALUE = -50;
//     const int MAX_VALUE = 15;

//     int array[SIZE];
//     int count, sum;

//     generateArray(array, SIZE, MIN_VALUE, MAX_VALUE);

//     cout << "Initial array:" << endl;
//     printArray(array, SIZE);

//     countAndSumElements(array, SIZE, count, sum);
//     cout << "\nNumber of elements satisfying the criterion: " << count << endl;
//     cout << "Sum of elements satisfying the criterion: " << sum << endl;

//     replaceSpecificElements(array, SIZE);

//     cout << "Modified array:" << endl;
//     printArray(array, SIZE);

//     return 0;
// }

// #endif

#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

const int SIZE = 24;
const int MIN_VALUE = -50;
const int MAX_VALUE = 15;

// Рекурсивна функція для генерації масиву
void generateArray(int arr[], int size, int i = 0)
{
    if (i == 0) // Генерація нового генератора випадкових чисел один раз на початку
    {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);

        arr[i] = distribution(generator);
    }

    if (i < size - 1)
    {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);

        arr[i] = distribution(generator);
        generateArray(arr, size, i + 1);
    }
}

// Рекурсивна функція для виведення масиву
void printArray(const int arr[], int size, int i = 0)
{
    if (i < size)
    {
        cout << setw(4) << arr[i];
        printArray(arr, size, i + 1);
    }
    else
    {
        cout << endl;
    }
}

// Рекурсивна функція для обробки масиву (підрахунок і сума елементів)
int processArray(const int arr[], int size, int &count, int &sum, int i = 0)
{
    if (i == 0)
    {
        count = 0;
        sum = 0;
    }

    if (i < size)
    {
        if (arr[i] < 0 || arr[i] % 2 != 0)
        {
            ++count;
            sum += arr[i];
        }
        return processArray(arr, size, count, sum, i + 1);
    }

    return sum;
}

// Рекурсивна функція для заміни специфічних елементів
void replaceElements(int arr[], int size, int i = 0)
{
    if (i < size)
    {
        if (arr[i] < 0 || arr[i] % 2 != 0)
        {
            arr[i] = 0;
        }
        replaceElements(arr, size, i + 1);
    }
}

#ifndef UNIT_TESTING

int main()
{
    int a[SIZE], count, sum;

    generateArray(a, SIZE);

    cout << "Initial array:" << endl;
    printArray(a, SIZE);

    processArray(a, SIZE, count, sum);

    replaceElements(a, SIZE);

    cout << "\nNumber of elements satisfying the criterion: " << count << endl;
    cout << "Sum of elements satisfying the criterion: " << sum << endl;

    cout << "Modified array:" << endl;
    printArray(a, SIZE);

    return 0;
}

#endif
