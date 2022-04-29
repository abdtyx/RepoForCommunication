#include <bits/stdc++.h>

using namespace std;

#define p 998244353

typedef long long int ll;

ll pow_mod(ll a, ll n) {
    if (n == 0) return 1;
    ll resby = pow_mod(a, n / 2);
    return resby * resby % p * ((n & 1) ? a : 1) % p;
}

int main() {
    // cout << INFINITY;
    cout << pow_mod(2, 29);
}