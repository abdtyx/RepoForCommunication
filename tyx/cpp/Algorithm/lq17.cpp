#include <bits/stdc++.h>

using namespace std;

int main() {
    int f1 = 1, f2 = 1;
    int mod = 10007;
    int n;
    cin >> n;
    for (int i = 1; i < (n + (n & 1)) / 2; i++) {
        f1 = (f1 + f2) % mod;
        f2 = (f2 + f1) % mod;
    }
    if (n & 1)
        cout << f1;
    else
        cout << f2;
    return 0;
}