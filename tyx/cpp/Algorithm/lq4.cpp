#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int main() {
    string hex;
    cin >> hex;
    LL dec = 0;
    LL n = hex.size() - 1;
    for (int i = n; i >= 0; i--) {
        if (hex[n - i] >= '0' && hex[n - i] <= '9')
            dec += (LL)pow(16, i) * (hex[n - i] - '0');
        else if (hex[n - i] >= 'A' && hex[n - i] <= 'F')
            dec += (LL)pow(16, i) * (hex[n - i] - 'A' + 10);
    }
    cout << dec;
    return 0;
}