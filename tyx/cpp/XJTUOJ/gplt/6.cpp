#include <bits/stdc++.h>

using namespace std;

int main() {
    int* arr = new int[100005];
    int tmp, ctr = 0;
    while (cin >> tmp) {
        if (tmp == -1) break;
        arr[ctr++] = tmp;
    }
    sort(arr, arr + ctr);
    cout << arr[ctr - 1] << ' ' << arr[0];
    return 0;
}