#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    str.push_back(';');
    string ans;
    ans.clear();
    char tmp = '\0';
    int ctr = 1;
    for (int i = 0; i < str.size(); i++) {
        if (i == 0)
            tmp = str[i];
        else if (str[i] != tmp || i == str.size() - 1) {
            if (ctr == 1)
                ans.push_back(tmp);
            else {
                ans.push_back(tmp);
                ans.push_back(ctr + '0');
            }
            tmp = str[i];
            ctr = 1;
        }
        else if (str[i] == tmp) {
            ctr++;
        }
    }
    cout << ans;
    return 0;
}