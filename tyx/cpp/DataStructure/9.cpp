#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    // int kinary[100], ctr = 0;
    stack<int> s, ss;
    int ctr = 0;
    while (n / (int)pow(b, ++ctr));
    // cout << ctr;
    while (ctr-- > 0) {
        int which = n / (int)pow(b, ctr);
        n %= (int)pow(b, ctr);
        s.push(which);
    }
    stack<int> tmp = s;
    while (tmp.size()) {
        ss.push(tmp.top());
        tmp.pop();
    }
    if (s == ss) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    while (ss.size()) {
        cout << ss.top();
        ss.pop();
        if (ss.size()) cout << ' ';
    }
}