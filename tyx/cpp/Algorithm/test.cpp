// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long int ll;

const ll maxn = 5e5 + 10;

ll n, m, ta[maxn], tm[maxn], sum[maxn], p = 571373;

ll ls(ll k) {
    return k << 1;
}

ll rs(ll k) {
    return (k << 1) | 1;
}

void pushup(ll k) {
    sum[k] = (sum[ls(k)] + sum[rs(k)]) % p;
}

void pushdown(ll k, ll x, ll y) {
    if (ta[k] || tm[k] != 1) {
        sum[ls(k)] = (sum[ls(k)] * tm[k] + ta[k] * x) % p;
        ta[ls(k)] = (ta[ls(k)] * tm[k] + ta[k]) % p;
        tm[ls(k)] = (tm[ls(k)] * tm[k]) % p;
        sum[rs(k)] = (sum[rs(k)] * tm[k] + ta[k] * y) % p;
        ta[rs(k)] = (ta[rs(k)] * tm[k] + ta[k]) % p;
        tm[rs(k)] = (tm[rs(k)] * tm[k]) % p;
        tm[k] = 1;
        ta[k] = 0;
    }
}

void add(ll a, ll b, ll k, ll l, ll r, ll x) {
    if (l >= a && r <= b) {
        ta[k] = (ta[k] + x) % p;
        sum[k] = (sum[k] + ((r - l + 1) * x % p) % p) % p;
        return;
    }
    ll m = (l + r) >> 1;
    pushdown(k, m - l + 1, r - m);
    if (m >= a) add(a, b, ls(k), l, m, x);
    if (m < b) add(a, b, rs(k), m + 1, r, x);
    pushup(k);
}

void mlt(ll a, ll b, ll k, ll l, ll r, ll x) {
    if (l >= a && r <= b) {
        tm[k] = (tm[k] * x) % p;
        ta[k] = (ta[k] * x) % p;
        sum[k] = (sum[k] * x) % p;
        return;
    }
    ll m = (l + r) >> 1;
    pushdown(k, m - l + 1, r - m);
    if (m >= a) mlt(a, b, ls(k), l, m, x);
    if (m < b) mlt(a, b, rs(k), m + 1, r, x);
    pushup(k);
}

ll ask(ll a, ll b, ll k, ll l, ll r) {
    if (l >= a && r <= b) {
        return sum[k];
    }
    ll m = (l + r) >> 1, ans = 0;
    pushdown(k, m - l + 1, r - m);
    if (m >= a) ans = (ans + ask(a, b, ls(k), l, m)) % p;
    if (m < b) ans = (ans + ask(a, b, rs(k), m + 1, r)) % p;
    return ans;
}

int main() {
    cin >> n >> m >> p;
    fill(tm, tm + maxn, 1);
    for (ll i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        add(i, i, 1, 1, n, tmp);
    }
    for (ll i = 0; i < m; i++) {
        ll c;
        cin >> c;
        if (c == 1) {
            ll x, y, k;
            cin >> x >> y >> k;
            mlt(x, y, 1, 1, n, k);
        }
        if (c == 2) {
            ll x, y, k;
            cin >> x >> y >> k;
            add(x, y, 1, 1, n, k);
        }
        if (c == 3) {
            ll x, y;
            cin >> x >> y;
            cout << ask(x, y, 1, 1, n) << endl;
        }
    }
    return 0;
}