#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<char> st;
    string s;
    cin >> s;
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' | s[i] == '[') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            if ((!st.empty()) && st.top() == '(')
                st.pop();
            else 
                flag = false;
        }
        else if (s[i] == ']') {
            if ((!st.empty()) && st.top() == '[')
                st.pop();
            else 
                flag = false;
        }
    }
    if (flag)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}