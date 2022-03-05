#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    v.clear();
    if (n == 2 || n == 1) {
        cout << n - 1;
        return 0;
    }
    for (int i = 2; i <= (int)sqrt(n); i++) {
        while (n % i == 0) {
            v.push_back(i);
            n /= i;
        }
        if (i >= (int)sqrt(n) && n != 1) {
            v.push_back(n);
        }
    }
    // for (auto i : v) {
    //     cout << i << ' ';
    // }
    long long int ans = 0;
    for (int i = 1; i < v.size(); i++) {
        long long int tmp = 1;
        for (int j = i; j < v.size(); j++) {
            tmp *= v[j];
        }
        ans += tmp;
    }
    cout << ans + 1;
    return 0;
}