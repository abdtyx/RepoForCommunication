#include <bits/stdc++.h>

using namespace std;

int w[25][25];
int dp[1 << 20][25];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }
    // dp[0][0] = 0;
    // 预处理
    for (int i = 1; i < n; i++) {
        dp[1<<i][i] = w[1][i + 1];
    }
    for (int i = 2; i < (1 << n); i+=2) {
        for (int j = 1; j < n; j++) {
            // cout << (int)((1<<j)^i);
            if ((int)((1<<j)^i) == 0) {
                // dp[i][j] = w[1][j + 1];
                continue;
            }
            if ((1<<j)&i) {
                int lst = (1<<j) ^ i;
                int _min = 2147483646;
                // int where;
                for (int k = 1; k < n; k++) {
                    if ((1<<k)&lst) {
                        if (_min > dp[lst][k]) {
                            // where = k;
                            _min = min(_min, dp[lst][k] + w[k + 1][j + 1]);
                        }
                    }
                }
                dp[i][j] = _min;
            }
            else continue;
        }
    }
    int ans = 2147483646;
    for (int i = (1 << n) - 2, j = 1; j < n; j++) {
        int tmp = dp[i][j] + w[j + 1][1];
        ans = min(tmp, ans);
    }
    cout << ans;
    // cout << endl;
    // for (int i = 2; i < (1<<n); i+=2) {
    //     for (int j = 1; j < n; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    return 0;
}