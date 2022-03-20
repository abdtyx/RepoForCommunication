#include <iostream>
#include <algorithm>

using namespace std;

bool mycmp(double a, double b) {
    return a > b;
}

int main() {
    int l;
    cin >> l;
    double arr[1005];
    int ctr = 0;
    while (cin >> arr[ctr++] && ctr < 3);
    sort(arr, arr + ctr, mycmp);
    cout << arr[0];
    return 0;
}