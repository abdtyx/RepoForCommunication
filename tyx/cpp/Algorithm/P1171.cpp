#include <bits/stdc++.h>

using namespace std;

typedef struct _Node {
    int to_else[30];
} Node;

int ans;
Node node[30];
void dfs(vector<int> to_where, int sum, int now);

int main() {
    ans = 2147483647;
    memset(node, 0, sizeof(node));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> node[i].to_else[j];
        }
    }
    vector<int> v;
    for (int i = 2; i <= n; i++) {
        v.push_back(i);
    }
    dfs(v, 0, 1);
    cout << ans;
    return 0;
}

void dfs(vector<int> to_where, int sum, int now) {
    if (to_where.size() == 0) {
        // goto 1
        sum += node[now].to_else[1];
        // compare
        if (sum < ans) ans = sum;
        return;
    }
    if (sum > ans) return;
    for (auto i : to_where) {
        // goto i
        int tmp = sum;
        tmp += node[now].to_else[i];
        vector<int> g;
        for (auto j : to_where) {
            if (j != i) g.push_back(j);
        }
        dfs(g, tmp, i);
    }
}