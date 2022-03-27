#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    for (ll i = n; i >= 1; i--) {
        ans *= i;
    }
    if (ans % k) cout << ans / k + 1;
    else cout << ans / k;
    return 0;
}