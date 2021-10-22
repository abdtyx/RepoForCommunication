#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}



int main() {
    int n;
    cin >> n;
    if (isPrime(n) && n > 1) {
        cout << n << " 0";
        return 0;
    }
    int left = n - 1, right = n + 1;
    while (1) {
        if (isPrime(left) && left > 1) {
            cout << left << " " << n - left;
            break;
        }
        else
            left--;
        if (isPrime(right) && right > 1) {
            cout << right << " " << right - n;
            break;
        }
        else
            right++;
    }
}