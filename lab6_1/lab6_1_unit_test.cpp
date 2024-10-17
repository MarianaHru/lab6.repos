#include <gtest/gtest.h>
#include "./lab6_1.h"

const int TEST_SIZE = 10;
const int TEST_MIN_VALUE = -50;
const int TEST_MAX_VALUE = 15;

// Тест для функції generateArray
TEST(ArrayTest, GenerateArray)
{
    int arr[TEST_SIZE];
    generateArray(arr, TEST_SIZE);

    for (int i = 0; i < TEST_SIZE; ++i)
    {
        EXPECT_GE(arr[i], TEST_MIN_VALUE);
        EXPECT_LE(arr[i], TEST_MAX_VALUE);
    }
}

// Тест для функції processArray
TEST(ArrayTest, ProcessArray)
{
    int arr[TEST_SIZE] = {-5, 2, 0, -3, 4, 6, 7, -2, 1, 10};
    int count, sum;

    int expectedCount = 5;                      // Кількість елементів, що < 0 або непарні
    int expectedSum = -5 + (-3) + 7 + 1 + (-2); // Сума таких елементів

    int result = processArray(arr, TEST_SIZE, count, sum);

    EXPECT_EQ(count, expectedCount);
    EXPECT_EQ(sum, expectedSum);
    EXPECT_EQ(result, expectedSum);
}

// Тест для функції replaceElements
TEST(ArrayTest, ReplaceElements)
{
    int arr[TEST_SIZE] = {-5, 2, 0, -3, 4, 6, 7, -2, 1, 10};
    int expectedArr[TEST_SIZE] = {0, 2, 0, 0, 4, 6, 0, 0, 0, 10};

    replaceElements(arr, TEST_SIZE);

    for (int i = 0; i < TEST_SIZE; ++i)
    {
        EXPECT_EQ(arr[i], expectedArr[i]);
    }
}

// Основна функція для запуску тестів
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
