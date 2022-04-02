#include <bits/stdc++.h>

using namespace std;

typedef struct _Node {
    int value;  // i 结点种j树能获得的最大价值
    int last;
} Node;

int dta[100005][7];
Node dp[100005][7];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> dta[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[1][1].value = dta[1][1];
    dp[1][2].value = dta[1][2];
    dp[1][3].value = dta[1][3];
    if (dp[1][2].value > dp[1][3].value) {
        dp[2][1].value = dp[1][2].value + dta[2][1];
        dp[2][1].last = 2;
    }
    else {
        dp[2][1].value = dp[1][3].value + dta[2][1];
        dp[2][1].last = 3;
    }
    dp[2][2].value = dp[1][1].value + dta[2][2];
    dp[2][2].last = 1;
    int ans = 0;
    if (dp[1][2].value > dp[1][1].value) {
        dp[2][3].value = dp[1][2].value + dta[2][3];
        dp[2][3].last = 2;
    }
    else {
        dp[2][3].value = dp[1][1].value + dta[2][3];
        dp[2][3].last = 1;
    }
    for (int i = 3; i <= n; i++) {
        if (dp[i - 1][2].last == 1) {
            dp[i][3].value = dp[i - 1][1].value + dta[i][3];
            if (dp[i - 1][1].value > dp[i - 1][3].value) {
                dp[i][2].value = dp[i - 1][1].value + dta[i][2];
                dp[i][2].last = 1;
            }
            else {
                dp[i][2].value = dp[i - 1][3].value + dta[i][2];
                dp[i][2].last = 3;
            }
            if (dp[i - 1][2].value > dp[i - 1][3].value) {
                dp[i][1].value = dp[i - 1][2].value + dta[i][1];
                dp[i][1].last = 2;
            }
            else {
                dp[i][1].value = dp[i - 1][3].value + dta[i][1];
                dp[i][1].last = 3;
            }
        }
        else {
            dp[i][1].value = dp[i - 1][3].value + dta[i][1];
            if (dp[i - 1][1].value > dp[i - 1][3].value) {
                dp[i][2].value = dp[i - 1][1].value + dta[i][2];
                dp[i][2].last = 1;
            }
            else {
                dp[i][2].value = dp[i - 1][3].value + dta[i][2];
                dp[i][2].last = 3;
            }
            if (dp[i - 1][2].value > dp[i - 1][1].value) {
                dp[i][3].value = dp[i - 1][2].value + dta[i][3];
                dp[i][3].last = 2;
            }
            else {
                dp[i][3].value = dp[i - 1][1].value + dta[i][3];
                dp[i][3].last = 1;
            }
        }
    }

    ans = max(ans, max(max(dp[n][1].value, dp[n][2].value), dp[n][3].value));

    dp[2][2].value = dp[1][3].value + dta[2][2];
    dp[2][2].last = 3;
    for (int i = 3; i <= n; i++) {
        if (dp[i - 1][2].last == 1) {
            dp[i][3].value = dp[i - 1][1].value + dta[i][3];
            if (dp[i - 1][1].value > dp[i - 1][3].value) {
                dp[i][2].value = dp[i - 1][1].value + dta[i][2];
                dp[i][2].last = 1;
            }
            else {
                dp[i][2].value = dp[i - 1][3].value + dta[i][2];
                dp[i][2].last = 3;
            }
            if (dp[i - 1][2].value > dp[i - 1][3].value) {
                dp[i][1].value = dp[i - 1][2].value + dta[i][1];
                dp[i][1].last = 2;
            }
            else {
                dp[i][1].value = dp[i - 1][3].value + dta[i][1];
                dp[i][1].last = 3;
            }
        }
        else {
            dp[i][1].value = dp[i - 1][3].value + dta[i][1];
            if (dp[i - 1][1].value > dp[i - 1][3].value) {
                dp[i][2].value = dp[i - 1][1].value + dta[i][2];
                dp[i][2].last = 1;
            }
            else {
                dp[i][2].value = dp[i - 1][3].value + dta[i][2];
                dp[i][2].last = 3;
            }
            if (dp[i - 1][2].value > dp[i - 1][1].value) {
                dp[i][3].value = dp[i - 1][2].value + dta[i][3];
                dp[i][3].last = 2;
            }
            else {
                dp[i][3].value = dp[i - 1][1].value + dta[i][3];
                dp[i][3].last = 1;
            }
        }
    }
    ans = max(ans, max(max(dp[n][1].value, dp[n][2].value), dp[n][3].value));
    cout << ans;
}