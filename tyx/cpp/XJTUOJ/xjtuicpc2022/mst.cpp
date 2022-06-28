#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll par[10000], sz[10000];

typedef pair<ll, pair<ll, ll> > P;
P e[300000], t[300000];

ll find(ll x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void merg(ll x, ll y) {
    ll sx = find(x), sy = find(y);
    if (sx == sy) return;
    if (sz[sx] < sz[sy]) swap(sx, sy);
    sz[sx] += sz[sy];
    par[sy] = sx;
}

void merge(ll l, ll r) {
    if (r - l <= 1) return;
    ll m = l + ((r - l) >> 1);
    merge(l, m);
    merge(m, r);
    ll p = l, q = m, s = l;
    while (s < r) {
        if (p >= m || (q < r && e[q] < e[p])) t[s++] = e[q++];
        else t[s++] = e[p++];
    }
    for (ll i = l; i < r; i++) e[i] = t[i];
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        sz[i] = 1;
        par[i] = i;
    }
    for (ll i = 0; i < m; i++) {
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    }
    merge(0, m);
    // sort(e, e + m);
    ll ans = 0;
    for (ll i = 0; i < m; i++) {
        if (find(par[e[i].second.first]) != find(par[e[i].second.second])) {
            ans += e[i].first;
            merg(e[i].second.first, e[i].second.second);
        }
    }
    for (ll i = 1; i <= n; i++) {
        if (sz[i] == n) {
            cout << ans;
            return 0;
        }
    }
    cout << "orz";
    return 0;
}