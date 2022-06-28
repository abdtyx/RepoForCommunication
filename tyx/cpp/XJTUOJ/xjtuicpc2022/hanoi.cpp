#include <bits/stdc++.h>

using namespace std;

int ans;

void hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        ans++;
        cout << a << "->" << c << endl;
        return;
    }
    n--;
    hanoi(n, a, c, b);
    ans++;
    cout << a << "->" << c << endl;
    hanoi(n, b, a, c);
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << ans << endl;;
    return 0;
}