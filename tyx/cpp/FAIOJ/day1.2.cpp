#include <bits/stdc++.h>

using namespace std;
int n, k;
int arr[30];
int t[30];
int _max;
// int ans;

typedef struct _Container {
    int v[30];
    int num;
    int v_max;
} Container;

void dfs(int i, Container c);

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int pos;
        int _min = 600;
        for (int j = 0; j < k; j++) {
            if (t[j] < _min) {
                _min = t[j];
                pos = j;
            }
        }
        t[pos] += arr[i];
    }
    for (int i = 0; i < k; i++) {
        _max = max(_max, t[i]);
    }
    // cout << _max;
    Container c;
    c.num = k;
    // ans = 900000;
    c.v_max = 0;
    memset(c.v, 0, sizeof(c));
    dfs(n, c);
    cout << _max;
    return 0;
}

void dfs(int i, Container c) {
    // for (int j = 0; j < c.num; j++) {
    //     if (c.v[j] >= _max) return;
    // }
    if (c.v_max >= _max) return;
    if (i == 1) {
        for (int j = 0; j < k; j++) {
            // c.v[j] += 
            Container d = c;
            d.v[j] += arr[n - i];
            d.v_max = max(d.v_max, d.v[j]);
            // int __max = 0;
            // for (int l = 0; l < k; l++) {
                // if (d.v[l] > __max) __max = d.v[l];
            // }
            if (d.v_max < _max) _max = d.v_max;
            if (d.v[j] - arr[n - i] == 0) break;
        }
        return;
    }
    for (int j = 0; j < k; j++) {
        Container d = c;
        d.v[j] += arr[n - i];
        d.v_max = max(d.v[j], d.v_max);
        dfs(i - 1, d);
        if (d.v[j] - arr[n - i] == 0) break;
    }
    return;
}