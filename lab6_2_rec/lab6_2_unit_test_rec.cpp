#include <gtest/gtest.h>
#include "./lab6_2_rec.h"

// Тест для функції countOddElements
TEST(ArrayTest, CountOddElements)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expectedCount = 5; // Непарні числа: 1, 3, 5, 7, 9

    EXPECT_EQ(countOddElements(arr, 10), expectedCount);
}

// Тест для рекурсивної функції Create
TEST(ArrayTest, CreateArrayWithinRange)
{
    const int TEST_SIZE = 10;
    const int Low = -10; // Змінив назву на "Low"
    const int High = 10; // Змінив назву на "High"
    int arr[TEST_SIZE];

    srand(1);                             // Фіксована seed для передбачуваності результатів
    Create(arr, TEST_SIZE, Low, High, 0); // Передаємо всі аргументи, включаючи індекс

    for (int i = 0; i < TEST_SIZE; ++i)
    {
        EXPECT_GE(arr[i], Low);  // Використовуємо "Low"
        EXPECT_LE(arr[i], High); // Використовуємо "High"
    }
}

// Основна функція для запуску тестів
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
