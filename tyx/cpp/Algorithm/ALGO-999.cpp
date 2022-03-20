#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
LL pow_mod(LL a, LL e, LL p);

int main() {
    LL n;
    cin >> n;
    LL m3 = n / 3;
    LL l = n - 3 * m3;
    if (n <= 2) {
        cout << n;
        return 0;
    }
    LL ans = pow_mod(3, m3 - 1, 5218);
    switch (l) {
        case 0:
            ans = ans * 3 % 5218;
            break;
        case 1:
            ans = ans * 4 % 5218;
            break;
        case 2:
            ans = ans * 6 % 5218;
            break;
    }
    cout << ans;
    return 0;
}

LL pow_mod(LL a, LL e, LL p) {
    if (e <= 0) return 1;
    LL resby = pow_mod(a, e / 2, p);
    return resby * resby % p * ((e & 1) ? a : 1) % p;
}