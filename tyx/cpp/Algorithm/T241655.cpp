#include <bits/stdc++.h>

using namespace std;

int t, n;

const int maxn = 1e6+5;
int sf[maxn];

int main() {
    int f1 = 1, f2 = 1;
    sf[1] = 1;
    sf[2] = 2;
    for (int i = 3; i < (int)1e6 + 5; i++) {
        // sf[i] = (f1 + f2) % 9;
        int tmp = (f1 + f2) % 9;
        f1 = f2;
        f2 = tmp;
        sf[i] = (sf[i - 1] + tmp) % 9;
    }
    // cout << sf[3] << endl << sf[4] << endl << sf[5] << endl;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << sf[n] << endl;
    }
    return 0;
}