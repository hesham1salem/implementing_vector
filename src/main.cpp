#include "myvector.hpp"
#include <vector>
#include <memory>
int main()
{  
  Vector v1{1,2,3,4};
  Vector v2(std::move(v1));
  try{
  v1.push_back(10);

  }catch(std::runtime_error & e){
    std::cout<<"please take care not use object after moving because it in not defined state"<<std::endl;
    std::cout<<"لكن هعدهالك"<<std::endl;
  }
  
  v2.print();

  return 0;
}
