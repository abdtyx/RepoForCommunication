#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    string ans = max(s1, max(s2, s3));
    cout << ans;
    return 0;
}