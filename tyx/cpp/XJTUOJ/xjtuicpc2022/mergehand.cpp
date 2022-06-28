#include <bits/stdc++.h>

using namespace std;

int t[100005], a[100005];

void merge(int ll, int rr) {
    if (rr - ll <= 1) return;
    int mid = ll + ((rr - ll) >> 1);
    merge(ll, mid);
    merge(mid, rr);
    int p = ll, q = mid, s = ll;
    while (s < rr) {
        if (p >= mid || (q < rr && a[p] > a[q])) t[s++] = a[q++];
        else t[s++] = a[p++];
    }
    for (int i = ll; i < rr; i++) a[i] = t[i];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge(0, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}