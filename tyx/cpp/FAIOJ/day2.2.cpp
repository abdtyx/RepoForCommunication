#include <bits/stdc++.h>

using namespace std;

int l, n, m;
int d[100000];

bool check(int mid) {
    int res = 0;
    for (int i = 0; i < n; ) {
        int pos = 1;
        while (d[i + pos] - d[i] < mid) {
            pos++;
            if (i + pos > n) break;
        }
        i += pos;
        res += pos - 1;
    }
    if (res <= m) return true;
    else return false;
}

int main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    int left = 1, right = l, mid = (left + right + 1) >> 1;
    while (left < right) {
        if (check(mid)) {
            left = mid;
        }
        else {
            right = mid - 1;
        }
        mid = (left + right + 1) >> 1;
    }
    cout << left;
    return 0;
}