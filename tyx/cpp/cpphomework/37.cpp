#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;


LL fib(LL n) {
    return n == 1 || n == 2 ? 1 :fib(n - 1) + fib(n - 2);
}



int main() {
    LL n;
    cin >> n;
    cout << fib(n);
}