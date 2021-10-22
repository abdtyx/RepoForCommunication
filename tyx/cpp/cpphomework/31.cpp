#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0; 
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        q.push(tmp);
    }
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        int a = q.front();
        ans += a * tmp;
        q.pop();
    }
    cout << ans;
}