#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 5e5 + 10;

ll n, m, sum[maxn];
bool lazy[maxn];

ll ls(ll k) {return k << 1;}
ll rs(ll k) {return (k << 1) | 1;}

void pushup(ll k) {
    sum[k] = sum[ls(k)] + sum[rs(k)];
}

void sqr(ll a, ll b, ll k, ll l, ll r) {
    if (a <= l && b >= r && lazy[k]) {
        return;
    }
    if (l == r) {
        sum[k] = (ll)sqrt(sum[k]);
        if (sum[k] == 1) lazy[k] = 1;
        return;
    }
    ll m = (l + r) >> 1;
    if (m >= a) sqr(a, b, ls(k), l, m);
    if (m < b) sqr(a, b, rs(k), m + 1, r);
    pushup(k);
    if (sum[k] == r - l + 1) lazy[k] = 1;
}

void add(ll p, ll k, ll l, ll r, ll x) {
    sum[k] += x;
    if (l == r) return;
    ll m = (l + r) >> 1;
    if (m >= p) add(p, ls(k), l, m, x);
    else add(p, rs(k), m + 1, r, x);
}

ll ask(ll a, ll b, ll k, ll l, ll r) {
    if (a <= l && b >= r) {
        return sum[k];
    }
    ll m = (l + r) >> 1, ans = 0;
    if (m >= a) ans += ask(a, b, ls(k), l, m);
    if (m < b) ans += ask(a, b, rs(k), m + 1, r);
    return ans;
}

int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        add(i, 1, 1, n, tmp);
    }
    cin >> m;
    for (ll i = 0; i < m; i++) {
        ll c;
        cin >> c;
        if (c == 0) {
            ll x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            sqr(x, y, 1, 1, n);
        }
        if (c == 1) {
            ll x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            cout << ask(x, y, 1, 1, n) << endl;
        }
    }
    return 0;
}