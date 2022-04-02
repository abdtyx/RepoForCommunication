#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll pow2(ll times) {
    if (times == 0) return 1;
    if (times == 1) return 2;
    ll resby = pow2(times / 2);
    return resby * resby * ((times & 1) ? (ll)2 : (ll)1);
}

int main() {
    ll a, b;
    cin >> a >> b;
    // ll ctr = 0;
    // ll i = 0;
    // for (; i < 64; i++) {
    //     ctr += pow2(i);
    //     if (ctr >= a && ctr <= b) {
    //         cout << i + 1;
    //         return 0;
    //     }
    //     if (ctr > b) break;
    // }
    // while (ctr > b) {
    //     ll ub = ctr - a;
    //     ll j = 0;
    //     for (; pow2(j) < ub; j++);
    //     j--;
    //     ctr -= pow2(j);
    //     i--;
    // }
    // cout << i + 1;

    // ll ans = 0;
    // while (1) {
    //     ll i = 0;
    //     for (; pow2(i) < b - ctr; i++);
    //     i--;
    //     ctr += pow2(i);
    //     ans++;
    //     if (ctr == b) {
    //         cout << ans;
    //         return 0;
    //     }
    // }
    // ll ans = 0;
    // ll first = 0;
    // bool flag = false;
    // ll i = 63;
    // for (; i >= 0; i--) {
    //     if (flag && ((ll)1 << i) & b) break;
    //     if (((ll)1 << i) & b) {
    //         first = i;
    //         flag = true;
    //     }
    // }
    // for (ll j = 0; j <= i; j++) {
    //     ans += (1 << j);
    // }
    // ans += (1 << first);
    // if (ans >= a) cout << i + 1;
    // else {
    //     for (ll k = 0; k < 63; k++) {

    //     }
    // }
    while ((a | a + 1) <= b) a |= a + 1;
    ll ans = 0;
    for (ll i = 0; i < 64; i++) {
        if (((ll)1 << i) & a) ans++;
    }
    cout << ans;
    return 0;
}