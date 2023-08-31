#include "bits/stdc++.h"

using namespace std;

int main() {
    int a1, b1, c1, a2, b2, c2;
 
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    float D = a1 * b2 - a2 * b1;
    float Dx = c1 * b2 - c2 * b1;
    float Dy = a1 * c2 - a2 * c1;

    if (D == 0) {
        if (Dx == 0 && Dy == 0)
            cout << "infinite solution";
        else
            cout << "no solution";
    }
    else {
        float x = Dx / D;
        float y = Dy / D;

        cout << x << " " << y;
    }
    
    return 0;
}