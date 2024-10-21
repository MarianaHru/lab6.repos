#ifndef LAB6_4_rec_H
#define LAB6_4_rec_H

#include <vector>

// Рекурсивна функція для добутку елементів з парними номерами
int productOfEvenIndices(const std::vector<int> &arr, int index = 0);

// Рекурсивна функція для знаходження першого нуля
int findFirstZero(const std::vector<int> &arr, int index = 0);

// Рекурсивна функція для знаходження останнього нуля
int findLastZero(const std::vector<int> &arr, int index);

// Рекурсивна функція для обчислення суми між першим і останнім нулями
int sumBetweenZeroes(const std::vector<int> &arr, int firstZero, int lastZero, int index = 0);

// Рекурсивна функція для перестановки додатних елементів на початок масиву
void rearrangeArray(const std::vector<int> &arr, std::vector<int> &positive, std::vector<int> &nonPositive, int index = 0);

#endif
