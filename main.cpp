#include "myvector.hpp"

int main()
{
    expend_capacity();
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
