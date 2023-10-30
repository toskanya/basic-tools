#include "sorting.cpp"

int main()
{
    int size = 10;
    int num_array[size] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 0};
    Array *new_arr = new Array(num_array, size);

    new_arr->quickSort(0, size - 1);
    new_arr->print();

    return 0;
}