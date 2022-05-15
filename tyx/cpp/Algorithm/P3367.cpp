#include <iostream>

using namespace std;

int par[50005], sz[50005];

void merge(int x, int y);
int find(int x);

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            merge(y, z);
        }
        if (x == 2) {
            bool flag = (find(y) == find(z));
            if (flag) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
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