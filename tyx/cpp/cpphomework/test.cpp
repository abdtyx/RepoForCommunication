#include <bits/stdc++.h>

using namespace std;

#define s 14561564654516321546103515

int main() {
    int ans = 1;
    for (int i = 0; i < 1e7; i++) {
        ans = (ans * 2) % 1000000;
        if (ans == 69376) {
            cout << i;
            break;
        }
    }
    return 0;
}