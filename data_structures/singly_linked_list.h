#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_

template <class T>
class LinkedList {
public:
    class Node; // Forward declaration

public:
    Node * head;
    Node * tail;
    int count;

private:
    void checkIndex(int index);

public:
    LinkedList();
    ~LinkedList();

    class Node {
    public:
        T data;
        Node * next;

        Node() {
            this->data = 0;
            this->next = nullptr;
        }

        Node(T data, Node * next) : data(data), next(next) {}
    };

    void add(T element);
    void add(int index, T element);
    int removeAt(int index);
    bool removeItem(T item);
    int get(int index);
    void set(int index, T element);
    bool contains(T item);
    string toString();
    int size();
    bool empty();
    void clear();
    int indexOf(T item);
    void replace(LinkedList * linked_list, int low, int high);
};

#endif