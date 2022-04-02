#include <iostream>

using namespace std;

int main() {
    // x = a + b
    // y = a - b
    // a = (x + y) / 2
    // b = (x - y) / 2
    int x, y;
    cin >> x >> y;
    int a, b;
    a = (x + y) / 2;
    b = (x - y) / 2;
    // int bita = 0, bitb = 0;
    bool plusa = true, plusb = true;
    if (a < 0) plusa = false;
    if (b < 0) plusb = false;
    char str[10000];
    string aa(itoa(a, str, 10)), bb(itoa(b, str, 10));
    // cout << aa << endl << bb;
    string s, t;
    int sa = aa.size(), sb = bb.size();
    if (plusa) {
        for (int i = 0; i < sa; i++) {
            s.push_back(aa.back());
            aa.pop_back();
        }
    }
    else {
        // s[0] = '-';
        s.push_back('-');
        for (int i = 0; i < sa - 1; i++) {
            s.push_back(aa.back());
            aa.pop_back();
        }
    }
    if (plusb) {
        for (int i = 0; i < sb; i++) {
            t.push_back(bb.back());
            bb.pop_back();
        }
    }
    else {
        // t[0] = '-';
        t.push_back('-');
        for (int i = 0; i < sb - 1; i++) {
            t.push_back(bb.back());
            bb.pop_back();
        }
    }
    // cout << s << endl << t;
    int aaa = atoi(s.c_str()), bbb = atoi(t.c_str());
    int ansa, ansb;
    ansa = (aaa + bbb);
    ansb = (aaa - bbb);
    cout << ansa << ' ' << ansb;
    return 0;
}