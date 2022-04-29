#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

void dfs(string s);

int main() {
    cin >> n;
    string na;
    dfs(na);
    cout << ans;
    return 0;
}

void dfs(string s) {
    if (s.size() == n) {
        // set<string> ss;
        bool flag = true;
        for (int i = 0; i + 3 < s.size(); i++) {
            if (s[i] == s[i + 2] && s[i + 1] == s[i + 3]) flag = false;
        }
        // if (ss.size() == n - 1) ans++;
        if (flag) ans++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        string nxt = s;
        nxt.push_back('A' + i);
        dfs(nxt);
    }
    return;
}