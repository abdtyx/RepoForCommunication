#include <bits/stdc++.h>

using namespace std;

typedef struct _node {
    int _max;
    vector<int> to_where;
} Node;

int n, m, ans = 1;
Node node[300005];

void dfs(int x) {
    if (node[x].to_where.size() == 0) {
        node[x]._max = 1;
        return;
    }
    priority_queue<int> h;
    for (auto i : node[x].to_where) {
        // goto i
        dfs(i);
        // get max
        h.push(node[i]._max);
    }
    int __max = h.top();
    h.pop();
    if (h.size() >= 1) {
        // 统计最大两个子树
        // get submax
        int submax = h.top();
        h.pop();
        int res = __max + submax + node[x].to_where.size();
        if (x == 1) res--;
        ans = max(ans, res);
    }
    node[x]._max = __max + node[x].to_where.size();
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        node[a].to_where.push_back(b);
    }
    dfs(1);
    ans = max(ans, node[1]._max);
    cout << ans;
    return 0;
}