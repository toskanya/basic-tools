#ifndef __SORTING__
#define __SORTING__



class Array {
private:
    int * arr;
    int size;

    void merge(Array left, Array right);

public:
    Array();

    Array(int n);

    Array(int a[], int n);

    int operator[] (int index);
    int getSize();

    void permutationSort();
    void selectionSort();
    void mergeSort();
    void bubbleSort();
    void insertionSort();

    void print();

};

#endif