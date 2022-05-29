#include<iostream>
using namespace std;

int ans;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp >= x) ans++;
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if (tmp <= x) ans++;
    }
    cout << ans;
    return 0;
}