#include <bits/stdc++.h>

using namespace std;

int a[100005];

void shell(int a[], int n) {
    int gap, i, j, tmp;
    for (gap = n >> 1; gap > 0; gap >>= 1) {
        for (i = gap; i < n; i++) {
            tmp = a[i];
            for (j = i - gap; j >= 0 && a[j] > tmp; j -= gap) {
                a[j + gap] = a[j];
            }
            a[j + gap] = tmp;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    shell(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}