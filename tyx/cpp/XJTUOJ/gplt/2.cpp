#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl << a << " - " << b << " = " << a - b << endl << a << " * " << b << " = " << a * b << endl << a << " / " << b << " = " << a / b;
    if ((int)a % (int)b) {
        cout << "......" << (int)a % (int)b;
    }
    return 0;
}