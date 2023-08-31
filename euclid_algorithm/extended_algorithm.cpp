#include "bits/stdc++.h"

using namespace std;

int gcd(int a, int b, int * x, int * y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1,
        y1;

    int res = gcd(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return res;
}

int main() {
    int x, y, a = 35, b = 15;
    int g = gcd(a, b, &x, &y);

    cout << x << " " << y << " " << g;

    return 0;
}
