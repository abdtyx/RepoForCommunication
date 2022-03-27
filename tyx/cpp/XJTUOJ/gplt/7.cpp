#include <bits/stdc++.h>

using namespace std;

#define MAX_INT 2147483647

int main() {
    int n;
    cin >> n;
    int _min = MAX_INT;
    int arr[10005];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tmp;
            if (j == i) tmp = arr[i];
            if (j == i + 1) _min = min(arr[i], arr[j]);
            else _min = min(_min, arr[j]);
            tmp = (j - i + 1) * _min;
            if (tmp > ans) ans = tmp;
        }
    }
    cout << ans;
    return 0;
}