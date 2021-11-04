#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<char> s;
    bool flag = true;
    char ch;
    while (cin >> ch) {
        if (ch == '@')
            break;
        if (ch == '(')
            s.push(ch);
        if (ch == ')') {
            if (!s.empty()) {
                char tmp = s.top();
                s.pop();
                if (tmp != '(')
                    flag = false;
            }
            else 
                flag = false;
        }
    }
    if (flag && s.empty())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}