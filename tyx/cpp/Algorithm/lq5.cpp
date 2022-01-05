#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int upb = 0;
    int findway = n;
    while (findway /= 16) {
        upb++;
    }
    string hex;
    hex.clear();
    while (upb != -1) {
        int tmp = n / (int)pow(16, upb);
        n %= (int)pow(16, upb);
        upb--;
        if (tmp >= 0 && tmp <= 9) {
            hex.push_back(tmp + '0');
        }
        else if (tmp >= 10 && tmp <= 15) {
            hex.push_back(tmp + 'A' - 10);
        }
    }
    cout << hex;
    return 0;
}