#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int to_search;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> to_search;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = i; j < n; j++) {
            if (arr[i] + arr[j] == to_search) {
                cout << '[' << i << ',' << j << ']';
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    return 0;
}