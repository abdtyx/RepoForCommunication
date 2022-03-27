#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define _MOD ((ll)1e9 + (ll)7)

ll pow_mod(ll a, ll e, ll p);

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    ll ans = (pow_mod(2, n, _MOD) + _MOD - (ll)1) % _MOD;
    // cout << ans << endl;
    ll cna = 1;
    if (a > n / 2) a = n - a;
    for (ll i = 0; i < a; i++) {
        cna = (cna % _MOD) * (n - i) / (i + 1) % _MOD;
    }
    // cout << cna;
    ll cnb = 1;
    if (b > n / 2) b = n - b;
    for (ll i = 0; i < b; i++) {
        cnb = (cnb % _MOD) * (n - i) / (i + 1) % _MOD;
    }
    // cout << endl << cnb << endl;
    ans = (ans + (ll)2 * _MOD - cna - cnb) % _MOD;
    cout << ans;
}

ll pow_mod(ll a, ll e, ll p) {
    if (e <= 0) return 1;
    ll resby = pow_mod(a, e / 2, p);
    return resby * resby % p * ((e & 1) ? a : 1) % p;
}