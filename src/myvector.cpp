#include "myvector.hpp"
#include<cstring>
#include<memory>
Vector::Vector(): current_size{std::make_shared<int>(0)},capacity{std::make_shared<int>(5)},arr(new int[*capacity]){}
Vector::Vector(int n , int value):current_size{std::make_shared<int>(n)},capacity{std::make_shared<int>(n)},arr(new int[*capacity]){
    for(int i=0; i<n;i++){
        arr[i]=value;
    }
}
Vector::Vector(std::initializer_list<int> init_list)
        :current_size{std::make_shared<int>(init_list.size())},capacity{std::make_shared<int>(init_list.size()*2)},arr(new int[*capacity]){
       
        int index = 0;
        for (auto it=init_list.begin();it!=init_list.end();it++) {
           
            arr[index] = *it;
            index++; 
        }
    }

// Vector::Vector(const Vector & other){
//     this->*current_size=other.*current_size;
//     this->**capacity=other.**capacity;
//     this->arr = new int[this->**capacity];
//     for(int i=0; i<other.*current_size;i++){
//         this->arr[i]=other.arr[i];
//     }
// }

// Vector::Vector(Vector &&other){
    
//     this->*current_size=other.*current_size;
//     this->*capacity=other.*capacity;
//     other.*current_size=0;
//     other.*capacity=0;
//     this->arr=other.arr;
//     other.arr=nullptr;

// }
// Vector& Vector::operator=(const Vector & other){
//     // if  other is not the same as this 
//     if(&other == this){
//         return *this;
//     }
//         this->*current_size=other.*current_size;
//         this->*capacity=other.*capacity;
//         // check if  arr is not nullptr
//         if(this->arr){
//             delete[] arr;
//         }
//         this->arr= new int[this->*capacity];
//         for(int i=0; i<other.*current_size;i++){
//             this->arr[i]=other.arr[i];
//         } 
//         return *this;
// }
// Vector & Vector::operator=(Vector && other){
//       if(this == &other){
//          return *this;
//       }
//       this->*capacity=other.*capacity;
//       this->*current_size=other.*current_size;
//       if(this->arr){
//         delete[] arr;
//       }
//       this->arr=other.arr;
//       other.*current_size=0;
//       other.*capacity=0;
//       other.arr=nullptr;  
//       return *this;

// }

// Vector::~Vector(){
//     if(arr){
//         delete[] arr;
//         arr=nullptr;
//     }
// }
void Vector::expand_capacity(){
   int new_cap=*capacity*2;
   std::shared_ptr<int[]> new_arr{new int[new_cap]};
   for(int i =0 ; i<*current_size;i++){
     new_arr[i]=arr[i];
   }
  
   arr=new_arr;
   *capacity=new_cap;
}
void Vector::set(int index, int value){
    
    if(index >= *current_size ||index < 0){
        throw std::out_of_range("index is out of range");
 
     }

      arr[index]=value;  

          

}
int Vector::get(int index){
    if(index >*current_size && index < 0){
        throw std::out_of_range(" index is out of range");
 
     }
     return arr[index];
    
}


int Vector::get_front()
{
    if(*current_size <=0){
        throw std::out_of_range("vector is empty");
    }
    return arr[0];
}

int Vector::get_back()
{   
    if(*current_size <= 0){
        throw std::out_of_range("vector is empty");
    }
    return arr[*current_size -1];
}

int Vector::find_index(int value){
            for (int i = 0; i < *current_size; ++i) {
            if (arr[i] == value) {
                return i;
            }
        }
        return NOT_EXIST;
    }


void Vector::print()
{
    for(int i =0 ; i<*current_size;i++){
        std::cout<<arr[i]<<"  ";
    }
    std::cout<<std::endl;
}


void Vector::push_back(int value) {
    if(current_size==nullptr && capacity ==nullptr){
        throw std::runtime_error("not allow to use after moving");
    }
    if((*current_size )== (*capacity)){
      expand_capacity();

    }
    arr[(*current_size)++]=value;

}
void Vector::push_front(int value) {
  if((*current_size) == (*capacity)){
    expand_capacity();
  }
  for(int i=*current_size; i>0;i--){
    arr[i]=arr[i-1];
  }
  arr[0]=value;
  ++*current_size;
}

int Vector::pop(int index)
   {
        if (index < 0 && index >= *current_size) {
            throw std::out_of_range("Index out of range");
        }
        int value = arr[index];
        for (int i = index; i < *current_size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --*current_size;
        return value;
    }


void Vector::insert(int index, int value) {
    
    if (index < 0 || index > *current_size) {
        throw std::out_of_range("Index out of range");
    }
    if ((*current_size) == (*capacity)) {
        expand_capacity();
    }
    for (int i = *current_size; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    ++*current_size;
    
}

void Vector::right_rotate() {
    
        int last = arr[*current_size - 1];
        for (int i = *current_size - 1; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    
}

void Vector::left_rotate() {
    
        int first = arr[0];
        for (int i = 0; i < *current_size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        arr[*current_size - 1] = first;
    
}