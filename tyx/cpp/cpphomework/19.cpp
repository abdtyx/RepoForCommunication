#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; 
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int ctr = 0;
        for (int j = 1; j <= k; j++) {
            if (i % j == 0)
                ctr++;
        }
        if (ctr & 1) {
            if (cnt == 0) {
                cout << i;
                cnt++;
            }
            else
                cout << " " << i;
        }
    }
}