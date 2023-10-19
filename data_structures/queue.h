#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "doubly_linked_list.h"

template <class T>
class Queue
{
protected:
    DLinkedList<T> list;
public:
    Queue() {}
    void push(T item);
    T pop();
    T top();
    bool empty();
    int size();
    void clear();
};

#endif