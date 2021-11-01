#include <bits/stdc++.h>

using namespace std;


// int reverse(int a);


int main() {
    string data;
    cin >> data;
    string s;
    s.clear();
    int upb = data.size();
    for (int i = 0; i < upb; i++) {
        char tmp = data.back();
        data.pop_back();
        s.push_back(tmp);
    }
    int ans = atoi(s.c_str());
    cout << ans;
    return 0;
}

