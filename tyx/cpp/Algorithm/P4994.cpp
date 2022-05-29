#include <bits/stdc++.h>

using namespace std;
// int a[1000000] = {0, 1};

int main() {
    long long int n;
    cin >> n;
    long long int f0 = 0, f1 = 1;
    for (long long int i = 2; i <= n * n; i++) {
        // a[i] = (a[i - 1] + a[i - 2]) % n;
        // cout << a[i] << ' ';
        // if (i == 24) cout << a[i];
        // cout << a[i] % 6 << ' ';
        long long int tmp = f1;
        f1 = (f0 + f1) % n;
        f0 = tmp;
        if (f1 == 1 && f0 == 0) {cout << i - 1;break;}
    }
    return 0;
}