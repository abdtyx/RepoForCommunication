#include <bits/stdc++.h>

using namespace std;

#define MAXN 500000

typedef long long int ll;

ll lowbit(ll x) {return x & (-x);}

ll a[MAXN], c1[MAXN], c2[MAXN];
ll n;

void updata(ll i, ll k) {
    ll x = i;
    while (i <= n) {
        c1[i] += k;
        c2[i] += k * (x - 1);
        i += lowbit(i);
    }
}

ll getsum(ll i) {
    ll ans = 0, x = i;
    while (i > 0) {
        ans += x * c1[i] - c2[i];
        i -= lowbit(i);
    }
    return ans;
}

int main() {
    ll m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        updata(i, a[i] - a[i - 1]);
    }
    for (ll i = 1; i <= m; i++) {
        ll where;
        cin >> where;
        if (where == 1) {
            ll x, y, k;
            cin >> x >> y >> k;
            updata(x, k);
            updata(y + 1, -k);
        }
        if (where == 2) {
            ll x, y;
            cin >> x >> y;
            cout << getsum(y) - getsum(x - 1) << endl;
        }
    }
    return 0;
}