#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int> >  ds;
int par[5005], sz[5005];
int n, m, ans;
// int flag;

void merge(int x, int y);
int find(int x);

int main() {
    cin >> n >> m;
    // flag = false;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    priority_queue<ds , vector<ds>, greater<ds> > h;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ds d;
        d.first = z;
        d.second.first = x;
        d.second.second = y;
        h.push(d);
    }
    for (int i = 1; i < n; i++) {
        if (h.size() == 0) break;
        ds d = h.top();
        h.pop();
        while (find(d.second.first) == find(d.second.second) && h.size() != 0) {
            d = h.top();
            h.pop();
        }
        merge(d.second.first, d.second.second);
        ans += d.first;
    }
    for (int i = 1; i <= n; i++) {
        if (sz[i] == n) {
            cout << ans;
            return 0;
        }
    }
    cout << "orz";
    return 0;
}

void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (sz[px] > sz[py]) swap(px, py);
    par[px] = py;
    sz[py] += sz[px];
}

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}