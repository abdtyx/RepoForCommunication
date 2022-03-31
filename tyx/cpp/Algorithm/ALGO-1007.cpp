#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double dp[25][25];
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            if (i < j) {
                dp[i][j] = 0;
                continue;
            }
            if (j == 1 && i != 1) {
                dp[i][j] = dp[i - 1][j] * (double)j / (double) n;
                continue;
            }
            dp[i][j] = dp[i - 1][j] * (double)j / (double)n + dp[i - 1][j - 1] * (double)(n - j + 1) / (double)n;
        }
    }
    cout << fixed << setprecision(4) << dp[m][n];
}