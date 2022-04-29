#include <iostream>
#include <queue>

using namespace std;

typedef struct _S {
    string s;
    // bool operator<(const struct _S& b) {
    //     return s.size() < b.s.size();
    // }
} S;

bool operator<(S a, S b) {
    return a.s.size() < b.s.size();
}

int main() {
    priority_queue<S> q;
    // string s;
    char str[1000];
    while (scanf("%s", str) != EOF) {
        // cout << str << endl;
        string s(str);
        S tmp;
        tmp.s = s;
        q.push(tmp);
        if (cin.peek() == '\n') {break;}
    }
    cout << q.top().s;
    return 0;
}