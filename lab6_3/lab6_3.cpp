
#include <iostream>
#include <iomanip>

using namespace std;

void Create(int *a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

template <typename T>
void Createtemplate(T *a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int *a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

template <typename T>

void Printtemplate(T *a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int SumEvenElements(int *a, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 == 0)
        {
            sum += a[i];
        }
    }
    return sum;
}

template <typename T>
// Функція для обчислення суми парних елементів масиву
int SumEvenElementstemplate(T *a, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 == 0)
        {
            sum += a[i];
        }
    }
    return sum;
}

#ifndef UNIT_TESTING

int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    int *a = new int[n];

    Create(a, n, -10, 10);
    Print(a, n);

    int sumEven = SumEvenElements(a, n);
    cout << "Sum of even elements = " << sumEven << endl;

    Createtemplate(a, n, -10, 10);
    Printtemplate(a, n);

    int sumEventemplate = SumEvenElementstemplate(a, n);
    cout << "Sum of even elements = " << sumEven << endl;

    delete[] a;
}

#endif