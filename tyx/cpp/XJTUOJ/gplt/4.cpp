#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, bool> P;

int main() {
    int n;
    cin >> n;
    P p[40];
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        p[i].first = tmp;
        p[i].second = false;
    }
    ll tmp = 0;
    while (cin >> tmp) {
        if (tmp == -1) break;
        cout << p[tmp - 1].first;
        if (p[tmp - 1].second) cout << '*';
        cout << endl;
        p[tmp - 1].second = true;
    }
    return 0;
}