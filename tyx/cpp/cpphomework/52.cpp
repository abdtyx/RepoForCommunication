#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL f1, f2, a, b, c;
LL recursion(LL n);

int main() {
    LL n;
    cin >> f1 >> f2 >> a >> b >> c >> n;
    LL ans = recursion(n) % 1000007;
    if (ans < 0)
        ans += 1000007;
    cout << ans;
}

LL recursion(LL n) {
    if (n == 1)
        return f1;
    if (n == 2)
        return f2;
    // return (LL)abs((LL)abs((a * recursion(n - 2)) % 1000007) + ((LL)abs(b * recursion(n - 1)) % 1000007) + c) % 1000007;
    return (a * recursion(n - 2) + b * recursion(n - 1) + c);
}