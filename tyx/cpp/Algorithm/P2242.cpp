#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
bool mycmp(ll a, ll b) {
    return a > b;
}

int main() {
    int n, m;
    cin >> n >> m;
    ll a, b;
    cin >> a;
    ll arr[20000];
    ll ctr = 0, ans = -a;
    if (m == 0) {
        cout << 0;
        return 0;
    }
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b;
        arr[ctr++] = b - a;
        a = b;
        if (i == n - 2) ans += b;
    }
    sort(arr, arr + ctr, mycmp);
    for (int i = 0; i < m - 1; i++) {
        ans -= arr[i];
    }
    cout << ans + m;
    return 0;
}