#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> P; // num, sequence

P arr1[100005], arr2[100005];
P len[100005];

bool mycmp(P a, P b) {
    return a.first < b.first;
}

bool mycmp2(P a, P b) {
    return a.second < b.second;
}

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        arr1[i] = make_pair(tmp, i);
    }
    for (ll i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        arr2[i] = make_pair(tmp, i);
    }
    sort(arr2 + 1, arr2 + n + 1);
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        P* temp = lower_bound(arr2 + 1, arr2 + n + 1, arr1[i], mycmp);
        // cout << temp->second << endl;
        if (i == 1) {
            len[ans++] = *temp;
        }
        else if (temp->second > len[ans - 1].second) {
            len[ans++] = *temp;
        }
        else {
            P* rep = upper_bound(len, len + ans, *temp, mycmp2);
            *rep = *temp;
        }
    }
    cout << ans;
    return 0;
}