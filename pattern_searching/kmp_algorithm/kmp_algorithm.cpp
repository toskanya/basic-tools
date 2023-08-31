#include "bits/stdc++.h"

using namespace std;

void setupLPS(string pat, int p, int * lps) {
    int i = 1, len = 0;

    lps[0] = 0;

    while (i < p) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else if (len == 0) {
            lps[i] = 0;
            i++;
        }
        else {
            len = lps[len - 1];
        }
    }
}
  

void checkKMP(char * pat, char * txt) {
    int p = strlen(pat),
        t = strlen(txt);
    
    int * lps = new int[p];

    setupLPS(pat, p, lps);

    int i = 0, j = 0;
    
    while (i < t) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        else if (j > 0) {
            j = lps[j - 1];
        }
        else {
            i++;
        }

        if (j == p) {
            return i - j;
        }
    }

    return -1;
}
