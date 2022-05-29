#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n, m, a[maxn];

bool check(int mid) {
    int ans = 0;
    for (int i = 0; i < n; ) {
        int res = a[i], pos = 1;
        for (; i + pos < n; pos++) {
            if (res + a[i + pos] > mid) break;
            res += a[i + pos];
        }
        i += pos;
        ans++;
        if (ans > m) return true;
    }
    if (ans > m) return true;
    else return false;
}

int main() {
    cin >> n >> m;
    int _max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        _max = max(a[i], _max);
    }
    int left = _max, right = (int)1e9, mid = (left + right) >> 1;
    while (left < right) {
        if (check(mid)) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
        mid = (left + right) >> 1;
    }
    cout << left;
    return 0;
}