#include <bits/stdc++.h>

using namespace std;

int main() {
    map<char, char> mp = {{'d', 'a'}, {'w', 'b'}, {'k', 'c'},
{';', 'd'}, {'i', 'e'}, {'h', 'f'},
{'m', 'g'}, {'o', 'h'}, {'a', 'i'},
{'z', 'j'}, {'b', 'k'}, {'n', 'l'},
{'y', 'm'}, {'c', ';'}, {'e', 'w'},
{'f', 'o'}, {'g', 'y'}, {'j', 'z'},
{'l', 'n'}, {' ', ' '}, {'/', '/'}};
// pair<char, char> pr = {'a', 'b'};
string s, ans;
ans.clear();
getline(cin, s);
for (int i = 0; i < s.size(); i++) {
    if (mp.find(s[i]) != mp.end())
        ans.push_back(mp[s[i]]);
    else
        ans.push_back(s[i]);
}
cout << ans;
}