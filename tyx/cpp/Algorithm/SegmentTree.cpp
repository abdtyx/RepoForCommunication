#include <bits/stdc++.h>

using namespace std;
int sum[2000005], n;
// 单点修改
void add(int p, int k, int l, int r, int x) {
    sum[k] += x;
    if (l == r) return;
    int m = (l + r) >> 1;
    if (p <= m) {
        add(p, k << 1, l, m, x);
    }
    else {
        add(p, (k << 1) | 1, m + 1, r, x);
    }
}
// 区间查询
int ask(int a, int b, int k, int l, int r) {
    if (a <= l && r <= b) {
        return sum[k];
    }
    int m = (l + r) >> 1, ans = 0;
    if (a <= m) ans += ask(a, b, k << 1, l, m);
    if (b > m) ans += ask(a, b, (k << 1) | 1, m + 1, r);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        add(i + 1, 1, 1, n, tmp);
    }
    for (int i = 0; i < m; i++) {
        int s, x, y, k;
        cin >> s;
        if (s == 1) {
            cin >> x >> k;
            add(x, 1, 1, n, k);
        }
        if (s == 2) {
            cin >> x >> y;
            cout << ask(x, y, 1, 1, n) << endl;
        }
    }
    return 0;
}