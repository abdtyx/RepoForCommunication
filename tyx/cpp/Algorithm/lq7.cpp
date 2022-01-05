#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int yanghui[50][50];
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            yanghui[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 1) {
                yanghui[1][1] = 1;
                continue;
            }
            if (j == i || j == 1)
                yanghui[i][j] = 1;
            else {
                yanghui[i][j] = yanghui[i - 1][j - 1] + yanghui[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1)
                cout << yanghui[i][j];
            else 
                cout << ' ' << yanghui[i][j];
        }
        cout << endl;
    }
    return 0;
}