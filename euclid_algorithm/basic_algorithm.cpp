#include "bits/stdc++.h"

using namespace std;

int GCD_divide(int a, int b) {
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (b == 0)
        return a;
    else 
        return GCD_divide(b, a % b);
}

int GCD_substract(int a, int b) {
    if (a == 0) 
        return b;
    else if (b == 0)
        return a;
    
    if (a == b) {
        return a;
    }
    if (a > b) {
        return GCD_substract(a - b, b);
    }
    else return GCD_substract(a, b - a);

}

int main() {
    int a = 1785, b = 546;

    cout << GCD_substract(a, b);
    cout << GCD_divide(a, b);
    
    return 0;
}
