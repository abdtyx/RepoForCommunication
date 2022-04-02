#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int re = s.size() % 3;
    for (int i = 0; i < re; i++) {
        cout << s[i];
    }
    if (re != 0 && s.size() > 3) cout << ',';
    for (int i = re; i < s.size(); i++) {
        cout << s[i];
        if ((i + 1) % 3 == re && i != s.size() - 1) cout << ',';
    }
    return 0;
}