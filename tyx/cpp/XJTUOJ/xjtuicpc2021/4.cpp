#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > v;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        bool flag = true;
        // for (auto j : v) {
        for (int k = 0; k < v.size(); k++) {
            vector<int>& j = v[k];
            if ((tmp - j[0]) % 200 == 0) {j.push_back(tmp); flag = false;}
        }
        if (flag) {
            vector<int> v2;
            v2.push_back(tmp);
            v.push_back(v2);
        }
    }
    long long sum = 0;
    for (auto j : v) {
        sum += (j.size() * (j.size() - 1)) / 2;
    }
    cout << sum;
    return 0;
}