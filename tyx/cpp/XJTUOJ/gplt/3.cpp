#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int ans1 = 0, ans2 = 0;
    while (getline(cin, s)) {
        if (s == "-1") break;
        if (s.find("USSR") != -1) ans1++;
        else if (s.find("United States") != -1) ans2++;
        else {
            ans1++;
            ans2++;
        }
    }
    cout << "United States: " << ans2 - 1 << endl << "USSR: " << ans1 - 1;
    return 0;
}