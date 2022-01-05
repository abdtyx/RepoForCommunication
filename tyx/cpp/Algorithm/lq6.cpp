#include <bits/stdc++.h>

using namespace std;

bool mycmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    else 
        return a.size() < b.size();
}


int main() {
    int n;
    cin >> n;
    vector<string> ans;
    ans.clear();
    // 判断五位是否可行
    if (n & 1) {
        // 中间
        for (int i = 1; i <= 9; i += 2) {
            // 第一位
            for (int j = 1; j <= 9; j++) {
                // 第二位
                for (int k = 0; k <= 9; k++) {
                    if (i + 2 * j + 2 * k == n) {
                        string s;
                        s.push_back(j + '0');
                        s.push_back(k + '0');
                        s.push_back(i + '0');
                        s.push_back(k + '0');
                        s.push_back(j + '0');
                        ans.push_back(s);
                        // cout << j << k << i << k << j << endl;
                    }
                }
            }
        }
    }
    else {
        // 五位且中间为偶数
        for (int i = 0; i <= 8; i += 2) {
            for (int j = 1; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    if (i + 2 * j + 2 * k == n) {
                        string s;
                        s.push_back(j + '0');
                        s.push_back(k + '0');
                        s.push_back(i + '0');
                        s.push_back(k + '0');
                        s.push_back(j + '0');
                        ans.push_back(s);
                    }
                }
            }
        }
        // 判断六位是否可行
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    if (2 * (i + j + k) == n) {
                        string s;
                        s.push_back(i + '0');
                        s.push_back(j + '0');
                        s.push_back(k + '0');
                        s.push_back(k + '0');
                        s.push_back(j + '0');
                        s.push_back(i + '0');
                        ans.push_back(s);
                    }
                }
            }
        }
    }
    sort(&ans[0], &ans[0] + ans.size(), mycmp);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}