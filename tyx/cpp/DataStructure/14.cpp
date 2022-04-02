#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[10005];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int l = 0, r = 0;
    int _max = 0;
    int ans = 0;
    int ctr = 0;
    int ansl = 10005, ansr = 10005;
    bool flag = false;
    while (ctr != n) {
        ans += arr[ctr];
        if (ans == 0 && arr[ctr] == 0 && ctr < ansl) {
            flag = true;
            ansl = ctr;
            ansr = ctr + 1;
        }
        if (ans < 0) {
            ans = 0;
            l = ctr + 1;
            r = l;
        }
        if (ans > 0) {
            r++;
        }
        if (ans > _max) {
            ansl = l;
            ansr = r;
            _max = ans;
        }
        ctr++;
    }
    if (_max != 0 || flag) cout << _max << ' ' << ansl << ' ' << ansr - 1;
    else cout << 0 << ' ' << arr[0] << ' ' << arr[n - 1];
    return 0;
}