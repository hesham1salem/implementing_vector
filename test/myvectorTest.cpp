#include "myvector.hpp"
#include <gtest/gtest.h>

Vector v={1,2,3,4,5};
TEST(getingValue,size)
{   

    EXPECT_EQ(5,v.size());
}
TEST(pushingbackValue, push_back)
{   v.push_back(10);
    EXPECT_EQ(10, v.get_back());
}

TEST(pushingfrontValue,push_front)
{
    v.push_front(0);
    EXPECT_EQ(0,v.get(0));
}

TEST(insertingValue, insert)
{
    v.insert(3,20);
    EXPECT_EQ(20, v.get(3));
  
}
TEST(setingValue,set)
{ 
    v.set(0,40);
    EXPECT_EQ(40,v.get_front());

}
TEST(popingValue,pop)
{
    EXPECT_EQ(10,v.pop(v.size()-1));
}
TEST(expandingcapacity,expandcapacity)
{  
    size_t size_prev=v.size();
    v.expand_capacity();
    EXPECT_EQ(size_prev*2,v.get_capacity());
   
}
TEST(findingValue,find_index)
{
    EXPECT_EQ(40,v.find_index(0));
}
TEST(rotating,right_rotate)
{
    v.right_rotate();
    EXPECT_EQ(40,v.get_back());
    EXPECT_EQ(5,v.get_front());

}
int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}