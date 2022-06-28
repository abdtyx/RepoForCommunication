#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, a = 0, b = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp & 1) a++;
            else b++;
        }
        cout << min(a, b) << endl;
    }
    return 0;
}