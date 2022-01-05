#include <bits/stdc++.h>

using namespace std;

int main() {
    // Merge_sort
    int arr1[4], arr2[4], ans[8], ctr1 = 0, ctr2 = 0;
    for (int i = 0; i < 4; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> arr2[i];
    }
    for (int i = 0; i < 8; i++) {
        if (ctr1 < 4) {
            if (ctr2 < 4 && arr2[ctr2] < arr1[ctr1])
                ans[i] = arr2[ctr2++];
            else 
                ans[i] = arr1[ctr1++];
        }
        else {
            if (ctr2 < 4) {
                ans[i] = arr2[ctr2++];
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        if (i == 0) 
            cout << ans[i];
        else 
            cout << ' ' << ans[i];
    }
}