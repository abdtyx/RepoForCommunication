#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 3;
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) {
            if (((1<<j)^i) == 0) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        cout << endl;
    }
}