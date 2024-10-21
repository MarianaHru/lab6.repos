#include <iostream>
#include <vector>

using namespace std;

// Функція для добутку елементів з парними номерами
// int productOfEvenIndices(const vector<int> &arr)
// {
//     int product = 1;
//     for (size_t i = 0; i < arr.size(); i += 2)
//     {
//         product *= arr[i];
//     }
//     return product;
// }

// Функція для добутку елементів з парними номерами
int productOfEvenIndices(const vector<int> &arr)
{
    // Якщо масив порожній, повертаємо 1
    if (arr.empty())
        return 1;

    int product = 1;
    bool hasNonZeroElement = false; // Для перевірки наявності ненульових елементів

    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] != 0)
        {
            product *= arr[i];        // Множимо лише ненульові елементи
            hasNonZeroElement = true; // Знайдено ненульовий елемент
        }
    }

    // Якщо не було жодного ненульового парного індексу, повертаємо 0
    return hasNonZeroElement ? product : 0;
}

// Функція для суми елементів між першим і останнім нульовими елементами
int sumBetweenZeroes(const vector<int> &arr)
{
    int firstZero = -1, lastZero = -1;
    int sum = 0;

    // Знайдемо індекси першого і останнього нуля
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            if (firstZero == -1)
            {
                firstZero = i;
            }
            lastZero = i;
        }
    }

    // Якщо знайшли два нулі, підраховуємо суму між ними
    if (firstZero != -1 && lastZero != -1 && firstZero != lastZero)
    {
        for (int i = firstZero + 1; i < lastZero; i++)
        {
            sum += arr[i];
        }
    }
    return sum;
}

// Функція для перестановки додатних елементів на початок масиву
void rearrangeArray(vector<int> &arr)
{
    vector<int> positive, nonPositive;

    // Поділяємо масив на додатні і всі інші
    for (int elem : arr)
    {
        if (elem >= 0)
        {
            positive.push_back(elem);
        }
        else
        {
            nonPositive.push_back(elem);
        }
    }

    // Об'єднуємо два масиви: додатні спочатку, потім решта
    arr.clear();
    arr.insert(arr.end(), positive.begin(), positive.end());
    arr.insert(arr.end(), nonPositive.begin(), nonPositive.end());
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

    // 1. Добуток елементів з парними номерами
    cout << "Добуток елементів з парними номерами: " << productOfEvenIndices(arr) << endl;

    // 2. Сума між першим і останнім нульовими елементами
    cout << "Сума між першим і останнім нульовими елементами: " << sumBetweenZeroes(arr) << endl;

    // 3. Перестановка додатних елементів на початок
    rearrangeArray(arr);
    cout << "Перетворений масив: ";
    for (int elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

#endif
