#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

void generateArray(int arr[], int size, int min_value, int max_value)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(min_value, max_value);

    for (int i = 0; i < size; i++)
    {
        arr[i] = distribution(generator);
    }
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

void countAndSumElements(const int arr[], int size, int &count, int &sum)
{
    count = 0;
    sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0 || arr[i] % 2 != 0)
        {
            count++;
            sum += arr[i];
        }
    }
}

void replaceSpecificElements(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0 || arr[i] % 2 != 0)
        {
            arr[i] = 0;
        }
    }
}

#ifndef UNIT_TESTING

int main()
{
    const int SIZE = 24;
    const int MIN_VALUE = -50;
    const int MAX_VALUE = 15;

    int array[SIZE];
    int count, sum;

    generateArray(array, SIZE, MIN_VALUE, MAX_VALUE);

    cout << "Initial array:" << endl;
    printArray(array, SIZE);

    countAndSumElements(array, SIZE, count, sum);
    cout << "\nNumber of elements satisfying the criterion: " << count << endl;
    cout << "Sum of elements satisfying the criterion: " << sum << endl;

    replaceSpecificElements(array, SIZE);

    cout << "Modified array:" << endl;
    printArray(array, SIZE);

    return 0;
}

#endif