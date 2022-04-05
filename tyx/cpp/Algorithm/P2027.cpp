#include <bits/stdc++.h>

using namespace std;
char mem[30005];
int ptr = 0;
queue<char> cache;
// bool vis[30005];
int execute(char c, int pos);
string ascii = "<>+-.,[]$";
string input;

int main() {
    // memset(vis, true, sizeof(vis));
    // getline(cin, input);
    char ch;
    while ((ch = getchar()) != EOF) {input.push_back(ch);}
    int fi = input.find('$');
    fi+=2;
    int ls = input.find_last_of('$');
    ls--;
    for (int i = fi; i < ls; i++) {
        cache.push(input[i]);
    }
    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        if (ascii.find(c) == -1) continue;
        if (c == '$') break;
        i = execute(c, i);
    }
    // cout << cache;
    return 0;
}

int execute(char c, int pos) {
    bool first_time = true;
    if (c == '<') ptr--;
    if (c == '>') ptr++;
    if (c == '+') mem[ptr]++;
    if (c == '-') mem[ptr]--;
    if (c == '.') cout << mem[ptr];
    if (c == ',') {
        if (cache.empty()) {
            mem[ptr] = -1;
        }
        else {
            mem[ptr] = cache.front();
            cache.pop();
        }
    }
    if (c == '[') {
        int ctr;
        if (first_time && mem[ptr] == 0) {
            first_time = false;
            ctr = pos;
            stack<char> s;
            s.push(input[ctr++]);
            while (!s.empty()) {
                if (input[ctr] != ']') {
                    s.push(input[ctr++]);
                }
                else {
                    char ccc = s.top();
                    s.pop();
                    while (ccc != '[') {
                        ccc = s.top();
                        s.pop();
                    }
                }
            }
        }
        while (mem[ptr] != 0) {
            ctr = pos;
            for (; ; ctr++) {
                if (ctr == ']') break;
                if (ascii.find(input[ctr]) == -1) continue;
                ctr = execute(input[ctr], ctr);
            }
            // stack<char> s;
            // s.push(mem[ctr++]);
            // string to_do;
            // if (mem[ctr-1] == ']') {
            //     // get
            //     stack<char> r;
            //     char tmp = s.top();
            //     s.pop();
            //     tmp = s.top();
            //     s.pop();
            //     while (tmp != '[') {
            //         r.push(tmp);
            //         tmp = s.top();
            //         s.pop();
            //     }
            //     while (!r.empty()) {
            //         to_do.push_back(r.top());
            //         r.pop();
            //     }
            // }

            // if (s.empty()) break;
        }

        pos = ctr;
    }
    return pos;
}