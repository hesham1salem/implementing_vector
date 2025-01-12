#include "../include/myvector.hpp"

int main()
{  
  Vector v={1,2,3,4,5};
  std::cout<<v.size()<<std::endl;
  v.print();
  v.push_back(10);
   v.print();
  v.left_rotate();
  v.print();
  std::cout<<v.size()<<std::endl;

  return 0;
}
