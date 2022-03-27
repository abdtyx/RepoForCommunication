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
    // cout << sizeof(a);
    memset(a, 0, sizeof(a));
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        updata(i, a[i] - a[i - 1]);

    }
    for (int i = 1; i <= m; i++) {
        ll where;
        cin >> where;
        if (where == 1) {
            ll x, y, k;
            cin >> x >> y >> k;
            updata(x, k);
            updata(y + 1, -k);
        }
        if (where == 2) {
            ll q;
            cin >> q;
            cout << getsum(q) << endl;
        }
    }
    return 0;
}