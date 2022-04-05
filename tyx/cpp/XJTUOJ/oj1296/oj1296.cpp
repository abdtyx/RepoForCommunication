#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll a[100005], sum1[100005], sum2[100005];
ll n, m;

ll lowbit(ll x) {return x & (-x);}

void updata(ll i, ll k) {
    ll x = i;
    while (i <= n) {
        sum1[i] += k;
        sum2[i] += k * (x - 1);
        i += lowbit(i);
    }
}

ll getsum(ll i) {
    ll ans = 0, x = i;
    while (i > 0) {
        ans += x * sum1[i] - sum2[i];
        i -= lowbit(i);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        updata(i, a[i] - a[i - 1]);
    }
    updata(x, k);
    updata(y + 1, k);
    ll sum = getsum(y) - getsum(x - 1);
}