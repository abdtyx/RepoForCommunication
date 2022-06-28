#include <bits/stdc++.h>

using namespace std;

// typedef pair<int, vector<int> > P;           // size 下标

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        map<int, vector<int> > mp;
        for (int j = 1; j <= n; j++) {
            int sz;
            cin >> sz;
            if (mp.find(sz) == mp.end()) {
                vector<int> v;
                v.push_back(j);
                mp.insert(make_pair(sz, v));
            }
            else {
                mp[sz].push_back(j);
            }
        }
        bool flag = true;
        for (auto j : mp) {
            if (j.second.size() == 1) flag = false;
        }
        if (flag) {
            for (auto j : mp) {
                cout << j.second[j.second.size() - 1];
                for (int k = 0; k < j.second.size() - 1; k++) {
                    cout << ' ' << j.second[k];
                }
                cout << ' ';
            }
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}