
#include <iostream>
#include <iomanip>

using namespace std;

int Sum(int *a, const int size, int s, int i)
{
    if (i < size)
    {
        if (a[i] % 2 == 0)
            return Sum(a, size, s + a[i], i + 1);
        else
            return Sum(a, size, s, i + 1);
    }
    return s;
}

void Create(int *a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int *a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

#ifndef UNIT_TESTING

int main()
{
    int c;
    cout << "n = ";
    cin >> c;

    int *a = new int[c];

    Create(a, c, -10, 10, 0);
    Print(a, c, 0);

    int s = Sum(a, c, s, 0);
    cout << "s = " << s << endl;
}

#endif