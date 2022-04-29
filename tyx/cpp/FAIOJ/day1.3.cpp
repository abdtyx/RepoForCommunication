#include <bits/stdc++.h>

using namespace std;

void dfs(int i, bool light[]);
map<int, vector<int> > mp;
void Print(__int128_t x);

int main() {
    string fi;
    cin >> fi;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int former, latter;
        cin >> former >> latter;
        if (mp.find(former) == mp.end()) {
            vector<int> tmp;
            tmp.push_back(latter);
            mp[former] = tmp;
        }
        else {
            mp[former].push_back(latter);
        }
    }
    int change[10];
    bool light[10];
    memset(change, 0, sizeof(change));
    for (int i = 0; i < 10; i++) {
        memset(light, 0, sizeof(light));
        dfs(i, light);
        int tmp = 0;
        for (int j = 0; j < 10; j++) {
            if (light[j]) tmp++;
        }
        change[i] = tmp;
    }
    __int128_t res = 1;
    for (auto i : fi) {
        res *= change[i - '0'];
    }
    Print(res);
    return 0;
}

void Print(__int128_t x) {
    if (x == 0) return;
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    else {
        Print(x / 10);
        char ch = x % 10 + '0';
        cout << ch;
    }
}

void dfs(int i, bool light[]) {
    vector<int> to_where = mp[i];
    if (light[i]) return;
    else light[i] = true;
    if (to_where.size() == 0) return;
    for (auto j : to_where) {
        dfs(j, light);
    }
}