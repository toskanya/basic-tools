#ifndef __HEAP__
#define __HEAP__
#include "main.h"

class Heap {
private:
    int * data;
    int capacity;
    int count;

    void ensureCapacity(int capcity);
    void checkIndex(int index);

    int leftChildIndex(int index);
    int rightChildIndex(int index);
    int parentIndex(int index);

    int leftChild(int index);
    int rightChild(int index);
    int parent(int index);

    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    bool hasParent(int index);

    void heapifyDown();
    void heapifyUp();

public:
    Heap();
    ~Heap();

    void swap(int indexOne, int indexTwo);
    int peak();
    int poll();
    void add(int item);
    void dump();
};

#endif