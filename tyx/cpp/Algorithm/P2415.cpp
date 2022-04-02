#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ll arr[35];
    ll ctr = 0;
    ll tmp;
    while (cin >> tmp) {
        arr[ctr++] = tmp;
    }
    ctr--;
    ll ans = 0;
    for (int i = 0; i <= ctr; i++) {
        ans += arr[i] * (1 << ctr);
    }
    cout << ans;
    return 0;
}