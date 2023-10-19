#ifndef __DOUBLY_LINKED_LIST
#define __DOUBLY_LINKED_LIST

#include "array.h"

template <class T>
class DLinkedList
{
public:
    class Node;

    class Iterator;

protected:
    Node * head;
    Node * tail;
    int count;

    void checkIndex(int index);

public:
    DLinkedList();
    ~DLinkedList();

    void add(T element);
    void add(int index, T element);
    T removeAt(int index);
    bool removeItem(T item);
    T get(int index);
    void set(int index, T element);
    bool contains(T item);
    string toString();
    int size();
    bool empty();
    void clear();
    int indexOf(T item);
    void reverse();

    Iterator begin()
    {
        return Iterator(this, true);
    }

    Iterator end()
    {
        return Iterator(this, false);
    }

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *pre;
        friend class DLinkedList<T>;
    public:
        Node()
        {
            this->data = 0;
            this->next = nullptr;
            this->pre = nullptr;
        }

        Node(T data, Node *next=nullptr, Node *pre=nullptr) : data(data), next(next), pre(pre) {};
    };

    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index;
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();

        // Prefix ++ overload
        Iterator &operator++();
        // Postfix ++ overload
        Iterator operator++(int);
    };
};

#endif
