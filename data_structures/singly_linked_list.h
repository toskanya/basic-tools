#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_

#include "array.h"

class IntSLinkedList : public Ilist<int> {
public:
    class Node; // Forward declaration

protected:
    Node * head;
    Node * tail;
    int count;

private:
    void checkIndex(int index);

public:
    IntSLinkedList();
    ~IntSLinkedList();

    class Node {
    public:
        int data;
        Node * next;

        Node() {
            this->data = 0;
            this->next = nullptr;
        }
    };

    void add(int element);
    void add(int index, int element);
    int removeAt(int index);
    bool removeItem(int item);
    int get(int index);
    void set(int index, int element);
    bool contains(int item);
    string toString();
    int size();
    bool empty();
    void clear();
    int indexOf(int item);      
};

#endif