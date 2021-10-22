#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, a[1000];
    int num = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    for (int j = 1; j <= k; j++)
    {
        for (; num <= n; num++)
        {
            if ((num + 1) % j == 0)
            {
                a[num] == 0 ? a[num] = 1 : a[num] = 0;
            }
        }
        num = 0;
    }
    int count = 1;
    for (int l = 0; l < n; l++)
    {
        if (a[l] == 1)
        {
            count != 1 ? cout << " " << l + 1 : cout << l + 1;
            count = 0;
        }
    }
}