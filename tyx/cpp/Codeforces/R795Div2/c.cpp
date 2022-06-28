#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int pos1 = 0;
        bool flag1 = false;
        for (; pos1 < s.size(); pos1++) {
            if (s[pos1] == '1') {flag1 = true; break;}
        }
        int pos2 = s.size() - 1;
        for (; pos2 >= 0; pos2--) {
            if (s[pos2] == '1') {flag1 = true; break;}
        }
        pos2 = s.size() - pos2 - 1;
        long long int ans = 0;
        if (!flag1) {
            cout << "0" << endl;
            continue;
        }
        for (auto j : s) {
            if (j == '1') ans += (long long int)11;
        }
        if (ans == (long long int)11) {
            if (pos2 <= k) {
                cout << 1 << endl;
                continue;
            }
            else if (pos1 <= k) {
                cout << 10 << endl;
                continue;
            }
        }
        if (pos2 <= k) {
            ans -= (long long int)10;
            if (pos1 + pos2 <= k) {
                ans -= (long long int)1;
            }
        }
        else if (pos1 <= k) {
            ans -= (long long int)1;
        }
        cout << ans << endl;
    }
    return 0;
}