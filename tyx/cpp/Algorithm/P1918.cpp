#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P; // 数量，位置

bool mycmp(P a, P b) {
    return a.first < b.first;
}

int main() {
    int n;
    P pr[100005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pr[i].first;
        pr[i].second = i + 1;
    }
    int q;
    cin >> q;
    sort(pr, pr + n);
    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        P* o = lower_bound(pr, pr + n, make_pair(tmp, 0), mycmp);
        P* oo = upper_bound(pr, pr + n, make_pair(tmp, 0), mycmp);
        if (o == pr + n || o == oo) {
            cout << 0 << endl;
        }
        else {
            cout << o->second << endl;
        }
    }
    return 0;
}