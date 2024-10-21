#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int countOddElements(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}

void Create(int *a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

#ifndef UNIT_TESTING

int main()
{
    srand((unsigned)time(0)); // Ініціалізація генератора випадкових чисел

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