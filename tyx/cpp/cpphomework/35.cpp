#include <bits/stdc++.h>

using namespace std;

int main() {
    double arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 10);
    for (int i = 0; i < 10; i++) {
        if (i == 0)
            cout << arr[0];
        else
            cout << " " << arr[i];
    }
}