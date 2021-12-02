#include <bits/stdc++.h>
#include <regex>

using namespace std;

int main() {
    // // regex r("^Reply from 202.117.0.20.*\n$");
    // string s = "Reply from 202.117.0.20: bytes=1472 time=8ms TTL=60\n";
    // bool b = regex_match(s, r);
    // cout << b;
    int res = system("getSystem 123");
    if (res == 1) puts("Windows");
    else puts("Linux");
    return 0;
}