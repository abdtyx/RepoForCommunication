#include <bits/stdc++.h>

#define Ins(a, b, c) s[a].ToWhere[b] = c
#define X 0x34

using namespace std;

typedef pair<char, int> P; // towhere edgevalue

typedef struct _status {
    bool IsAccept;
    map<char, int> ToWhere;
    string status;
} Status;

Status s[1000];

void encode();
void decode(string str);
void addall(int x);
void is(int x, bool b, string st);
void dfs(int stat, string strr);

int main() {
    // ifstream in;
    // in.open("read.dat", ios::out | ios::in );
    encode();
    int SwitchMode;
    cin >> SwitchMode;
    if (SwitchMode == 1) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            decode(str);
        }
    }
    if (SwitchMode == 2) {
        string str;
        getline(cin, str);
        getline(cin, str);
        int cur = 1;
        queue<char> q;
        for (int i = 0; i < str.size(); i++) {
            q.push(str[i]);
        }
        while (!q.empty()) {
            char tmp = q.front();
            if (tmp == ' ') {
                q.pop();
                if (s[cur].IsAccept) cout << s[cur].status << endl;
                else cout << "False word." << endl;
                cur = 1;
                continue;
            }
            if (s[cur].ToWhere.find(tmp) != s[cur].ToWhere.end()) {
                cur = s[cur].ToWhere[tmp];
                q.pop();
                if (q.empty())
                    if (s[cur].IsAccept) cout << s[cur].status << endl;
                    else cout << "False word." << endl;
                continue;
            }
            else if (s[cur].IsAccept) cout << s[cur].status << endl;
            else cout << "False word." << endl;
            cur = 1;
        }
    }
    return 0;
}

