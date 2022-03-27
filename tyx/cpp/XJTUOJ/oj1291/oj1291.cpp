#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P; // 数， 转移序号

bool mycmp(P a, P b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    P* arr = new P[500005];
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = make_pair(tmp, i);
    }
    P* len = new P[500005];
    len[0] = arr[0];
    int ans = 0;    // 输出ans + 1
    int* where = new int[500005];
    // int where[10];
    where[0] = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].first >= len[ans].first) {
            len[++ans] = arr[i];
            where[i] = len[ans - 1].second;
        }
        else {
            P* pos = upper_bound(len, len + ans + 1, arr[i], mycmp);
            if (pos == len) {
                *pos = arr[i];
                where[i] = i;
            }
            else {
                *pos = arr[i];
                where[i] = (pos - 1)->second;
            }
        }
    }
    cout << ans + 1 << endl;
    // back
    stack<int> s;
    int tmp = len[ans].second;
    s.push(tmp);
    while (tmp != where[tmp]) {
        tmp = where[tmp];
        s.push(tmp);
    }
    while (s.size()) {
        tmp = s.top();
        s.pop();
        cout << tmp + 1<< ' ';
    }
    return 0;
}