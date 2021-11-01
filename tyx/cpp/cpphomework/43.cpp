#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

// LL cal(LL n, LL p);

int main() {
    LL n, p;
    cin >> n >> p;
    // LL ans = cal(n, p);
    LL ans = 0;
    for (int i = n; i > 0; i--) {
        ans += (LL)pow(i, p);
    }
    cout << ans;
    return 0;
}
/*
LL cal(LL n, LL p) {
    return (LL)pow(n, p) + cal(n - 1, p);
}
*/