#include <bits/stdc++.h>

using namespace std;

typedef struct _node {
    int ind;
    int otd;
    vector<int> to;
} Node;

Node a[30];
bool vis[30];
int n, m;

int main() {
    cin >> n >> m;
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        char f, s, q;
        cin >> f >> q >> s;
        bool flag = false;
        for (auto j : a[f - 'A'].to) {
            if (s - 'A' == j) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        a[f - 'A'].otd++;
        a[s - 'A'].ind++;
        a[f - 'A'].to.push_back(s - 'A');
    }
    while (1) {
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (a[i].ind == 0 && !vis[i]) {
                tmp.push_back(i);
                vis[i] = true;
            }
        }
        if (tmp.size() > 1) {
            cout << "Sorted sequence cannot be determined.";
            return 0;
        }
        for (auto i : tmp) {
            ans.push_back(i);
            for (auto j : a[i].to) a[j].ind--;
        }
        if (ans.size() == n) break;
    }
    for (auto i : ans) cout << (char)('A' + i);
    return 0;
}