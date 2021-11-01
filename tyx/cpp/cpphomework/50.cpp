#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> mp;
    mp.clear();
    string tmp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (mp.find(tmp) == mp.end()) {
            mp.insert(make_pair(tmp, 1));
        }
        else
            mp[tmp]++;
    }
    pair<string, int> ans = make_pair("123", 0);
    for (auto i : mp) {
        if (i.second > ans.second)
            ans = i;
    }
    cout << ans.first << " " << ans.second;
    return 0;
}