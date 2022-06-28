#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef struct _node {
    vector<pair<ll, ll> > to_where;
} Node;

const ll maxn = 1e6+20;

bool vis[maxn];
ll dis[maxn];
Node node[maxn];

priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;

int main() {
    ll n, m, s;
    cin >> n >> m >> s;
    fill(dis, dis + n + 5, LLONG_MAX);
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        node[a].to_where.push_back(make_pair(b, c));
    }
    vis[s] = true;
    dis[s] = 0;
    ll cur = s;
    for (ll i = 1; i < n; i++) {
        for (auto j : node[cur].to_where) {
            if (!vis[j.first] && dis[cur] + j.second < dis[j.first]) {
                dis[j.first] = dis[cur] + j.second;
                q.push(make_pair(dis[j.first], j.first));
            }
        }
        pair<ll, ll> pr = q.top();
        while (vis[pr.second]) {
            q.pop();
            pr = q.top();
        }
        vis[pr.second] = true;
        cur = pr.second;
        q.pop();
    }
    for (ll i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    return 0;
}