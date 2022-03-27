#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool prime[2000005];
    int sieve[2000], ctr = 2;
    sieve[0] = 2;
    sieve[1] = 3;
    memset(prime, true, 2000005);
    for (int i = 4; i < 2000; i++) {
        bool flag = false;
        for (int j = 2; j <= (int)sqrt(i); j++) {
            if (i % j == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            sieve[ctr++] = i;
        }
    }
    prime[0] = false;
    prime[1] = false;
    for (int i = 0; i < ctr; i++) {
        for (int j = 2; j * sieve[i] <= 2000000; j++) {
            prime[j * sieve[i]] = false;
        }
    }
    // cout << 2;
    if (n == 1) {cout << 2; return 0;}
    ctr = 0;
    for (int i = 3; i < 2000000; i++) {
        if (prime[i]) ctr++;
        if (ctr == n - 1) {cout << i; break;}
    }
    return 0;
}