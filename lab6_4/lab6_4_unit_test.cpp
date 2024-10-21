#include <gtest/gtest.h>
#include "lab6_4.h"

// Тести для добутку елементів з парними номерами
TEST(ProductOfEvenIndicesTests, BasicTests)
{
    EXPECT_EQ(productOfEvenIndices({1, 2, 3, 4, 5}), 15); // 1 * 3 * 5 = 15
    EXPECT_EQ(productOfEvenIndices({0, 2, 0, 4, 5}), 0);  // 0 * 0 * 5 = 0
    EXPECT_EQ(productOfEvenIndices({2, 2, 2, 2}), 4);     // 2 * 2 = 4 (правильне значення)
    EXPECT_EQ(productOfEvenIndices({}), 1);               // Порожній масив
}

// Тести для суми елементів між першим і останнім нульовими елементами
TEST(SumBetweenZeroesTests, BasicTests)
{
    EXPECT_EQ(sumBetweenZeroes({1, 0, 2, 3, 0, 4}), 5); // 2 + 3 = 5
    EXPECT_EQ(sumBetweenZeroes({0, 1, 2, 3, 0}), 6);    // 1 + 2 + 3 = 6
    EXPECT_EQ(sumBetweenZeroes({1, 2, 3}), 0);          // Немає нулів
    EXPECT_EQ(sumBetweenZeroes({0, 0}), 0);             // 0 між 0 і 0
}

// Тести для перестановки додатних елементів на початок масиву
TEST(RearrangeArrayTests, BasicTests)
{
    vector<int> arr1 = {1, -1, 2, -2, 3, -3};
    rearrangeArray(arr1);
    EXPECT_EQ(arr1, vector<int>({1, 2, 3, -1, -2, -3}));

    vector<int> arr2 = {-1, -2, -3};
    rearrangeArray(arr2);
    EXPECT_EQ(arr2, vector<int>({-1, -2, -3})); // Нічого не змінюється

    vector<int> arr3 = {1, 2, 3};
    rearrangeArray(arr3);
    EXPECT_EQ(arr3, vector<int>({1, 2, 3})); // Нічого не змінюється

    vector<int> arr4 = {0, -1, 2, -3, 4};
    rearrangeArray(arr4);
    EXPECT_EQ(arr4, vector<int>({0, 2, 4, -1, -3})); // 0 включається
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
