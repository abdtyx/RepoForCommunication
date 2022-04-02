#include <bits/stdc++.h>

using namespace std;

typedef map<int, int> MP;

map<int, int> map_add(map<int, int> a, map<int, int> b);
map<int, int> map_minus(map<int, int> a, map<int, int> b);
void updata(MP m, int k);
MP getsum(int n);
int lowbit(int x) {
    return x & (-x);
}
int n, m;

MP a[300005], c[300005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        MP tmp;
        int dt;
        cin >> dt;
        tmp.insert(make_pair(dt, 1));
        a[i] = tmp;
        updata(tmp, i);
    }
    for (int i = 0; i < m; i++) {
        int to;
        cin >> to;
        if (to == 1) {
            int l, r, cj;
            cin >> l >> r >> cj;
            MP ans = map_minus(getsum(r), getsum(l - 1));
            cout << ans[cj] << endl;
        }
        else {
            int where;
            cin >> where;
            MP updt_where_plus = a[where];
            updt_where_plus.insert(make_pair(a[where + 1].begin()->first, -a[where + 1].begin()->second));
            MP updt_where = a[where + 1];
            updt_where.insert(make_pair(a[where].begin()->first, -a[where].begin()->second));
            updata(updt_where, where);
            updata(updt_where_plus, where + 1);
            MP temp = a[where];
            a[where] = a[where + 1];
            a[where + 1] = temp;
        }
    }
    return 0;
}

map<int, int> map_add(map<int, int> a, map<int, int> b) {
    MP c = a;
    for (auto i : b) {
        if (c.find(i.first) != c.end()) {
            c[i.first] += i.second;
        }
        else {
            c.insert(make_pair(i.first, i.second));
        }
    }
    return c;
}

map<int, int> map_minus(map<int, int> a, map<int, int> b) {
    MP c = a;
    for (auto i : b) {
        if (c.find(i.first) != c.end()) {
            c[i.first] -= i.second;
        }
        else {
            c.insert(make_pair(i.first, -i.second));
        }
    }
    return c;
}

void updata(MP m, int k) {
    while (k <= n) {
        c[k] = map_add(c[k], m);
        k += lowbit(k);
    }
}

MP getsum(int r) {
    MP ans;
    while (r > 0) {
        ans = map_add(ans, c[r]);
        r -= lowbit(r);
    }
    return ans;
}