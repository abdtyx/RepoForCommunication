#include <bits/stdc++.h>

using namespace std;

string s[1000005];
int f[10005];

int main() {
    string to_search;
    cin >> to_search;
    for (int i = 0; i < to_search.size(); i++) to_search[i] = tolower(to_search[i]);
    // vector<string> s;
    int ctr = 0;
    int pos = 0;
    char ch;
    scanf("%c", &ch);
    while (cin.peek() == ' ') {
        pos++;
        scanf("%c", &ch);
    }
    string tmp;
    while (cin >> tmp) {
        while(cin.peek() == ' ') {
            f[ctr + 1]++;
            scanf("%c", &ch);
        }
        for (int i = 0; i < tmp.size(); i++) tmp[i] = tolower(tmp[i]);
        s[ctr++] = tmp;
    }

    for (int i = 0; i < ctr; i++) {
        f[i] += pos;
        pos += s[i].size();
    }

    int ans = 0, fi = -1;
    for (int i = 0; i < ctr; i++) {
        if (s[i] == to_search) {
            if (ans == 0) fi = f[i];
            ans++;
        }
    }
    if (ans == 0) cout << -1;
    else cout << ans << ' ' << fi;
    return 0;
}