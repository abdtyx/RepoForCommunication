#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[20005];
    int ctr = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ctr++;
    }
    for (int i = 0; i < m; i++) {
        arr[ctr + i] = 0;
        for (int j = i; j < ctr + i; j++) {
            arr[ctr + i] += arr[j];
            if (arr[ctr + i] >= 10) arr[ctr + i] -= 10;
        }
    }
    for (int i = 0; i < n + m; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}