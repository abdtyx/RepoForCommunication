#include <bits/stdc++.h>

using namespace std;

// bool mycmp(int a, int b) {
//     if ((a + b) & 1) return false;
//     else {
//         return a = b;
//     }
// }

typedef pair<int, int> P; // 数字 次序

bool mycmp(P a, P b) {
    return a.first < b.first;
}

// void bubble(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (mycmp(arr[i], arr[j])) {
//                 int tmp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = tmp;
//             }
//         }
//     }
// }

int main() {
    int n;
    cin >> n;
    P* odd = new P[n];
    P* even = new P[n];
    bool* ode = new bool[n]; // 0 even  1 odd
    memset(ode, false, n);
    int ctr_odd = 0, ctr_even = 0, b = 0;
    // for (int i = 0; i < n; i++) cin >> arr[i];
    // sort(arr, arr + n, mycmp);
    // bubble(arr, n);
    // for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ode[b++] = tmp & 1;
        if (tmp & 1) odd[ctr_odd++] = make_pair(tmp, i);
        else even[ctr_even++] = make_pair(tmp, i);
    }
    sort(odd, odd + ctr_odd);
    sort(even, even + ctr_even);
    ctr_even = ctr_odd = 0;
    for (int i = 0; i < n; i++) {
        if (ode[i]) cout << odd[ctr_odd++].first << ' ';
        else cout << even[ctr_even++].first << ' ';
    }
    return 0;
}