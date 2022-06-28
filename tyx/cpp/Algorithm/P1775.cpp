#include <bits/stdc++.h>

/**
 * g++ -E P1775.cpp -o main.i
 * g++ -S main.i -o main.s
 * g++ -c main.s -o main.o
 * g++ main.o -o main.exe
 */

using namespace std;

typedef long long int ll;

ll dp[500][500];
ll a[500];

int main() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    return 0;
}