#include "sorting.cpp"

int main()
{
    int size = 5;
    int num_array[size] = {5, 4, 3, 2, 1};
    Array *new_arr = new Array(num_array, size);

    new_arr->insertionSort();
    new_arr->print();

    return 0;
}