#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (isPrime(tmp) && tmp > 1)
            ans += tmp;
    }
    cout << ans;
}