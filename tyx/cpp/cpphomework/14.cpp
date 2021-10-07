#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL Factorial(LL n);

int main() {
    LL x;
    cin >> x;
    cout << Factorial(x);
}

LL Factorial(LL n) {
    return n ? n * Factorial(n - 1) : 1;
}