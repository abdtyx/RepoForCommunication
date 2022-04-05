#include <bits/stdc++.h>

using namespace std;
template<typename T>
inline T read() {
    T sum = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        sum = sum * 10 + ch - '0';
        ch = getchar();
    }
    return sum * f;
}
template<typename T>
inline void print(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}



int main() {
    int a;
    a = read<int>();
    print<int>(a);
    return 0;
}