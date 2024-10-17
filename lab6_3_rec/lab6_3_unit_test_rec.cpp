#include <gtest/gtest.h>
#include "lab6_3_rec.h"

// Тест для функції Sum
TEST(ArrayTest, SumEvenElements)
{
    int arr1[] = {2, 4, 6, 8, 10}; // Сума: 30
    int arr2[] = {1, 3, 5, 7};     // Сума: 0 (немає парних)
    int arr3[] = {-2, 2, -4, 6};   // Сума: 6 (немає -4)
    int arr4[] = {0};              // Сума: 0 (один парний)

    EXPECT_EQ(Sum(arr1, 5, 0, 0), 30);
    EXPECT_EQ(Sum(arr2, 4, 0, 0), 0);
    EXPECT_EQ(Sum(arr3, 4, 0, 0), 2);
    EXPECT_EQ(Sum(arr4, 1, 0, 0), 0);
}

// Тест для функції Create
TEST(ArrayTest, CreateArrayWithinRange)
{
    const int size = 10;
    const int Low = -10;
    const int High = 10;
    int arr[size];

    Create(arr, size, Low, High, 0);

    for (int i = 0; i < size; ++i)
    {
        EXPECT_GE(arr[i], Low);  // Перевіряємо, що значення не менше ніж Low
        EXPECT_LE(arr[i], High); // Перевіряємо, що значення не більше ніж High
    }
}

// Основна функція для запуску тестів
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
