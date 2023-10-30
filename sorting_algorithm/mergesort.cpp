#include "bits/stdc++.h"

using namespace std;

void print(vector<int> arr)
{
    for (int e : arr)
        cout << e << " ";
    cout << endl;
}

vector<int> merge(vector<int> &arr, vector<int> left, vector<int> right)
{
    int left_size = left.size();
    int right_size = right.size();
    vector<int> result(left_size + right_size);
    int l = 0;
    int r = 0;
    int i = 0;

    while (l < left_size && r < right_size)
    {
        if (left[l] < right[r])
        {
            result[i] = left[l];
            l++;
        }
        else
        {
            result[i] = right[r];
            r++;
        }
        i++;
    }

    while (l < left_size)
    {
        result[i++] = left[l++];
    }
    while (r < right_size)
    {
        result[i++] = left[r++];
    }

    return result;
}

vector<int> mergeSort(vector<int> &arr, int l, int r)
{
    int size = arr.size();
    int mid = size / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + size - mid, arr.end());

    int left_size = left.size();
    int right_size = right.size();

    mergeSort(left, 0, left_size);
    mergeSort(right, 0, right_size);

    return merge(arr, left, right);
}

int main()
{
    vector<int> arr = {3, 2, 6, 9, 2, 1};
    vector<int> sorted = mergeSort(arr, 0, arr.size());
    print(sorted);
}