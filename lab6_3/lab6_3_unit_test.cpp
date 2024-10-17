#include <gtest/gtest.h>
#include "lab6_3.h"

// Тест для функції Create
TEST(ArrayTest, CreateArrayWithinRange)
{
    const int size = 10;
    const int Low = -10;
    const int High = 10;
    int arr[size];

    Create(arr, size, Low, High);

    for (int i = 0; i < size; ++i)
    {
        EXPECT_GE(arr[i], Low);  // Перевіряємо, що значення не менше ніж Low
        EXPECT_LE(arr[i], High); // Перевіряємо, що значення не більше ніж High
    }
}

// Тест для функції SumEvenElements
TEST(ArrayTest, SumEvenElements)
{
    int arr1[] = {2, 4, 6, 8, 10}; // Сума: 30
    int arr2[] = {-2, 3, 5, -6};   // Сума: -8
    int arr3[] = {1, 3, 5, 7, 9};  // Сума: 0 (немає парних)

    EXPECT_EQ(SumEvenElements(arr1, 5), 30);
    EXPECT_EQ(SumEvenElements(arr2, 4), -8);
    EXPECT_EQ(SumEvenElements(arr3, 5), 0);
}

// Основна функція для запуску тестів
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
