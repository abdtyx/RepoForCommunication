#include <bits/stdc++.h>

using namespace std;

int main() {
    int flag = 1;
    int ctl = 0;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ctl++;
            cout << setw(5) << i;
        }
        flag = 1;
        if (ctl == 5) {
            cout << endl;
            ctl = 0;
        }
    }
}