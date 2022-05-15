#include <bits/stdc++.h>

using namespace std;

int main() {
    double x, y, z;
    cin >> x >> y >> z;
    int i = 1;
    for (i = 1; i <= 100000000; i++) {
        if ((double)i / z >= y / x) break;
    }
    cout << i - 1;
    return 0;
}