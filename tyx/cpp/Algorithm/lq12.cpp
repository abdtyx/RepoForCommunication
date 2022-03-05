#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1005];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s == arr[i]) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}