#include <bits/stdc++.h>

using namespace std;

void dfs(int q, queue<int> path, vector<bool> vis);
void visualization(queue<int> visualize);

int main() {
    queue<int> p;
    vector<bool> vis;
    for (int i = 0; i < 16; i++) {
        vis.push_back(false);
    }
    dfs(0, p, vis);
    return 0;
}

void dfs(int q, queue<int> path, vector<bool> vis) {
    if (q == 5 || q == 3 || q == 10 || q == 12) {
        return;
    }
    if (q == 15) {
        path.push(q);
        queue<int> visualize = path;
        while (!path.empty()) {
            cout << path.front() << ' ';
            path.pop();
        }
        cout << endl;
        visualization(visualize);
        return;
    }
    path.push(q);
    vis[q] = true;
    if ((1 << 3) & q) {
        if (!vis[q - 8]) {
            dfs(q - 8, path, vis);
        }
        for (int i = 0; i < 3; i++) {
            if (((1 << i) & q) != 1) continue;
            int tmp = q ^ (1 << i) ^ (1 << 3);
            if (!vis[tmp])
                dfs(tmp, path, vis);
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (((1 << i) & q) != 0) continue;
            int tmp = q ^ (1 << i) ^ (1 << 3);
            if (!vis[tmp])
                dfs(tmp, path, vis);
        }
    }
    return;
}

void visualization(queue<int> visualize) {
    string name[4] = {"农夫", "狼", "白菜", "羊"};
    while (!visualize.empty()) {
        int tmp = visualize.front();
        visualize.pop();
        cout << '\t';
        for (int i = 3; i >= 0; i--) {
            if ((1 << i) & tmp) {
                cout << name[3 - i] << '\t';
            }
            else {
                cout << '\t';
            }
        }
        cout << endl;
        cout << "\t——————————————————————————" << endl;
        cout << "\t——————————————————————————" << endl;
        cout << '\t';
        for (int i = 3; i >= 0; i--) {
            if ((1 << i) & tmp) {
                cout << '\t';
            }
            else {
                cout << name[3 - i] << '\t';
            }
        }
        cout << endl << endl;
        cout << "*********************************************" << endl << endl;
    }
    return;
}