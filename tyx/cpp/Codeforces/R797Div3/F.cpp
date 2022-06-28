#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b) {
    return a % b ? gcd(b, a % b) : b;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    int t;
    cin >> t;
    for (int o = 0; o < t; o++) {
        // int n, m;
        // cin >> n >> m;
        // cout << gcd(n, m) << endl;
        int n;
        cin >> n;
        char c[210];
        int a[210];
        bool vis[210];
        memset(vis, false, sizeof(vis));
        memset(c, 0, sizeof(c));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll g[210], ctr = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            ll res = 1;
            vis[i] = true;
            while (!vis[])
        }
    }
    return 0;
}