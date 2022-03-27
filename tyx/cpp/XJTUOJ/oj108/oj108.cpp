#include <bits/stdc++.h>

using namespace std;

int main() {
    double n;
    double sum = 0;
    cin >> n;
    double ans = n;
    for (int i = 1; i <= n; i++) {
        if (i % 3 && i % 5 && i % 7) {
            sum += 1.0 / (double)i;
        }
        else ans--;
    }
    cout << ans << endl << fixed << setprecision(6) << sum;
}