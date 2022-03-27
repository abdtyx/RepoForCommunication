#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ll n;
    cin >> n;
    ll* arr = new ll[n];
    for (ll i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cout << arr[0] << endl << arr[n - 1];
    return 0;
}