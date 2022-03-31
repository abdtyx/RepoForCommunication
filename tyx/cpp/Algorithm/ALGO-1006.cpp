#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int data[1005][1005];
    int dp[1005][1005];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> data[i][j];
        }
    }
    dp[1][1] = data[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j != 1) {
                dp[i][j] = dp[i][j - 1] + data[i][j];
                continue;
            }
            if (i != 1 && j == 1) {
                dp[i][j] = dp[i - 1][j] + data[i][j];
                continue;
            }
            if (i != 1 && j != 1) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + data[i][j];
            }
            if (i == n && j == n) {
                cout << dp[i][j];
            }
        }
    }
    return 0;
}