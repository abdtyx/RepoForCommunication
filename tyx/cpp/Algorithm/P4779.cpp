#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
bool vis[1000005];
ll dis[1000005];
typedef struct _Node {
    vector<pair<ll, ll> > to_where; // where, weight
} Node;
Node node[1000005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q; 

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    fill(dis, dis + n + 10, INT_MAX);

    for (int i = 0; i < m; i++) {
        int nd;
        cin >> nd;
        int where, value;
        cin >> where >> value;
        node[nd].to_where.push_back(make_pair(where, value));
    }
    vis[s] = true;
    dis[s] = 0;
    int curr = 1;
    for (int i = 1; i < n; i++) {
        for (auto j : node[curr].to_where) {
            if (!vis[j.first] && dis[curr] + j.second < dis[j.first]) {
                dis[j.first] = dis[curr] + j.second;
                q.push(make_pair(dis[j.first], j.first));
            }
        }
        // int _min = INT_MAX;
        // int w;
        // for (int j = 1; j <= n; j++) {
        //     if (!vis[j] && dis[j] < _min) {
        //         w = j;
        //         _min = dis[j];
        //     }
        // }
        // vis[w] = true;
        // dis[w] = _min;
        // curr = w;
        pair<ll, ll> pr = q.top();
        while (vis[pr.second]) {q.pop(); pr = q.top();}
        vis[pr.second] = true;
        // dis[pr.second] = pr.first;
        curr = pr.second;
        q.pop();
    }
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    return 0;
}