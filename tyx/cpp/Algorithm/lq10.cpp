#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

void dfs(vector<LL> to_dfs, vector<LL> base);

LL ans = 0b111111111111111111111111111111111111111111111111111111111111111;

int main() {
    int n, m;
    LL sticks[7];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    for (int mask = 0, tot = 1 << n; mask < tot; mask++) {
        int ctr = 0;
        vector<LL> to_dfs;
        vector<LL> base;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                ctr++;
                base.push_back(sticks[i]);
            }
            else
                to_dfs.push_back(sticks[i]);
        }
        if (ctr == m) {
            // 保留这m个
            // dfs剩余n-m个
            dfs(to_dfs, base);
        }
    }
    cout << ans;
    return 0;
}

void dfs(vector<LL> to_dfs, vector<LL> base) {
    if (to_dfs.size() == 0) {
        LL _min = 0b111111111111111111111111111111111111111111111111111111111111111;
        LL _max = 0;
        for (int i = 0; i < base.size(); i++) {
            if (base[i] < _min)
                _min = base[i];
            if (base[i] > _max)
                _max = base[i];
        }
        LL tmp = _max - _min;
        ans = min(ans, tmp);
        return;
    }
    else {
        LL tmp = to_dfs.back();
        to_dfs.pop_back();
        for (int i = 0; i < base.size(); i++) {
            base[i] += tmp;
            dfs(to_dfs, base);
            base[i] -= tmp;
        }
    }
}