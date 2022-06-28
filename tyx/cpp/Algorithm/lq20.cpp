#include <bits/stdc++.h>

using namespace std;
int stat[50005][27];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (s.size() % n) {
        cout << -1;
        return 0;
    }
    int seg = s.size() / n;
    for (int i = 1; i <= seg; i++) {
        for (int j = 0; j < n; j++) {
            // i * j - 1
            stat[i][s[i+(seg*j)-1]-'a']++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= seg; i++) {
        int _max = 0;
        for (int j = 0; j < 26; j++) {
            _max = max(stat[i][j], _max);
        }
        ans += (n - _max);
    }
    cout << ans;
    return 0;
}