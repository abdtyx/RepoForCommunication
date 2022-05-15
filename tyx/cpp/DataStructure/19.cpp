#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string s;
    // cin >> s;
    getline(cin, s);
    cout << s << endl << s.size() << endl;
    char d;
    cin >> d;
    while (s.find(d) != -1) {
        int x = s.find(d);
        s.erase(x, 1);
    }
    cout << s << endl << s.size();
    return 0;
}