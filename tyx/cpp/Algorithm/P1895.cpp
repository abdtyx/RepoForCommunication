#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool ck(ll mid, ll se);

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll se;
        cin >> se;
        ll l = 0, r = se;
        ll mid = (l + r) / 2;
        while (ck(mid, se)) {
            if (mid * (mid + 1) / 2 < se) {
                l = mid + 1;
                mid = (l + r) / 2;
            }
            else {
                r = mid;
                mid = (l + r) / 2;
            }
            // cout << mid << endl;
        }
        cout << se - mid * (mid + 1) / 2 << endl;
    }
    return 0;
}

bool ck(ll mid, ll se) {
    // if (mid * (mid + 1) / 2 < se) {return true;} else return false;
    if (mid * (mid + 1) / 2 < se && (mid + 1) * (mid + 2) / 2 >= se) {
        return false;
    }
    else return true;
}