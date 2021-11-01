#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int space = 0, capital = 0, lowercase = 0, number = 0, upb = s.size();
    for (int i = 0; i < upb; i++) {
        if (s[i] == ' ')
            space++;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            capital++;
        else if (s[i] >= 'a' && s[i] <= 'z')
            lowercase++;
        else if (s[i] >= '0' && s[i] <= '9')
            number++;
    }
    cout << "space: " << space << endl
    << "capital: " << capital << endl
    << "lowercase: " << lowercase << endl
    << "number: " << number;
    return 0;
}