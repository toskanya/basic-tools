#include "sorting.h"
#include "main.h"

Array::Array() : arr(nullptr), size(0) {}

Array::Array(int n) : size(n) {
    arr = new int[n];
}

Array::Array(int a[], int n) : arr(a), size(n) {}

int Array::operator[] (int index) {
    return arr[index];
}

void Array::print() {
    for (size_t i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int Array::getSize() {
    return size;
}

//-----------------------Permutation Sort------------------------//

void Array::permutationSort() {
    bool isSorted = false;

    while (!isSorted) {
        for (size_t i = 0; i < size; i++) {
            swap(arr[i], arr[rand() % size]);
        }

        for (size_t i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                isSorted = false;
                break;
            }

            isSorted = true;
        }
    }
}

//-----------------------Selection Sort------------------------//

void Array::selectionSort() {
    for (size_t i = 0; i < size - 1; i++) {
        int min_index = i;

        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        if (min_index != i)
            swap(arr[i], arr[min_index]);
    }
}

//-----------------------Merge Sort------------------------//

void Array::merge(Array left, Array right) {
    int l = 0,
        r = 0,
        i = 0;

    int left_size = size / 2,
        right_size = size - left_size;

    while (l < left_size && r < right_size) {
        if (left[l] < right[r]) {
            arr[i++] = left[l++];
        }
        else {
            arr[i++] = right[r++];
        }
    }

    while (l < left_size) {
        arr[i++] = left[l++];
    }

    while (r < right_size) {
        arr[i++] = right[r++];
    }
}   

void Array::mergeSort() {
    int mid_size = size / 2;
    int left_array[mid_size];
    int right_array[size - mid_size];

    if (size <= 1) return;

    for (size_t i = 0; i < mid_size; i++) {
        left_array[i] = arr[i];
    }

    for (size_t i = mid_size; i < size; i++) {
        right_array[i - mid_size] = arr[i];
    }

    Array left(left_array, mid_size);
    Array right(right_array, size - mid_size);

    left.mergeSort();
    right.mergeSort();
    merge(left, right);
}

//-----------------------Bubble Sort------------------------//

void Array::bubbleSort() {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

//-----------------------Insertion Sort------------------------//

void Array::insertionSort() {
    for (size_t i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key <= arr[j]) {    
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}