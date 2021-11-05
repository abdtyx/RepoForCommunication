#include <bits/stdc++.h>
using namespace std;

long lk(int y1, int y2, int a, int b, int c, int n)
{
    if (n == 1)
    {
        return y1;
    }
    else if (n == 2)
    {
        return y2;
    }
    else
    {
        return a * lk(y1, y2, a, b, c, n - 2) + b * lk(y1, y2, a, b, c, n - 1) + c;
    }
}

int main()
{
    int y1, y2, a, b, c, n;
    int sum;
    cin >> y1 >> y2 >> a >> b >> c >> n;
    sum = lk(y1, y2, a, b, c, n);
    while (sum < 0)
    {
        sum += 1000007;
    }
    cout << sum % 1000007;
}