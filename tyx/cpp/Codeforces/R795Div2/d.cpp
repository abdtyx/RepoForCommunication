#include <bits/stdc++.h>
using namespace std;

// long long a[300000];

typedef long long int ll;

int main() {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n;
        cin >> n;
        ll* a = new ll[n + 10];
        vector<long long> positive;
        for (long long j = 0; j < n; j++) {
            cin >> a[j];
            if (a[j] > 0) positive.push_back(j);
        }
        if (positive.size() < 2) {
            cout << "YES" << endl;
        }
        else {
            bool trueflag = true;
            for (ll interval = 1; interval <= n - 1; interval++) {
                bool flag = true;
                for (long long j = 0; j < positive.size() - interval; j++) {
                    ll sum = 0;
                    for (long long k = positive[j]; k <= positive[j + interval]; k++) {
                        sum += a[k];
                    }
                    if (sum > max(a[positive[j]], a[positive[j + interval]])) {
                        cout << "NO" << endl;
                        flag = false;
                        trueflag = false;
                        break;
                    }
                }
                if (!flag) {
                    // cout << "YES" << endl;
                    break;
                }
            }
            if (trueflag) {
                cout << "YES" << endl;
            }
        }
        delete[] a;
    }
    return 0;
}