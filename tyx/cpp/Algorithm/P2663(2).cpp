#include <bits/stdc++.h>

using namespace std;

int n, a[1000];
bool dp[100][10000];

int main() {
    cin >> n;
    int sumscore = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sumscore += a[i];
    }
    sumscore /= 2;
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {//the last one
        for (int j = min(i, n / 2); j >= 1; j--) {//number of stu
            for (int k = sumscore; k - a[i] >= 0; k--) {//sum
                dp[j][k] |= dp[j - 1][k - a[i]];
            }
        }
    }
    int ans;
    for (int i = n / 2, j = 0; j <= sumscore; j++) {
        if (dp[i][j]) ans = j;
    }
    cout << ans;
    return 0;
}