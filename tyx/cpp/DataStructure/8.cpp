#include <iostream>

using namespace std;

int main() {
    int n, ctr = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        while (!(tmp % 5)) {
            ctr++;
            tmp /= 5;
        }
    }
    cout << ctr;
    return 0;
}