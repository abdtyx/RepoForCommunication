#include <bits/stdc++.h>

using namespace std;

int dfs(int i, int length);

typedef struct _node {
    int ind;
    int otd;
    vector<int> to_where;
    int max_length;
} Node;

Node node[5005];

int ans = 0, _max = 0;


int main() {
    int n, m;
    cin >> n >> m;
    // 初始化
    for (int i = 1; i <= n; i++) {
        node[i].ind = 0;
        node[i].otd = 0;
        node[i].max_length = 0;
        node[i].to_where.clear();
    }
    // 存图
    for (int i = 0; i < m; i++) {
        int no_de, go_to;
        cin >> no_de >> go_to;
        node[no_de].otd++;
        node[go_to].ind++;
        node[no_de].to_where.push_back(go_to);
    }
    // 图的遍历
    for (int i = 1; i <= n; i++) {
        if (node[i].ind == 0) {
            // ans += dfs(i, 0);
            ans = (ans + dfs(i, 0)) % 80112002;
        }
        /*
        int tmp = 0;
        if (node[i].ind == 0) {
            // 回收入度为0节点遍历结果
            tmp = dfs(node[i], 0);
        }
        if (tmp > _max) {
            _max = tmp;
            ans = 1;
        }
        else if (tmp == _max) {
            ans++;
        }
        // tmp < _max舍去
        */
    }
    cout << ans;
}


int dfs(int i, int length) {
    // 每个节点要回收下一个节点的结果，会收到许多回收，求其和，返回结果。
    // .
    // int restore = 1;
    Node nd = node[i];
    // dfs出口
    if (nd.max_length != 0) {
        return nd.max_length;
    }
    if (nd.otd == 0) {
        /*
        if (length + 1 > _max) {
            _max = length + 1;
            ans = 1;
            return 1;
        }
        else if (length + 1 == _max) {
            ans++;
            return 1;
        }
        */
    //    ans++;
       return 1;
    }
    // 向下dfs
    int tmp_restore = 0;
    for (auto j : nd.to_where) {
        int tmp = dfs(j, length + 1);
        // if (tmp + 1 > tmp_restore)
        // tmp_restore += tmp;
        tmp_restore = (tmp_restore + (tmp % 80112002)) % 80112002;
    }
    node[i].max_length = tmp_restore;
    return tmp_restore;
}