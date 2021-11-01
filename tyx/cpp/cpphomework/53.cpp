#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL ans = 1;
// void hanoi(LL n);
int main() {
    LL n;
    cin >> n;
    // ans = (LL)pow(2, n) - 1;
    // hanoi(n);
    // cout << ans;
    // string s(_itoa(ans, "str", 10));
    // if (s.size() > 6)
    //     for (int i = s.size() - 6; i < s.size(); i++)
    //         cout << s[i];
    // else
    //     cout << ans;
    // stack<LL> aps;
    // if (ans >= 1000000) {
    //     for (int i = 0; i < 6; i++) {
    //         aps.push(ans % 10);
    //         ans /= 10;
    //     }
    //     while (!aps.empty()) {
    //         cout << aps.top();
    //         aps.pop();
    //     }
    // }
    // else
    //     cout << ans;
    if (n <= 19) {
        ans = (LL)pow(2, n) - 1;
        cout << ans;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        ans = (ans * 2) % 1000000;
    }
    ans -= 1;
    // int bitw = 0;
    // int tmp = ans;
    // while (ans /= 10) {
    //     bitw++;
    // }
    // bitw++;
    // for (int i = bitw; i < 6; i++) {
    //     cout << "0";
    // }
    // cout << tmp;
    cout << ans;
    return 0;
}
/*
void hanoi(LL n) {
    if (n == 0)
        return;
    hanoi(n - 1);
    ans++;
    hanoi(n - 1);
}*/