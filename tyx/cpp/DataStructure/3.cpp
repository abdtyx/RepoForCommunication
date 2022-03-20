#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char str[10005], temp[10005], str2[10005]; // source temp substr
    memset(str, 0, 10005);
    memset(str2, 0, 10005);
    memset(temp, 0, 10005);
    // cin >> str >> str2;
    cin.getline(str, 10005);
    cin.getline(str2, 10005);
    // cin.get(str2, 10005);
    // bool a = false;
    for (int i = 0; i < strlen(str); i++) {
        memset(temp, 0, 10005);
        strncpy(temp, str + i, strlen(str2));
        if (!strcmp(str2, temp)) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}