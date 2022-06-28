#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll p = 998244353;

ll pow_mod(ll a, ll x) {
    if (x == 1) {return a;}
    ll resby2 = pow_mod(a, x / 2);
    return resby2 * resby2 % p * ((x&1)?a:1) % p;
}

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        ll n;
        cin >> n;
        ll ans = n * (n - 1) % p * (n - 2) % p * (n - 2) % p * pow_mod(2, p-2) % p;
        cout << ans << endl;
    }
    return 0;
}