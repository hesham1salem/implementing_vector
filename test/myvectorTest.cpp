#include "myvector.hpp"
#include <gtest/gtest.h>

TEST(getingValue, get)
{
    EXPECT_EQ(55, get(1));
    EXPECT_EQ(0, 0);
    EXPECT_NE(58, get(1));
}

TEST(getingValue, pop)
{
    EXPECT_EQ(5, pop(1));
    EXPECT_EQ(0, 0);
    EXPECT_NE(58, pop(1));
}
TEST(insertingValue, push)
{
    push_back(2);
    EXPECT_EQ(5, get_back());
    // check this
    //  push_front()
    //  EXPECT_NE();
}
// TODO: complete the following
//  {
//      expend_capacity();
//      set(1, 5);
//      size();
//      get_front();
//      find_index(25);
//      print();
//      right_rotate();
//      left_rotate();
//      right_rotate(6);
//      push_front(9);
//      insert(3, 8);
//  }
int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}