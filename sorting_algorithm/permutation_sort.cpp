#include <iostream>
#include <algorithm>

using namespace std;

bool isSorted(int a[], int n) {
    for (size_t i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }

    return true;
}

void shuffle(int a[], int n) {
    for (size_t i = 0; i < n; i++) {
        swap(a[i], a[rand() % n]);
    }
}

void sort(int a[], int n) {
    while (!isSorted(a, n)) {
        shuffle(a, n);
    }
}


int main() {
    int a[5] = {1, 3, 7, 2, 0};

    sort(a, 5);

    for (size_t i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}