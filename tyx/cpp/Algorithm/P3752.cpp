#include <bits/stdc++.h>

using namespace std;
map<string, vector<string> > mp;
vector<string> se;

int main() {
    int n;
    cin.sync_with_stdio(false);
    // cin >> n;
    scanf("%d", &n);
    char tmp[300];
    char abd;
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        string fr(tmp);
        // cin >> fr;
        se.clear();
        // cin >> noskipws;
        scanf("%c", &abd);
        // if (cin.peek() == ' ') {
        //     // scanf("%c", &abd);
        //     cin >> abd;
        // }
        while (abd != '\n') {
            // cin >> s;
            if (abd != ' ') {
                tmp[0] = abd;
                scanf("%s", tmp + 1);
            }
            else scanf("%s", tmp);
            string s(tmp);
            for (int l = 0; l < s.size(); l++) {s[l] = tolower(s[l]);}
            se.push_back(s);
            // if (cin.peek() == ' ') {
            //     // scanf("%c", &abd);
            //     cin >> abd;
            // }
            scanf("%c", &abd);
            while (abd == ' ') {
                scanf("%c", &abd);
            }
        }
        mp.insert(make_pair(fr, se));
        // cin >> skipws;
    }
    // string in; 
    // getline(cin, in);
    // getline(cin, in);
    while (scanf("%[^\n]", tmp) != EOF) {
        string in(tmp);
        for (int l = 0; l < in.size(); l++) {in[l] = tolower(in[l]);}
        in.push_back('\n');
        for (auto i : mp) {
            bool flag2 = false;
            for (auto j : i.second) {
                int k = in.find(j);
                bool flag = false;
                if (k != -1) {
                    if (in[k + j.size()] == '.' || in[k + j.size()] == ',' || in[k + j.size()] == '?' || in[k + j.size()] == '!' || in[k + j.size()] == ';' || in[k + j.size()] == '(' || in[k + j.size()] == ')' || in[k + j.size()] == ' ' || in[k + j.size()] == '\n') {
                        cout << i.first << endl;
                        flag = true;
                        flag2 = true;
                    }
                }
                if (flag) {break;}
            }
            if (flag2) {break;}
        }
        if (scanf("%c", &abd) == EOF) break;
    }
    return 0;
}