#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int _max = -0x2f2f2f, _min = 0x2f2f2f, _sum = 0;
    for (int i = 0; i < n; i++) {
        long long int tmp;
        cin >> tmp;
        if (tmp >= _max)
            _max = tmp;
        if (tmp <= _min)
            _min = tmp;
        _sum += tmp;
    }
    cout << _max << endl << _min << endl << _sum;
    return 0;
}