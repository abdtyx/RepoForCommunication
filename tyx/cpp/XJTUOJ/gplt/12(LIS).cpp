#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef pair<ll, ll> P; // num, sequence
typedef pair<ll, queue<ll> > P2;

P arr1[100005];
P2 arr2[100005];
P len[100005];

bool mycmp(P2 a, P2 b) {
    return a.first < b.first;
}

bool mycmp2(P a, P b) {
    return a.second < b.second;
}

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= 5 * n; i++) {
        ll tmp;
        cin >> tmp;
        arr1[i] = make_pair(tmp, i);
    }
    // ll ctr = 1;
    for (ll i = 1; i <= n; i++) {
        arr2[i].first = i;
    }
    for (ll i = 1; i <= 5 * n; i++) {
        ll tmp;
        cin >> tmp;
        P2 ins;
        ins.first = tmp;
        P2* temp = lower_bound(arr2 + 1, arr2 + n + 1, ins, mycmp);
        temp->second.push(i);
    }
    ll ans = 0;
    for (ll i = 1; i <= 5 * n; i++) {
        P2 tmp;
        tmp.first = arr1[i].first;
        P2* temp = lower_bound(arr2 + 1, arr2 + n + 1, tmp, mycmp);
        if (i == 1) {
            ll t = temp->second.front();
            temp->second.pop();
            len[ans++] = make_pair(temp->first, t);
        }
        else if (temp->second.front() > len[ans - 1].second) {
            ll t = temp->second.front();
            temp->second.pop();
            len[ans++] = make_pair(temp->first, t);
        }
        else {
            ll t = temp->second.front();
            temp->second.pop();
            P rep = make_pair(temp->first, t);
            P* tt = upper_bound(len, len + ans, rep, mycmp2);
            *tt = rep;
        }
    }
    cout << ans;
    return 0;
}