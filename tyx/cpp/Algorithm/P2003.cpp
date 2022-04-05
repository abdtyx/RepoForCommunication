#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef struct _board {
    ll height, left, right;
    bool operator<(struct _board b) {
        return height < b.height;
    }
} Board;

int main() {
    int n;
    Board bd[200];
    cin >> n;
    // ll exl = 100000, exr = -1;
    ll Cover[10005];
    memset(Cover, 0, sizeof(Cover));
    for (int i = 0; i < n; i++) {
        cin >> bd[i].height >> bd[i].left >> bd[i].right;
        // exl = min(bd[i].left, exl);
        // exr = max(bd[i].right, exr);
    }
    sort(bd, bd + n);
    // for (int i = 0; i < n; i++) {
    //     cout << bd[i].height << endl;
    // }
    ll ans = 0;
    // l to r - 1
    for (int i = 0; i < n; i++) {
        ans += 2 * bd[i].height - Cover[bd[i].left] - Cover[bd[i].right - 1];
        for (int j = bd[i].left; j < bd[i].right; j++) {
            Cover[j] = bd[i].height;
        }
    }
    cout << ans;
    return 0;
}