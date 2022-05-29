#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main() {
    int n, q;
    cin >> n >> q;
    int sum = 0, ctr = 0;
    a[ctr++] = sum;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        a[ctr++] = sum;
    }
    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        int pos = upper_bound(a, a + n + 1, tmp) - a;
        cout << pos << endl;
    }
    return 0;
}