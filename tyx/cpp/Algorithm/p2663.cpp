#include <bits/stdc++.h>

using namespace std;

bool dp[51][5005][101];
int a[1000];

int main() {
    int n;
    cin >> n;
    int sumscore = 0, midscore = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[1][a[i]][i] = true;
        sumscore += a[i];
    }
    midscore = sumscore / 2;
    for (int i = 1; i < n / 2; i++) {
        for (int j = 0; j <= midscore; j++) {
            vector<int> truepos;
            for (int k = 1; k <= n; k++) {
                if (dp[i][j][k]) {
                    truepos.push_back(k);
                }
            }
            if (truepos.size()) {
                for (int k = 1; k <= n; k++) {
                    if (!dp[i][j][k]) {
                        if (j + a[k] <= midscore) {
                            dp[i + 1][j + a[k]][k] = true;
                            for (auto l : truepos) {
                                dp[i + 1][j + a[k]][l] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= midscore; j++) {
        bool islegal = false;
        for (int k = 1; k <= n; k++) {
            if (dp[n / 2][j][k]) {
                islegal = true;
                break;
            }
        }
        if (islegal) {
            ans = j;
        }
    }
    cout << ans;
    return 0;
}