#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef pair<ll, ll> FL;

const ll maxn = 4e5 + 10;

ll value[maxn];
set<ll> sum[maxn];
FL fl[maxn];

ll ans;

ll ls(ll x) {return x << 1;}
ll rs(ll x) {return (x << 1) | 1;}

ll findrs(ll k) {
    if (sum[k].size() == 1) {
        return value[k];
    }
    return findrs(rs(k));
}

ll findls(ll k) {
    if (sum[k].size() == 1) {
        return value[k];
    }
    return findls(ls(k));
}

void pushup(ll k) {
    // sum[k].insert(sum[ls(k)].begin(), sum[ls(k)].end());
    // sum[k].insert(sum[rs(k)].begin(), sum[rs(k)].end());
}

void pushdown(ll k) {

}

void add(ll a, ll b, ll k, ll l, ll r, ll x) {
    // if (a <= l && r <= b) {
    //     sum[k].clear();
    //     sum[k].insert(x);
    //     value[k] = x;
    //     return;
    // }
    sum[k].insert(x);
    if (l == r) {
        value[k] = x;
        fl[k].first = fl[k].second = x;
        return;
    }
    ll m = (l + r) >> 1;
    // pushdown(k);
    if (m >= a) add(a, b, ls(k), l, m, x);
    if (m < b) add(a, b, rs(k), m + 1, r, x);
    // pushup(k);
    if (fl[k].first == 0) fl[k].first = x;
    fl[k].second = x;
}

void change(ll x, ll y, ll k, ll l, ll r) {
    if (sum[k].size() == 1 && value[k] == x) {
        value[k] = y;
        sum[k].clear();
        sum[k].insert(y);
        fl[k].first = fl[k].second = y;
        return;
    }
    ll m = (l + r) >> 1;
    if (sum[ls(k)].find(x) != sum[ls(k)].end()) change(x, y, ls(k), l, m);
    if (sum[rs(k)].find(x) != sum[rs(k)].end()) change(x, y, rs(k), m + 1, r);
    sum[k].erase(x);
    sum[k].insert(y);
    if (sum[k].size() == 1) value[k] = y;
    if (fl[k].first == x) fl[k].first = y;
    if (fl[k].second == x) fl[k].second = y;
}

void ask(ll k, ll l, ll r) {
    // if (a <= l && r <= b) {
    //     ans.insert(sum[k].begin(), sum[k].end());
    //     return;
    // }
    // ll m = (l + r) >> 1;
    // pushdown(k);
    // if (m >= a) ask(a, b, ls(k), l, m);
    // if (m < b) ask(a, b, rs(k), m + 1, r);
    if (sum[k].size() == 1) {
        ans++;
        return;
    }
    // if (findrs(ls(k)) == findls(rs(k))) ans--;
    if (fl[ls(k)].second == fl[rs(k)].first) ans--;
    ll m = (l + r) >> 1;
    ask(ls(k), l, m);
    ask(rs(k), m + 1, r);
}

int main() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        add(i, i, 1, 1, n, tmp);
    }
    for (ll i = 1; i <= m; i++) {
        ll cr;
        cin >> cr;
        if (cr == 1) {
            ll x, y;
            cin >> x >> y;
            change(x, y, 1, 1, n);
        }
        if (cr == 2) {
            // cout << sum[1].size() << endl;
            ans = 0;
            ask(1, 1, n);
            cout << ans << endl;
        }
    }
    return 0;
}