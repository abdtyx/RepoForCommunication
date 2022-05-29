#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
bool pos[100005];

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == 'c' && s[i + 1] == 'j' && s[i + 2] == 'b') pos[i + 2] = true;
    }
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if (pos[i]) cout << ',';
    }
    return 0;
}