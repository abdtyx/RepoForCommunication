#include <bits/stdc++.h>

using namespace std;
void find_all_of(string raw, string substr, vector<int>& where);

int main() {
    queue<pair<string, int> > q;
    string raw, ans;
    cin >> raw >> ans;
    map<string, vector<string> > mp; // first second
    string fi, se;
    while (cin >> fi) {
        cin >> se;
        vector<string> tmp;
        tmp.push_back(se);
        if (mp.find(fi) == mp.end()) {
            mp[fi] = tmp;
        }
        else {
            mp[fi].push_back(se);
        }
    }
    if (raw == ans) {
        cout << 0;
        return 0;
    }
    q.push(make_pair(raw, 0));
    while (q.size()) {
        pair<string, int> p = q.front();
        if (p.second == 11) {
            cout << "NO ANSWER!";
            return 0;
        }
        q.pop();
        for (auto i : mp) {
            pair<string, int> _new = p;
            vector<int> where;
            find_all_of(p.first, i.first, where);
            for (auto j : where) {
                for (auto k : i.second) {
                    pair<string, int> __new = p;
                    __new.first.replace(j, i.first.size(), k);
                    __new.second++;
                    if (__new.first == ans) {
                        cout << __new.second;
                        return 0;
                    }
                    q.push(__new);
                }
            }
        }
    }
    cout << "NO ANSWER!";
    return 0;
}

void find_all_of(string raw, string substr, vector<int>& where) {
    int n = raw.size();
    int m = substr.size();
    for (int i = 0; i < n - m + 1; i++) {
        string su = raw.substr(i, m);
        if (su == substr) {where.push_back(i);}
    }
}