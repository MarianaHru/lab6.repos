

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int countOddElements(int a[], int n, int i = 0)
{
    if (i == n)
        return 0;
    // Рекурсивний випадок: перевіряємо, чи непарний елемент і додаємо до результату
    return (a[i] % 2 != 0) + countOddElements(a, n, i + 1);
}

void Create(int *a, const int size, const int Low, const int High, int i = 0)
{
    if (i == size)
        return;

    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, i + 1);
}

void PrintArray(const int *a, const int size, int i = 0)
{
    if (i == size)
        return;

    cout << a[i] << " ";
    PrintArray(a, size, i + 1);
}

#ifndef UNIT_TESTING

int main()
{
    srand((unsigned)time(0));

    int n;
    int Low, High;

    cout << "Введіть кількість елементів у масиві: ";
    cin >> n;

    int *a = new int[n];

    cout << "Введіть нижню межу (Low): ";
    cin >> Low;
    cout << "Введіть верхню межу (High): ";
    cin >> High;

    Create(a, n, Low, High);

    cout << "Згенерований масив: ";
    PrintArray(a, n);
    cout << endl;

    cout << "Кількість непарних елементів: " << countOddElements(a, n) << endl;

    delete[] a;

    return 0;
}

#endif
