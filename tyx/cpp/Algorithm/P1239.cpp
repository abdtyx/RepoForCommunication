#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef struct _Base {
    ll zero;
    ll els;
} Base;

typedef struct _X {
    ll x;
    ll zero;
    ll els;
} X;

int main() {
    Base b[12];
    X xx[12];
    memset(b, 0, sizeof(b));
    memset(xx, 0, sizeof(xx));
    b[1].zero = 0;
    b[1].els = 1;
    xx[1].x = 1;
    xx[1].els = 0;
    xx[1].zero = 0;
    for (int i = 2; i <= 9; i++) {
        // b[i]-> pow(10, i)
        string s;
        for (int j = 1; j < i; j++) {
            s.push_back('1');
        }
        int tmp = atoi(s.c_str());
        xx[i].zero = (ll)tmp + b[i - 1].zero;
        xx[i].x = (ll)pow(10, i - 1);
        xx[i].els = b[i - 1].els;
        b[i].els = xx[i].x + 10 * xx[i].els;
        b[i].zero = b[i - 1].zero + xx[i].zero * 9;
    }
    // cout << b[4].els << endl << b[4].zero;
    ll ans[11];
    memset(ans, 0, sizeof(ans));
    int n;
    cin >> n;
    int bit = 0;
    while (n / (int)pow(10, ++bit));
    int num[12];
    for (int i = bit; i > 0; i--) {
        num[i] = n % 10;
        n = (n - n % 10) / 10;
    }
    // for (int i = bit; i > 0; i--) {
    //     cout << num[i];
    // }
    // cout << bit;
    for (int i = bit; i > 0; i--) {
        // +b[i-1]
        ans[0] += b[i - 1].zero;
        for (int j = 1; j < 10; j++) {
            ans[j] += b[i - 1].els;
        }
        for (int j = 1; j <= num[i]; j++) {
            ans[0] += xx[i - 1].zero;
            ans[j] += xx[i - 1].x;
            for (int k = 1; k < 10; k++) {
                ans[k] += xx[i - 1].els;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}