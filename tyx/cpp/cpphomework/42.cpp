#include <bits/stdc++.h>

using namespace std;
/*
int main() {
    int arr[1000];
    cin >> arr[0];
    char tmp;
    // cin >> tmp;
    tmp = cin.peek();
    int ctr = 1;
    while (tmp == ' ') {
        cin >> arr[ctr];
        ctr++;
        // cin >> tmp;
        tmp = cin.peek();
    }
    int to_search;
    cin >> to_search;
    sort(arr, arr + ctr);
    // int* debug = lower_bound(arr, arr + ctr, to_search);
    int ans = (lower_bound(arr, arr + ctr, to_search) - arr);
    if (ans == ctr)
        cout << "-1";
    else
        cout << ans;
    return 0;
}*/
int main() {
    int arr[1000];
    cin >> arr[0];
    char tmp;
    // cin >> tmp;
    tmp = cin.peek();
    int ctr = 1;
    while (tmp == ' ') {
        cin >> arr[ctr];
        ctr++;
        // cin >> tmp;
        tmp = cin.peek();
    }
    int to_search;
    cin >> to_search;
    int ans = -1;
    for (int i = 0; i < ctr; i++) {
        if (arr[i] == to_search) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}