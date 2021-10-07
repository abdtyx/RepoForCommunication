#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int ctr = 0;
    cin >> str;
    while (str != "done") {
        ctr++;
        cin >> str;
    }
    cout << "You entered a total of " << ctr << " words.";
}