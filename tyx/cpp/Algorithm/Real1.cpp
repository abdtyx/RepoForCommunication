#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")

using namespace std;
int arr[100005];
inline bool mycmp(int a, int b) {return a > b;}
inline bool mycmp2(int a, int b) {return a < b;}

int main() {
    int n, m;
    cin >> n >> m;
    for (register int i = 1; i <= n; ++i) {arr[i] = i;}
    for (register int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == 0) sort(arr + 1, arr + b + 1, mycmp);
        if (a == 1) sort(arr + b, arr + n + 1, mycmp2);
    }
    for (register int i = 1; i <= n; ++i) {cout << arr[i] << ' ';}
    return 0;
}