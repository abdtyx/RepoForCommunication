#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll n;
ll a[500005], c[500005];

ll lowbit(ll x) {return x & (-x);}

void updata(ll pos, ll data) {
    while (pos <= n) {
        c[pos] += data;
        pos += lowbit(pos);
    }
}

ll getsum(ll r) {
    // 1-r
    ll ans = 0;
    while (r > 0) {
        ans += c[r];
        r -= lowbit(r);
    }
    return ans;
}

int main() {
    ll m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        updata(i, a[i]);
    }
    for (ll i = 1; i <= m; i++) {
        ll swi, l, r;
        cin >> swi >> l >> r;
        if (swi == 1) {
            // b == x, c == k
            updata(l, r);
            a[l] += r;
        }
        if (swi == 2) {
            // b == l, c == r;
            cout << getsum(r) - getsum(l - 1) << endl;
        }
    }
    return 0;
}