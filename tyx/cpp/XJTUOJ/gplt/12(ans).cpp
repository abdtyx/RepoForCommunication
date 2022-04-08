#include <bits/stdc++.h>

using namespace std;
int dp[500005];
vector<int> d[100005];
int c[500005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 5 * n; i++) {
        int tmp;
        cin >> tmp;
        d[tmp].push_back(i);
    }
    int ctr = 0;
    for (int i = 1; i <= n; i++) {
        reverse(d[i].begin(), d[i].end());
    }
    for (int i = 1; i <= 5 * n; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < 5; j++) {
            c[ctr++] = d[tmp][j];
        }
    }
    // ctr = 0;
    // memset(dp, 500000, sizeof(dp));
    for (int i = 0; i < 100005; i++) {
        dp[i] = 2147483647;
    }
    for (int i = 0; i < 25 * n; i++) {
        *lower_bound(dp, dp + 100005, c[i]) = c[i];
    }
    int ans;
    for (ans = 0; dp[ans] != 2147483647; ans++);
    cout << ans;
}
