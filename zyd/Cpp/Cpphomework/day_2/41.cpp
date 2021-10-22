#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x, sum = 0;
    int n;
    cin >> n;
    while (n)
    {
        n = n / 5;
        sum = sum + n;
    }
    cout << sum;
}