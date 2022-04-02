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
        pr[i].second = i;
    }
    int q;
    cin >> q;
    sort(pr, pr + n);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cout << lower_bound(pr, pr + n, tmp, mycmp)->second;
    }
    return 0;
}