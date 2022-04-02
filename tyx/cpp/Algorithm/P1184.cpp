#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    set<string> s;
    int ans = 0;
    cin >> n >> m;
    string abd;
    getline(cin, abd);
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        string tmp;
        getline(cin, tmp);
        s.insert(tmp);
    }
    for (int i = 0; i < m; i++) {
        string tmp;
        getline(cin, tmp);
        if (s.find(tmp) != s.end()) ans++;
    }
    cout << ans;
    return 0;
}