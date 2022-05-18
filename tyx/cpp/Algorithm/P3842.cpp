#include <bits/stdc++.h>

using namespace std;
pair<int, int> p[100000];
int dp[100000][2]; // 0表示到第i时在左边，1表示右边  的最短路径

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int fi, se;
        cin >> fi >> se;
        p[i] = make_pair(fi, se);
    }
    dp[1][0] = p[1].first - 1;
    dp[1][1] = p[1].second - 1;
    for (int i = 2; i <= n; i++) {
        int l = p[i - 1].second - p[i - 1].first;
        dp[i][0] = min(dp[i - 1][0] + l + abs(p[i - 1].second - p[i].first), dp[i - 1][1] + l + abs(p[i - 1].first - p[i].first));
        dp[i][1] = min(dp[i - 1][0] + l + abs(p[i - 1].second - p[i].second), dp[i - 1][1] + l + abs(p[i - 1].first - p[i].second));
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i][0] << ' ' << dp[i][1] << endl;
    // }
    cout << min(dp[n][0] + n - p[n].first, dp[n][1] + n - p[n].first + p[n].second - p[n].first) + n - 1;
    return 0;
}