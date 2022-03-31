#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int arr[1000005];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += max(arr[i], arr[i - 1]);
    }
    cout << ans;
}