#include "myvector.hpp"
#include <gtest/gtest.h>

TEST(getingValue,size)
{   
Vector v={1,2,3,4,5};

    EXPECT_EQ(5,v.size());
}

TEST(expandingcapacity,expandcapacity)
{  
    Vector v={1,2,3,4,5};

    v.expand_capacity();
    EXPECT_EQ(5*2,v.get_capacity());
   
}
TEST(pushingbackValue, push_back)
{
    Vector v{};

       v.push_back(10);
    EXPECT_EQ(10, v.get_back());
    EXPECT_EQ(1,v.size());
}

TEST(pushingfrontValue,push_front)
{
    Vector v={1,2};

    v.push_front(10);
    EXPECT_EQ(3,v.size());
    EXPECT_EQ(10,v.get_front());
}

TEST(insertingValue, insert)
{
    Vector v{1,2,3,4};
    v.insert(3,20);
    EXPECT_EQ(20, v.get(3));
    EXPECT_EQ(5,v.size());
  
}
TEST(setingValue,set)
{ 
    Vector v{1,2,3,4};
    v.set(2,100);
    EXPECT_EQ(100, v.get(2));
}
TEST(popingValue,pop)
{
    Vector v{1,2,3,4};
    EXPECT_EQ(4,v.pop(v.size()-1));
    v.print();
}

TEST(findingValue,find_index)
{
    Vector v{1,2,3,4};
    EXPECT_EQ(3,v.find_index(4));
    v.print();
}
TEST(rotating,right_rotate)
{       
    Vector v{1,2,3,4};
    v.right_rotate();
    EXPECT_EQ(4,v.get_front());
    v.print();

} 
TEST(rotating,left_rotate)
{
    Vector v{1,2,3,4};
    v.left_rotate();
  
    EXPECT_EQ(2,v.get_front());
    v.print();
}
int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}