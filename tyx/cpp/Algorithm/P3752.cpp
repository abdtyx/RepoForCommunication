#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, vector<string> > mp;
    for (int i = 0; i < n; i++) {
        string fr, s;
        cin >> fr;
        vector<string> se;
        char abd;
        if (cin.peek() == ' ') {
            scanf("%c", &abd);
        }
        while (cin.peek() != '\n') {
            cin >> s;
            for (int l = 0; l < s.size(); l++) {s[l] = tolower(s[l]);}
            se.push_back(s);
            if (cin.peek() == ' ') {
                scanf("%c", &abd);
            }
        }
        mp.insert(make_pair(fr, se));
    }
    string in;
    getline(cin, in);
    getline(cin, in);
    while (getline(cin, in)) {
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
    }
    return 0;
}