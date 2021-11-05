#include <bits/stdc++.h>
using namespace std;

long long sum(int n, int p)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + pow(i + 1, p);
    }
    return sum;
}

int main()
{
    int n, p;
    cin >> n >> p;
    cout << sum(n, p);
}