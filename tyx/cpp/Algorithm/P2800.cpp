#include <bits/stdc++.h>

using namespace std;
int dp[1000005];
int a[1000005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = a[2];
    dp[3] = a[3];
    for (int i = 4; i <= n + 1; i++) {
        dp[i] = min(dp[i - 3], min(dp[i - 2], dp[i - 1])) + a[i];
    }
    cout << dp[n + 1];
    return 0;
}