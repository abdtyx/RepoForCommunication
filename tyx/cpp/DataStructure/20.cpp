#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    stack<char> st;
    for (auto i : s) {
        if (i == '(') {
            st.push(i);
        }
        if (i == ')') {
            if (st.size() == 0) {cout << "括号不匹配！"; return 0;}
            else {st.pop();}
        }
    }
    if (st.size() == 0) {cout << "括号匹配！";}
    else cout << "括号不匹配！";
    return 0;
}