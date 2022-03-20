#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    string tmp = s;
    string ans;
    while (tmp.size()) {
        char c = tmp.back();
        ans.push_back(c);
        tmp.pop_back();
    }
    if (ans == s) cout << 1;
    else cout << 0;
    return 0;
}