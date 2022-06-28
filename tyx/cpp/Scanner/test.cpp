#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, int> mp;
    for (int i = 'a'; i < 'z'; i++) {
        mp[i] = 1;
    }
    mp.erase('c');
    string s = "abcdef";
    s.erase(0, 1);
    cout << s << endl;
    return 0;
}