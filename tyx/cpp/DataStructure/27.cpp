#include <iostream>

using namespace std;

int a[1000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int to_search;
    cin >> to_search;
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= to_search) r = mid;
        else l = mid + 1;
    }
    if (a[l] == to_search) cout << l;
    else cout << -1;
    return 0;
}