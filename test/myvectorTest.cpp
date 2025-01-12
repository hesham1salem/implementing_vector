#include "myvector.hpp"
#include <gtest/gtest.h>

class myvector_test :public testing::Test{
protected:
void SetUp() override {
    for(int i=1;i<=5;i++)
    {
v.push_back(i);
    }
}
void TearDown() override{
std::cout<< "hello from TearDown()"<<std::endl;

}

Vector v{};

};

TEST_F(myvector_test,size)
{   

    EXPECT_EQ(5,v.size());
}

TEST_F(myvector_test,expandcapacity)
{  
    v.expand_capacity();
    EXPECT_EQ(5*2,v.get_capacity());
}
TEST_F(myvector_test, push_back)
{
    v.push_back(10);
    EXPECT_EQ(10, v.get_back());
    EXPECT_EQ(6,v.size());
}

TEST_F(myvector_test,push_front)
{
    v.push_front(10);
    EXPECT_EQ(6,v.size());
    EXPECT_EQ(10,v.get_front());
}

TEST_F(myvector_test, insert)
{
    v.insert(3,20);
    EXPECT_EQ(20, v.get(3));
    EXPECT_EQ(6,v.size());
  
}
TEST_F(myvector_test,set)
{ 
    v.set(2,100);
    EXPECT_EQ(100, v.get(2));
}
TEST_F(myvector_test,pop)
{
    v.pop(v.size()-1);
    EXPECT_EQ(4,v.size());

}

TEST_F(myvector_test,find_index)
{
    EXPECT_EQ(3,v.find_index(4));
  
}
TEST_F(myvector_test,right_rotate)
{       
    v.right_rotate();
    EXPECT_EQ(5,v.get_front());
    

} 
TEST_F(myvector_test,left_rotate)
{
    v.left_rotate();
  
    EXPECT_EQ(2,v.get_front());
   
}
