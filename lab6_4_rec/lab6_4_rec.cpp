#include <iostream>
#include <vector>

using namespace std;

// Рекурсивна функція для добутку елементів з парними номерами
int productOfEvenIndices(const vector<int> &arr, int index = 0)
{
    if (index >= arr.size())
    {
        return 1; // Базовий випадок: повертаємо 1, коли індекс виходить за межі масиву
    }
    return arr[index] * productOfEvenIndices(arr, index + 2); // Рекурсія через кожні 2 індекси
}

// Рекурсивна функція для знаходження першого нуля
int findFirstZero(const vector<int> &arr, int index = 0)
{
    if (index >= arr.size())
    {
        return -1; // Базовий випадок: якщо не знайдено, повертаємо -1
    }
    return arr[index] == 0 ? index : findFirstZero(arr, index + 1); // Рекурсія до першого нуля
}

// Рекурсивна функція для знаходження останнього нуля
int findLastZero(const vector<int> &arr, int index)
{
    if (index < 0)
    {
        return -1; // Базовий випадок: якщо не знайдено, повертаємо -1
    }
    return arr[index] == 0 ? index : findLastZero(arr, index - 1); // Рекурсія до останнього нуля
}

// Рекурсивна функція для обчислення суми між першим і останнім нулями
int sumBetweenZeroes(const vector<int> &arr, int firstZero, int lastZero, int index = 0)
{
    if (index >= lastZero)
    {
        return 0; // Базовий випадок: якщо індекс досяг кінця діапазону, повертаємо 0
    }
    return index > firstZero ? arr[index] + sumBetweenZeroes(arr, firstZero, lastZero, index + 1)
                             : sumBetweenZeroes(arr, firstZero, lastZero, index + 1);
}

// Рекурсивна функція для перестановки додатних елементів на початок масиву
void rearrangeArray(const vector<int> &arr, vector<int> &positive, vector<int> &nonPositive, int index = 0)
{
    if (index >= arr.size())
    {
        return; // Базовий випадок: закінчили обхід масиву
    }
    if (arr[index] >= 0)
    {
        positive.push_back(arr[index]); // Якщо елемент додатній, додаємо його в масив додатніх
    }
    else
    {
        nonPositive.push_back(arr[index]); // Якщо елемент від'ємний, додаємо його в масив недодатніх
    }
    rearrangeArray(arr, positive, nonPositive, index + 1); // Рекурсія на наступний індекс
}

#ifndef UNIT_TESTING

int main()
{
    // Ініціалізація динамічного масиву
    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // 1. Добуток елементів з парними номерами (рекурсивно)
    cout << "Добуток елементів з парними номерами: " << productOfEvenIndices(arr) << endl;

    // 2. Сума між першим і останнім нульовими елементами (рекурсивно)
    int firstZero = findFirstZero(arr);
    int lastZero = findLastZero(arr, arr.size() - 1);

    if (firstZero != -1 && lastZero != -1 && firstZero != lastZero)
    {
        cout << "Сума між першим і останнім нульовими елементами: "
             << sumBetweenZeroes(arr, firstZero, lastZero) << endl;
    }
    else
    {
        cout << "Неможливо обчислити суму: недостатньо нулів." << endl;
    }

    // 3. Перестановка додатних елементів на початок (рекурсивно)
    vector<int> positive, nonPositive;
    rearrangeArray(arr, positive, nonPositive);

    // Виведення результату
    cout << "Перетворений масив: ";
    for (int elem : positive)
    {
        cout << elem << " ";
    }
    for (int elem : nonPositive)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

#endif
