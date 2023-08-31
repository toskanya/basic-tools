#include "sorting.cpp"

int main() {
    int size = 10;
    int num_array[size] = {5, 2, 1, 3, 23, 123, 123, 52133, 23, 1};
    Array * new_arr = new Array(num_array, size);

    new_arr->insertionSort();
    new_arr->print();

    return 0;
}