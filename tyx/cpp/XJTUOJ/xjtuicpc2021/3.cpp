#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int _max1 = 0, _max2 = 0;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        if (ch == 'A') {
            cin >> ch;
            int tmp;
            cin >> tmp;
            _max1 = max(tmp, _max1);
        }
        if (ch == 'B') {
            cin >> ch;
            int tmp;
            cin >> tmp;
            _max2 = max(tmp, _max2);
        }
    }
    cout << _max1 + _max2;
    return 0;
}