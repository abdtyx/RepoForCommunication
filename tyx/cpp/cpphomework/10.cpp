#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b);

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << " " << a * b / gcd(a, b);
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}