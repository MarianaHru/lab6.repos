#include <gtest/gtest.h>
#include "./lab6_2.h"

// Тест для функції countOddElements
TEST(ArrayTest, CountOddElements)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expectedCount = 5; // Непарні числа: 1, 3, 5, 7, 9

    EXPECT_EQ(countOddElements(arr, 10), expectedCount);
}

// Тест для функції Create
TEST(ArrayTest, CreateArrayWithinRange)
{
    const int TEST_SIZE = 10;
    const int LOW = -10;
    const int HIGH = 10;
    int arr[TEST_SIZE];

    srand(1); // Фіксована seed для передбачуваності результатів
    Create(arr, TEST_SIZE, LOW, HIGH);

    for (int i = 0; i < TEST_SIZE; ++i)
    {
        EXPECT_GE(arr[i], LOW);
        EXPECT_LE(arr[i], HIGH);
    }
}

// Основна функція для запуску тестів
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
