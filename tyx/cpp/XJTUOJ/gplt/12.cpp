#include <bits/stdc++.h>

using namespace std;

int arr1[100005];
int arr2[100005];
// int dp[100005][100005];
int dp[2][100005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 5 * n; i++) {
        cin >> arr1[i];
    }
    for (int i = 1; i <= 5 * n; i++) {
        cin >> arr2[i];
    }
    int pos = 1;
    for (int i = 0; i <= 5 * n; i++) {
        for (int j = 0; j <= 5 * n; j++) {
            // if (i == 0 || j == 0) {
            //     dp[i][j] = 0;
            //     continue;
            // }
            // if (arr1[i] == arr2[j])
            //     dp[i][j] = dp[i - 1][j - 1] + 1;
            // else {
            //     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            // }
            if (i == 0 || j == 0) {
                dp[pos][j] = 0;
                continue;
            }
            if (pos) {
                if (arr1[i] == arr2[j]) {
                    dp[pos][j] = dp[pos - 1][j - 1] + 1;
                }
                else {
                    dp[pos][j] = max(dp[pos - 1][j], dp[pos][j - 1]);
                }
            }
            else {
                if (arr1[i] == arr2[j]) {
                    dp[pos][j] = dp[pos + 1][j - 1] + 1;
                }
                else {
                    dp[pos][j] = max(dp[pos + 1][j], dp[pos][j - 1]);
                }
            }
        }
        pos = (pos + 1) & 1;
    }
    pos = (pos + 1) & 1;
    cout << dp[pos][5 * n];
    return 0;
}