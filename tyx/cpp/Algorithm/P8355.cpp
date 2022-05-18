#include <bits/stdc++.h>

using namespace std;
int a, b;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        if (ch == '(') a++;
        if (ch == ')') b++;
    }
    cout << 2 * min(a, b);
    return 0;
}