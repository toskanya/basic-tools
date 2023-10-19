#include "main.h"

#ifndef __SORTING__
#define __SORTING__

class Array
{
private:
    int *arr;
    int size;

    int moves;
    int comparisions;

    void merge(Array left, Array right);
    stack<int> incrementalValue();
    void sortSegment(int segment, int k);
    int partition(int low, int high);

public:
    Array();

    Array(int n);

    Array(int a[], int n);

    int operator[](int index);
    int getSize();

    void permutationSort();
    void selectionSort();
    void mergeSort();
    void bubbleSort();
    void insertionSort();
    void shellSort();
    void quickSort(int low, int high);

    void print();
};

#endif