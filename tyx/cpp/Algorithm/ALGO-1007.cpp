#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << "0.0000";
        return 0;
    }
    // double total = pow(n, m);
    // A m n
    double times = 1;
    for (int i = m; i > m - n; i--) {
        times = times * (double)i / (double)n;
    }
    for (int i = 0; i < m - n; i++) {
        times /= (double)n;
    }
    cout << fixed << setprecision(4) << times;
}