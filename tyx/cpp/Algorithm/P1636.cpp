#include <bits/stdc++.h>

using namespace std;

int du[1005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        du[x]++;
        du[y]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (du[i] & 1) ans++;
    }
    if (ans == 0) cout << 1;
    else cout << ans / 2;
    return 0;
}