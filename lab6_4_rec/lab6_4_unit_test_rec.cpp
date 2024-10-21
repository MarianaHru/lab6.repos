#include <gtest/gtest.h>
#include "lab6_4_rec.h"

TEST(ProductOfEvenIndicesTests, BasicTests)
{
    EXPECT_EQ(productOfEvenIndices({0, 2, 0, 4, 5}), 0);
    EXPECT_EQ(productOfEvenIndices({1, 2, 3, 4}), 3);
    EXPECT_EQ(productOfEvenIndices({1, 2, 3, 4, 5}), 15);
    EXPECT_EQ(productOfEvenIndices({2, 2, 2, 2, 2}), 8);
}

TEST(SumBetweenZeroesTests, BasicTests)
{
    EXPECT_EQ(sumBetweenZeroes({1, 0, 2, 3, 0, 4}, 1, 4), 5);
    EXPECT_EQ(sumBetweenZeroes({0, 1, 2, 0, 3, 4}, 0, 3), 3);
    EXPECT_EQ(sumBetweenZeroes({1, 2, 3}, -1, -1), 0);
}

TEST(RearrangeArrayTests, BasicTests)
{
    std::vector<int> arr = {1, -1, 2, -2, 3, -3};
    std::vector<int> positive;
    std::vector<int> nonPositive;
    rearrangeArray(arr, positive, nonPositive);
    EXPECT_EQ(positive, (std::vector<int>{1, 2, 3}));
    EXPECT_EQ(nonPositive, (std::vector<int>{-1, -2, -3}));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