void encode() {
    
    // 0x01
    s[0x01].IsAccept = false;
    s[0x01].status = "NONE";
    Ins(0x01, 'i', 0x02);
    Ins(0x01, 'e', 0x04);
    Ins(0x01, 'w', 0x08);
    Ins(0x01, 'r', 0x0d);
    Ins(0x01, 'o', 0x17);
    Ins(0x01, '.', 0x1e);
    Ins(0x01, '+', 0x31);
    Ins(0x01, '-', 0x1f);
    for (int i = 0; i < 10; i++) {
        Ins(0x01, '0' + i, 0x1d);
    }
    Ins(0x01, '\\', 0x21);
    Ins(0x01, '*', 0x30);
    Ins(0x01, '!', 0x2d);
    Ins(0x01, '<', 0x2c);
    Ins(0x01, '=', 0x2b);
    Ins(0x01, ']', 0x2A);
    Ins(0x01, '[', 0x29);
    for (int i = 'a'; i <= 'z'; i++) {
        if (i == 'i' || i == 'e' || i == 'w' || i == 'r' || i == 'o') continue;
        Ins(0x01, i, X);
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        Ins(0x01, i, X);
    }
    Ins(0x01, '_', X);

    for (int i = 0x02; i <= 0x1c; i++) addall(i);

    // 0x02
    s[0x02].IsAccept = true;
    s[0x02].status = "ID";
    Ins(0x02, 'f', 0x03);
    Ins(0x02, 'n', 0x13);

    // 0x03
    s[0x03].IsAccept = true;
    s[0x03].status = "IF";

    // 0x04
    s[0x04].IsAccept = true;
    s[0x04].status = "ID";
    Ins(0x04, 'l', 0x05);

    // 0x05
    s[0x05].IsAccept = true;
    s[0x05].status = "ID";
    Ins(0x05, 's', 0x06);

    // 0x06
    s[0x06].IsAccept = true;
    s[0x06].status = "ID";
    Ins(0x06, 'e', 0x07);

    // 0x07
    s[0x07].IsAccept = true;
    s[0x07].status = "ELSE";

    // 0x08
    is(0x08, true, "ID");
    Ins(0x08, 'h', 0x09);

    // 0x09
    is(0x09, true, "ID");
    Ins(0x09, 'i', 0x0a);

    // 0x0a
    is(0x0a, true, "ID");
    Ins(0x0a, 'l', 0x0b);

    // 0x0b
    is(0x0b, true, "ID");
    Ins(0x0b, 'e', 0x0c);
    
    // 0x0c
    is(0x0c, true, "WHILE");

    // 0x0d
    is(0x0d, true, "ID");
    Ins(0x0d, 'e', 0x0e);

    // 0x0e
    is(0x0e, true, "ID");
    Ins(0x0e, 't', 0x0f);

    // 0x0f
    is(0x0f, true, "ID");
    Ins(0x0f, 'u', 0x10);

    // 0x10
    is(0x10, true, "ID");
    Ins(0x10, 'r', 0x11);

    // 0x11
    is(0x11, true, "ID");
    Ins(0x11, 'n', 0x12);

    // 0x12
    is(0x12, true, "RETURN");

    // 0x13
    is(0x13, true, "ID");
    Ins(0x13, 'p', 0x14);

    // 0x14
    is(0x14, true, "ID");
    Ins(0x14, 'u', 0x15);

    // 0x15
    is(0x15, true, "ID");
    Ins(0x15, 't', 0x16);

    // 0x16
    is(0x16, true, "INPUT");

    // 0x17
    is(0x17, true, "ID");
    Ins(0x17, 'u', 0x18);

    // 0x18
    is(0x18, true, "ID");
    Ins(0x18, 't', 0x19);

    // 0x19
    is(0x19, true, "ID");
    Ins(0x19, 'p', 0x1a);

    // 0x1a
    is(0x1a, true, "ID");
    Ins(0x1a, 'u', 0x1b);

    // 0x1b
    is(0x1b, true, "ID");
    Ins(0x1b, 't', 0x1c);

    // 0x1c
    is(0x1c, true, "OUTPUT");

    // 0x1d
    is(0x1d, true, "NUM");
    for (int i = '0'; i <= '9'; i++) Ins(0x1d, i, 0x1d);
    Ins(0x1d, '.', 0x20);

    // 0x1e
    is(0x1e, false, "NONE");
    for (int i = '0'; i <= '9'; i++) Ins(0x1e, i, 0x20);

    // 0x1f
    is(0x1f, false, "NONE");
    for (int i = '0'; i <= '9'; i++) Ins(0x1f, i, 0x1d);
    Ins(0x1f, '.', 0x1e);

    // 0x20
    is(0x20, true, "FLOAT");
    for (int i = '0'; i <= '9'; i++) Ins(0x20, i, 0x20);

    // 0x21
    is(0x21, false, "NONE");
    Ins(0x21, '=', 0x22);
    Ins(0x21, '(', 0x23);
    Ins(0x21, ')', 0x24);
    Ins(0x21, '{', 0x25);
    Ins(0x21, '}', 0x26);
    Ins(0x21, ';', 0x27);
    Ins(0x21, ',', 0x28);

    // 0x22
    is(0x22, true, "ASG");

    // 0x23
    is(0x23, true, "LPAR");

    // 0x24
    is(0x24, true, "RPAR");

    // 0x25
    is(0x25, true, "LBR");

    // 0x26
    is(0x26, true, "RBR");

    // 0x27
    is(0x27, true, "SEMI");

    // 0x28
    is(0x28, true, "CMA");

    // 0x29
    is(0x29, true, "LBK");

    // 0x2a
    is(0x2a, true, "RBK");

    // 0x2b
    is(0x2b, false, "NONE");
    Ins(0x2b, '=', 0x2e);

    // 0x2c
    is(0x2c, true, "ROP");

    // 0x2d
    is(0x2d, false, "NONE");
    Ins(0x2d, '=', 0x2f);

    // 0x2e
    is(0x2e, true, "ROP");

    // 0x2f
    is(0x2f, true, "ROP");

    // 0x30
    is(0x30, true, "MUL");

    // 0x31
    is(0x31, true, "ADD");
    Ins(0x31, '\\', 0x32);

    // 0x32
    is(0x32, false, "NONE");
    Ins(0x32, '=', 0x33);

    // 0x33
    is(0x33, true, "AASG");

    // 0x34
    is(0x34, true, "ID");
    addall(0x34);
}

void addall(int x) {
    for (int i = 0; i < 26; i++) {
        Ins(x, 'a' + i, X);
        Ins(x, 'A' + i, X);
        if (i < 10) Ins(x, '0' + i, X);
    }
    Ins(x, '_', X);
}

void is(int x, bool b, string st) {
    s[x].IsAccept = b;
    s[x].status = st;
}

void decode(string str) {
    dfs(0x01, str);
}

void dfs(int stat, string strr) {
    if (strr == "") {
        if (s[stat].IsAccept) cout << s[stat].status << endl;
        else cout << "False input." << endl;
        return;
    }
    if (s[stat].ToWhere.find(strr[0]) == s[stat].ToWhere.end()) {
        cout << "False input." << endl;
        return;
    }
    int nxt = s[stat].ToWhere[strr[0]];
    strr.erase(0, 1);
    dfs(nxt, strr);
    return;
}