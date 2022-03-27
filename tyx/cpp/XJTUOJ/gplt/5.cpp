#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n / (int)pow(k, ans++));
    cout << ans - 1;
    return 0;
}