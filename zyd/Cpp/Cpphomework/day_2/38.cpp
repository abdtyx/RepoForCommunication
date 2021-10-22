#include <bits/stdc++.h>
using namespace std;

int check(int a[], int n);

int main()
{
    int n, sum = 0;
    int a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++)
    {
        sum = check(a, n);
    }
    cout << sum << endl;
}

int check(int a[], int n)
{
    int r = 0, sum2 = 0;
    for (int k = 0; k < n; k++)
    {
        for (int m = 1; m <= a[k]; m++)
        {
            if (a[k] % m == 0)
            {
                r++;
            }
        }
        if (r == 2)
        {
            sum2 = sum2 + a[k];
        }
        r = 0;
    }
    return sum2;
}