#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int main() {
    vector<LL> a1, a2;
    stack<LL> cache;
    LL sum1 = 0, sum2 = 0, n, r;
    cin >> n >> r;
    LL* data = new LL[n];
    vector<LL> v;
    for (LL i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data, data + n);
    for (LL i = n - 1; i >= 0; i--) {
        v.push_back(data[i]);
    }
    for (auto i : v) cout << i << ' ';

    delete [] data;
    return 0;
}