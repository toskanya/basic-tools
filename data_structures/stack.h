#ifndef __STACK_H__
#define __STACK_H__

#include "doubly_linked_list.h"

template <class T>
class Stack 
{
protected:
    DLinkedList<T> list;

public:
    Stack() {}
    void push(T item);
    T top();
    T pop();
    bool empty();
    int size();
    void clear();
};

#endif