#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;
// bool mycmp(P a, P b) {
//     return a.first < b.first;
// }

int main() {
    int n;
    P arr[100005];
    P st[100005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        st[i].first = arr[i].first;
        arr[i].second = i;
        st[i].second = i;
    }
    sort(st, st + n);
    int ans = -1;
    for (int i = 0; i < n; i++) {
        P* tmp = lower_bound(st, st + i + 1, arr[i]);
        if (tmp != st + i + 1) {
            int res = i - (tmp - st);
            // cout << res << endl;
            ans = max(ans, res);
        }
    }
    cout << ans + 1;
    return 0;
}