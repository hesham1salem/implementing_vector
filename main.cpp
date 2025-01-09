
#include <iostream>
int *arr{};
void expend_capacity() {}

void set(int index, int value) {}
int get(int index)
{
    return 55;
}
int size()
{
    return 5;
}
int get_front()
{
    return 5;
}
int get_back()
{
    return 5;
}
int find_index(int value)
{
    return 5;
}
void print()
{
    std::cout << 1 << 2 << 33 << 55 << 88 << std::endl;
}
void right_rotate() {}
void left_rotate() {}
void right_rotate(int times) {}
void push_back(int value) {}
void push_front(int value) {}
void insert(int index, int value) {}
int pop(int index)
{
    return 5;
}

int main()
{
    void expend_capacity();

    set(1, 5);
    get(1);
    size();
    get_front();
    get_back();
    find_index(25);
    print();
    right_rotate();
    left_rotate();
    right_rotate(6);
    push_back(2);
    push_front(9);
    insert(3, 8);
    pop(1);
}
