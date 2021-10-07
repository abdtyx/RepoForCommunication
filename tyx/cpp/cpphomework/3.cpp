#include <bits/stdc++.h>
using namespace std;

int main() {
    double degree, minute, second;
    cin >> degree >> minute >> second;
    double ans = degree + minute / 60.0 + second / 3600.0;
    cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = " << ans << " degrees";
}