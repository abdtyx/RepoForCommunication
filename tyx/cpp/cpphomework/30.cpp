#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[8];
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }
    for (int i = 7; i >= 0; i--) {
        if (i == 7)
            cout << arr[i];
        else
            cout << " " << arr[i];
    }
}