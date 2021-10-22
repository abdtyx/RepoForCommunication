#include <bits/stdc++.h>

using namespace std;


bool cmp(double a, double b) {
    return a > b;
}


int main() {
    double arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 10, cmp);
    for (int i = 0; i < 10; i++) {
        if (i == 0)
            cout << arr[0];
        else
            cout << " " << arr[i];
    }
}