#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int countOddElements(int a[], int n)
{
    if (n == 0)
        return 0;

    return (a[n - 1] % 2 != 0) + countOddElements(a, n - 1);
}

void Create(int *a, const int size, const int Low, const int High, int index = 0)
{
    if (index == size)
        return;

    a[index] = Low + rand() % (High - Low + 1);

    Create(a, size, Low, High, index + 1);
}

#ifndef UNIT_TESTING

int main()
{
    srand((unsigned)time(0));

    int n;
    int Low, High;

    cout << "Введіть кількість елементів у масиві: ";
    cin >> n;

    // Створення масиву динамічно
    int *a = new int[n];

    cout << "Введіть нижню межу (Low): ";
    cin >> Low;
    cout << "Введіть верхню межу (High): ";
    cin >> High;

    // Генерація масиву з випадковими числами (рекурсивно)
    Create(a, n, Low, High);

    cout << "Згенерований масив: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Кількість непарних елементів: " << countOddElements(a, n) << endl;

    delete[] a;

    return 0;
}

#endif