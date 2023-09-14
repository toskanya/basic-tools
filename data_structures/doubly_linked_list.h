#ifndef __DOUBLY_LINKED_LIST
#define __DOUBLY_LINKED_LIST

#include "array.h"

class IntSDoubleLinkedList : public Ilist<int> {
public:
    class Node;

private:
    Node * head;
    int count;

    void checkIndex(int index);

public:
    IntSDoubleLinkedList();
    ~IntSDoubleLinkedList();

    class Node {
    public:
        int data;
        Node * next;
        Node * pre;

        Node() {
            this->data = 0;
            this->next = nullptr;
            this->pre = nullptr;
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
    void reverse();
};

#endif
