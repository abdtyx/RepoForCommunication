<<<<<<< HEAD
#include<iostream>
#include<vector>
using namespace std;
const int maxn=3e5+10;

vector<int> e[maxn];
int n,m,d0[maxn],d1[maxn],res;

void dfs(int x) {
    for(int i=0;i<e[x].size();i++) {
        int to=e[x][i];
        if(!vis[to]) dfs(to);
        if(d0[to]+1>d0[x]) {
            d1[x]=d0[x];
            d0[x]=d0[to]+1;
        } else if(d0[to]+1>d1[x]) d1[x]=d0[to]+1;
    }

    res[x]=d0[x]+d1[x]+;
    return ;
}

int main() {
    cin>>n>>m;
    for(int i=0,x,y;i<m;i++) {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    cout<<res<<endl;
    return 0;
=======
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
>>>>>>> 96fd097b50d76a6155eb6fd5c594e7362218d2a6
}