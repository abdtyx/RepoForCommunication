#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    if (x > 0)
        cout << 3 * x + 1;
    if (x == 0)
        cout << "0";
    if (x < 0)
        cout << x * x - 1;
}