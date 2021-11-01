#include <bits/stdc++.h>
#define e (long double)0.04999999999999

using namespace std;

int main() {
    long double a, b, c;
    while (cin >> a >> b >> c) {
        if (a <= b) {
            cout << "0" << endl;
            continue;
        }
        a += e;
        b += e;
        if (a > 10) 
            a = 10;
        if (b > 10)
            b = 10;
        long double ans = ((long long)(c * a) - c * b) / (b - 1.0);
        long long answer = (long long)(ans + 0.99999999999999L);
        cout << answer << endl;
    }
    return 0;
}