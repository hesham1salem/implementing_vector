#include "../include/myvector.hpp"
#include<cstring>
Vector::Vector():current_size{0},capacity(5){
    arr= new int[capacity];
}
Vector::Vector(int n , int value):current_size(n),capacity(5){
    arr =new int[capacity];
    for(int i=0; i<n;i++){
        arr[i]=value;
    }
}
Vector::Vector(std::initializer_list<int> init_list)
        : current_size(init_list.size()), capacity(5) {
        arr = new int[capacity];
        int index = 0;
        for (int value : init_list) {
            arr[index++] = value; 
        }
    }

Vector::~Vector(){
    if(arr){
        delete[] arr;
    }
}
void Vector::expand_capacity(){
   int new_cap=capacity*2;
   int* new_arr= new int[new_cap];
   for(int i =0 ; i<current_size;i++){
     new_arr[i]=arr[i];
   }
   delete[] arr;
   arr=new_arr;
   capacity=new_cap;
}
void Vector::set(int index, int value){
      if(index <current_size && index >= 0){
        arr[index]=value;  
     }
     else{
      throw std::out_of_range("index is out of range");
        }

}
int Vector::get(int index){
    if(index <current_size && index >= 0){
            return arr[index];
     }

    else throw std::out_of_range("index is out of range");
    
}

int Vector::size(){
    return current_size;
}
int Vector::get_capacity(){
    return capacity;
}

int Vector::get_front()
{
    if(current_size>0){
        return arr[0];
    }
    else{
        throw std::out_of_range("vector is empty");
    }
}

int Vector::get_back()
{   
     if(current_size>0){
        return arr[current_size -1];
    }
    else{
        throw std::out_of_range("vector is empty");
    }
}

int Vector::find_index(int value){
            for (int i = 0; i < current_size; ++i) {
            if (arr[i] == value) {
                return i;
            }
        }
        return NOT_EXIST;
    }


void Vector::print()
{
    for(int i =0 ; i<current_size;i++){
        std::cout<<arr[i]<<"  ";
    }
    std::cout<<std::endl;
}


void Vector::push_back(int value) {
    if(current_size==capacity){
      expand_capacity();

    }
    arr[current_size++]=value;

}
void Vector::push_front(int value) {
  if(current_size==capacity){
    expand_capacity();
  }
  for(int i=current_size; i>0;i--){
    arr[i]=arr[i-1];
  }
  arr[0]=value;
  ++current_size;
}

int Vector::pop(int index)
   {
        if (index < 0 || index >= current_size) {
            throw std::out_of_range("Index out of range");
        }
        int value = arr[index];
        for (int i = index; i < current_size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --current_size;
        return value;
    }


void Vector::insert(int index, int value) {
    
    if (index < 0 || index > current_size) {
        throw std::out_of_range("Index out of range");
    }
    if (current_size == capacity) {
        expand_capacity();
    }
    for (int i = current_size; i > index; --i) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    ++current_size;
    
}

void Vector::right_rotate() {
    if (current_size > 1) {
        int last = arr[current_size - 1];
        for (int i = current_size - 1; i > 0; --i) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }
}

void Vector::left_rotate() {
    if (current_size > 1) {
        int first = arr[0];
        for (int i = 0; i < current_size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        arr[current_size - 1] = first;
    }
}