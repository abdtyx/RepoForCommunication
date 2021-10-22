#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double delta = pow(b, 2.0) - 4.0 * a * c;
    double x1, x2;
    if (delta < 0) {
        cout << "no root";
    }
    else {
        if (a == 0 && b != 0) {
            cout.precision(6);
            cout << -c / b;
        }
        else if (a == 0 && b == 0) {
            cout << "no root";
        }
        else {
            x1 = (-b + sqrt(delta)) / (2.0 * a);
            x2 = (-b - sqrt(delta)) / (2.0 * a);
            if (x1 != x2) {
                cout.precision(6);
                cout << min(x2, x1) << " " << max(x1, x2);
            }
            else { 
                cout.precision(6);
                cout << x1;
            }
        }
    }
}