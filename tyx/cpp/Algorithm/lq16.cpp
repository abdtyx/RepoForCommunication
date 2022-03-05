#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (!(n % 4) && (n % 100) || !(n % 400))
        cout << "yes";
    else
        cout << "no";
    return 0;
}