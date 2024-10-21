// #include <gtest/gtest.h>
// #include "./lab6_1_rec.h"

// const int TEST_SIZE = 10;
// const int TEST_MIN_VALUE = -50;
// const int TEST_MAX_VALUE = 15;

// // Тест для функції generateArray
// TEST(ArrayTest, GenerateArray)
// {
//     int arr[TEST_SIZE];
//     generateArray(arr, TEST_SIZE, TEST_MIN_VALUE, TEST_MAX_VALUE);

//     for (int i = 0; i < TEST_SIZE; ++i)
//     {
//         EXPECT_GE(arr[i], TEST_MIN_VALUE);
//         EXPECT_LE(arr[i], TEST_MAX_VALUE);
//     }
// }

// // Тест для функції countAndSumElements
// TEST(ArrayTest, CountAndSumElements)
// {
//     int arr[TEST_SIZE] = {-5, 2, 0, -3, 4, 6, 7, -2, 1, 10};
//     int count, sum;

//     int expectedCount = 5;                      // Кількість елементів, що < 0 або непарні
//     int expectedSum = -5 + (-3) + 7 + 1 + (-2); // Сума таких елементів

//     countAndSumElements(arr, TEST_SIZE, count, sum);//

//     EXPECT_EQ(count, expectedCount);
//     EXPECT_EQ(sum, expectedSum);
// }

// // Тест для функції replaceSpecificElements
// TEST(ArrayTest, ReplaceSpecificElements)
// {
//     int arr[TEST_SIZE] = {-5, 2, 0, -3, 4, 6, 7, -2, 1, 10};
//     int expectedArr[TEST_SIZE] = {0, 2, 0, 0, 4, 6, 0, 0, 0, 10};

//     replaceSpecificElements(arr, TEST_SIZE);

//     for (int i = 0; i < TEST_SIZE; ++i)
//     {
//         EXPECT_EQ(arr[i], expectedArr[i]);
//     }
// }

// // Основна функція для запуску тестів
// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

#include <gtest/gtest.h>
#include "./lab6_1_rec.h"

const int TEST_SIZE = 10;
const int TEST_MIN_VALUE = -50;
const int TEST_MAX_VALUE = 15;

// Тест для функції generateArray (рекурсивна версія)
TEST(ArrayTest, GenerateArray)
{
    int arr[TEST_SIZE];
    generateArray(arr, TEST_SIZE, TEST_MIN_VALUE, TEST_MAX_VALUE, 0); // Додаємо рекурсивний індекс

    for (int i = 0; i < TEST_SIZE; ++i)
    {
        EXPECT_GE(arr[i], TEST_MIN_VALUE); // Перевіряємо, чи елементи масиву не менші за мінімум
        EXPECT_LE(arr[i], TEST_MAX_VALUE); // Перевіряємо, чи елементи масиву не більші за максимум
    }
}

// Тест для функції countAndSumElements (рекурсивна версія)
TEST(ArrayTest, CountAndSumElements)
{
    int arr[TEST_SIZE] = {-5, 2, 0, -3, 4, 6, 7, -2, 1, 10};
    int count = 0;
    int sum = 0;

    int expectedCount = 5;                      // Кількість елементів, що < 0 або непарні
    int expectedSum = -5 + (-3) + 7 + 1 + (-2); // Сума таких елементів

    countAndSumElements(arr, TEST_SIZE, count, sum, 0); // Додаємо рекурсивний індекс для початку

    EXPECT_EQ(count, expectedCount);
    EXPECT_EQ(sum, expectedSum);
}

TEST(ArrayTest, ReplaceSpecificElements)
{
    int arr[TEST_SIZE] = {-5, 2, 0, -3, 4, 6, 7, -2, 1, 10};
    int expectedArr[TEST_SIZE] = {0, 2, 0, 0, 4, 6, 0, 0, 0, 10};

    replaceSpecificElements(arr, TEST_SIZE, 0); // Додаємо рекурсивний індекс

    for (int i = 0; i < TEST_SIZE; ++i)
    {
        EXPECT_EQ(arr[i], expectedArr[i]); // Перевірка відповідності елементів після заміни
    }
}

// Основна функція для запуску тестів
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
