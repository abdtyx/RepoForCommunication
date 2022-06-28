#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll maxn = 2e5+10;

ll Mod[maxn];

int main() {
    ll t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        ll ans = 0;
        ll n, k;
        cin >> n >> k;
        // ll* rem = new ll[1005];
        ll rem[1005];
        memset(rem, 0, sizeof(rem));
        for (ll i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            ans += tmp / k;
            tmp %= k;
            rem[tmp]++;
            // Mod[i] = tmp;
        }
        // sort(Mod, Mod + n);
        // ll fst = 0, lst = n - 1;
        // bool* used = new bool[n];
        for (ll i = 1; i <= (k - 1) / 2; i++) {
            ll res = min(rem[i], rem[k - i]);
            ans += res;
            rem[i] -= res;
            rem[k - i] -= res;
        }
        if ((k & 1) == 0) {
            ll res = rem[k / 2] / 2;
            ans += res;
            rem[k / 2] %= 2;
        }
        rem[0] %= 2;
        vector<ll> truepos;
        for (ll i = 1; i < k; i++) {
            if (rem[i]) truepos.push_back(i);
        }
        if (truepos.size()) {
            for (ll i = 0; i < truepos.size() && truepos[i] <= (k - 1) / 2; i++) {
                ll j = truepos.size() - 1;
                for (; truepos[j] > k - truepos[i]; j--);
                j++;
                // i, j
                if (j < truepos.size() && truepos[j] > k - truepos[i]) {
                    ll res = min(rem[truepos[i]], rem[truepos[j]]);
                    ans += res;
                    rem[truepos[i]] -= res;
                    rem[truepos[j]] -= res;
                }
            }
            ll aa = 0;
            for (ll i = (k - 1) / 2 + 1; i < k; i++) {
                aa += rem[i];
            }
            ans += aa / 2;
        }
        cout << ans << endl;
        // delete[] rem;
    }
    return 0;
}