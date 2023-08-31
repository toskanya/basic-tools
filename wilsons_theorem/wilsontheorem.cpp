#include "bits/stdc++.h"

using namespace std;


int main() {
    int n;
    long long fact = 1;
    
    cin >> n;

    for (int i = 2; i < n; i++) {

        if ((fact + 1) % i == 0)
            cout << i << " ";

        fact *= i;
    }
    
    return 0;
}