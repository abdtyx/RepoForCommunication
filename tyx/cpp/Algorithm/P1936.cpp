#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

// int main() {
//     ll k;
//     cin >> k;
//     for (ll n = k; n >= 1; n--) {
//         for (ll m = n; m >= 1; m--) {
//             ll ex = n*n-m*n-m*m;
//             if ((ex == 1 || ex == -1)) {
//                 cout << "m=" << m << endl;
//                 cout << "n=" << n << endl;
//                 return 0;
//             }
//         }
//     }
// }

int main() {
    ll f1 = 1, f2 = 1;
    ll k;
    cin >> k;
    for (int i = 0; i < 40; i++) {
        // cout << f1 + f2 << ' ';
        ll tmp = f1 + f2;
        if (tmp > k) {
            cout << "m=" << f1 << endl;
            cout << "n=" << f2 << endl;
            return 0;
        }
        f1 = f2;
        f2 = tmp;
    }
    return 0;
}