#include <bits/stdc++.h>

using namespace std;

int main() {
    char str[100];
    int digits = 0, letters = 0, blanks = 0;
    cin.get(str, 100);
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            letters++;
        if (str[i] >= '0' && str[i] <= '9')
            digits++;
        if (str[i] == ' ')
            blanks++;
    }
    cout << digits << " " << letters << " " << blanks;
}