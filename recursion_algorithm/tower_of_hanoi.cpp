#include "bits/stdc++.h"

using namespace std;



int towerOfHanoi(int total_disks, string from, string to, string aux) {

    if (total_disks == 1) {
        cout << "move " << from << " to " << to << endl;;
        return 1;
    }
    else {
        return towerOfHanoi(total_disks - 1, from, aux, to) + towerOfHanoi(1, from, to, aux) + towerOfHanoi(total_disks - 1, aux, to, from);
    }
}

int main() {
    int steps = towerOfHanoi(3, "A", "C", "B");

    cout << endl << steps;

    return 0;
}
A C B
A B C
A C B