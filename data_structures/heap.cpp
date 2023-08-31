#include "main.h"
#include "heap.h"

Heap::Heap() {
    this->capacity = 10;
    this->data = new int[capacity];
    this->count = 0;
}

Heap::~Heap() {
    delete[] this->data;
}

void Heap::ensureCapacity(int capacity) {
    if (capacity > this->capacity) {
        int new_capacity = this->capacity * 2;
        int * new_data = new int[new_capacity];

        memmove(new_data, this->data, this->count * sizeof(int));

        delete[] this->data;
        this->data = new_data;
    }
}

void Heap::checkIndex(int index) {
    if (index < 0 || index >= this->count) 
        throw out_of_range("Index is out of range");
}

int Heap::leftChildIndex(int index) {
    this->checkIndex(index);

    return index * 2 + 1;
}

int Heap::rightChildIndex(int index) {
    this->checkIndex(index);

    return index * 2 + 2;
}

int Heap::parentIndex(int index) {
    this->checkIndex(index);

    return (index - 1) / 2;
}

int Heap::leftChild(int index) {
    return this->data[leftChildIndex(index)];
}

int Heap::rightChild(int index) {
    return this->data[rightChildIndex(index)];
}

int Heap::parent(int index) {
    return this->data[parentIndex(index)];
}

bool Heap::hasLeftChild(int index) {
    return this->leftChildIndex(index) < this->count;
}

bool Heap::hasRightChild(int index) {
    return this->rightChildIndex(index) < this->count;
}

bool Heap::hasParent(int index) {
    return this->parentIndex(index) < this->count;
}

void Heap::swap(int indexOne, int indexTwo) {
    this->checkIndex(indexOne);
    this->checkIndex(indexTwo);

    int temp = this->data[indexOne];
    this->data[indexOne] = this->data[indexTwo];
    this->data[indexTwo] = temp;
}

int Heap::peak() {
    if (this->count == 0)
        throw out_of_range("Index is out of range");

    return this->data[0];
}

int Heap::poll() {
    if (this->count == 0)
        throw out_of_range("Index is out of range");

    int item = this->data[0];
    this->data[0] = this->data[this->count - 1];
    this->count--;
    this->heapifyDown();
    return item;
}

void Heap::add(int item) {
    this->ensureCapacity(count + 1);

    this->data[this->count] = item;
    this->count++;
    this->heapifyUp();
}

void Heap::heapifyUp() {
    int index = this->count - 1;
    while (this->hasParent(index) && this->parent(index) > this->data[index]) {
        this->swap(this->parentIndex(index), index);
        index = this->parentIndex(index);
    }
}

void Heap::heapifyDown() {
    int index = 0;
    while (this->hasLeftChild(index)) {
        int smallerIndex = this->leftChildIndex(index);
        if (this->hasRightChild(index) && this->rightChild(index) < this->leftChild(index))
            smallerIndex = this->rightChildIndex(index);

        if (this->data[smallerIndex] > this->data[index])
            break;
        else {
            this->swap(smallerIndex, index);
            index = smallerIndex;
        } 
    }
}

void Heap::dump() {
    int levels = 1 + floor(log(this->count) / log(2));
    int index = 0;
    for (int i = 0; i < levels; i++) {
        cout << setw(pow(2, levels - i - 1)) << right;
        for (int j = 0; j < pow(2, i); j++) {
            if (index < count)
                cout << this->data[index++] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "[";

    for (int i = 0; i < this->count - 1; i++)
        cout << this->data[i] << ", ";

    if (this->count < 1)
        cout << "]";
    else
        cout << this->data[this->count - 1] << "]";
}