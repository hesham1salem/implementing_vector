#include <iostream>
#include<stdexcept>
#ifndef VECTOR_H
#define VECCTOR_H

# define NOT_EXIST -1;
class Vector{
    public:
    Vector();
    Vector(int n ,int value);
    Vector(std::initializer_list<int> init_list);
    Vector(const Vector & other); 
    Vector(Vector &&other); 
    Vector& operator=(const Vector & other);
    Vector& operator=(Vector && other);
    void expand_capacity();
    void set(int index, int value);
    int get(int index);
    int get_front();
    int get_back();
    int find_index(int value);
    void print();
    void push_back(int value) ;
    void push_front(int value) ;
    void insert(int index, int value) ;
    int  pop(int index);
    void right_rotate();
    void left_rotate() ;

    inline int size(){
        return current_size;
    }
    inline int get_capacity(){
        return capacity;
    }

    ~Vector();
   private:
   int* arr;
   int capacity;
   int current_size;
};
#endif




