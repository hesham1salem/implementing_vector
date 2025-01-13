#include "myvector.hpp"

int main()
{  
  
  Vector v1{1,2,3,4};
  Vector v2(std::move(v1));
  v1.push_back(4);
  v1.print();
  v2.print();
  return 0;
}
