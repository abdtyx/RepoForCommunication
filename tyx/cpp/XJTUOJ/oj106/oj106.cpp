#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << ' ' << lcm(a, b);
}