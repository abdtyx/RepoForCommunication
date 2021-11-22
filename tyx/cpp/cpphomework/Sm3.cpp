#include <bits/stdc++.h>

using namespace std;

char search(string& str1, string& str2);

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    char ans = search(str1, str2);
    cout << ans;
    return 0;
}

char search(string& str1, string& str2) {
    int arr1[60], arr2[60];
    for (int i = 0; i < 60; i++) {
        arr1[i] = 0;
        arr2[i] = 0;
    }
    // int _min, flag;
    // if (str1.size() > str2.size()) {
    //     _min = str2.size();
    //     flag = 1;
    // }
    // else {
    //     _min = str1.size();
    //     flag = 2;
    // }
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            arr1[str1[i] - 'A' + 1]++;
        }
        else if (str1[i] >= 'a' && str1[i] <= 'z') {
            arr1[str1[i] - 'a' + 27]++;
        }
        else if (str1[i] == ' ') {
            arr1[0]++;
        }
    }
    for (int i = 0; i < str2.size(); i++) {
        if (str2[i] >= 'A' && str2[i] <= 'Z') {
            arr2[str2[i] - 'A' + 1]++;
        }
        else if (str2[i] >= 'a' && str2[i] <= 'z') {
            arr2[str2[i] - 'a' + 27]++;
        }
        else if (str2[i] == ' ') {
            arr2[0]++;
        }
    }
    for (int i = 0; i < 60; i++) {
        if (arr1[i] != arr2[i]) {
            if (i == 0)
                return ' ';
            else if (i >= 1 && i <= 26) {
                return 'A' + i - 1;
            }
            else if (i >= 27 && i <= 52) {
                return 'a' + i - 27;
            }
        }
    }
}