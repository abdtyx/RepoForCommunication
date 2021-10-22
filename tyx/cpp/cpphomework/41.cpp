#include <bits/stdc++.h>

using namespace std;

int mut2(int n);
int mut5(int n);


int main() {
    int ans = 0;
    int n;
    cin >> n;
    int num2 = 0;
    int num5 = 0;
    for (int i = 1; i <= n; i++) {
        num2 += mut2(i);
        num5 += mut5(i);
    }
    cout << min(num2, num5);
}


int mut2(int n) {
    int ans = 0;
    while (!((n >> ans) & 1))
        ans++;
    return ans;
}

int mut5(int n) {
    int ans = 0;
    while (n % 5 == 0) {
        ans++;
        n /= 5;
    }
    return ans;
}
