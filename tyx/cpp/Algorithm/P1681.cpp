#include <bits/stdc++.h>

using namespace std;
bool Map[1600][1600];
int ans;
bool vis[1600][1600];
void findway(int i, int j);
int n, m;

int main() {
    cin >> n >> m;
    ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) findway(i, j);
        }
    }
    cout << ans;
    return 0;
}

void findway(int i, int j) {
    for (int wide = 1; i + wide < n && j + wide < m; wide++) {
        for (int k = i, l = j + wide; k < i + wide; k++) {
            if (Map[k][l] == Map[k][l - 1]) {
                ans = max(ans, wide);
                return;
            }
        }
        for (int k = i + wide, l = j; l < j + wide; l++) {
            if (Map[k][l] == Map[k - 1][l]) {
                ans = max(ans, wide);
                return;
            }
        }
        if (Map[i + wide - 1][j + wide - 1] != Map[i + wide][j + wide]) {
            ans = max(ans, wide);
            return;
        }
        // success
        // for ()
        ans = max(ans, wide + 1);
    }
}