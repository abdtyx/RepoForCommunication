#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 5;
    for (int tot = 0, mask = 1 << n; tot < mask; tot++) {
        for (int i = n - 1; i >= 0; i--) {
            if ((1 << i) & tot)
                cout << '1';
            else 
                cout << '0';
        }
        cout << endl;
    }
    return 0;
}