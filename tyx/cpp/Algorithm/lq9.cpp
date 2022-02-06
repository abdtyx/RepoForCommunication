#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

bool mycmp(int a, int b) {
    return a > b;
}

int main() {
    int n, m;
    LL ans = 0;
    cin >> n >> m;
    int* data = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data, data + n, mycmp);
    for (int i = 0; i < m; i++) {
        ans += data[i];
    }
    cout << ans;
    delete [] data;
    return 0;
}