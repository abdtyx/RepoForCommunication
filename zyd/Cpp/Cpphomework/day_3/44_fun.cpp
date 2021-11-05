#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    a = max(a, b);
    cout << max(a, c);
}