#include <bits/stdc++.h>

using namespace std;
void bubble(char arr[], int n);
int ans;
int main() {
    char arr[80] = "jihgfeeddbbccaa";
    bubble(arr, strlen(arr));
    cout << ans;
    return 0;
}

void bubble(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                char tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                ans++;
                res++;
            }
        }
        cout << res << endl;
    }
}