#include <bits/stdc++.h>
using namespace std;

void output(int a[], int n, int r);

int main()
{
    int n, r, p, tmp, k;
    cin >> n >> r;
    p = n - 1;
    int a[200] = {0};
    for (int i = n - r; i < n; i++)
    {
        a[i] = 1;
    }
    output(a, n, r);
    while (1)
    {
        for (k = 0; k <= n - r; k++)
        {
            if (a[k] == 0)
            {
                break;
            }
        }
        if (k == n - r + 1)
        {
            break;
        }
        if (a[p] == 1 && a[p - 1] == 0)
        {
            tmp = a[p];
            a[p] = a[p - 1];
            a[p - 1] = tmp;
            output(a, n, r);
        }
        if (p == 1)
        {
            p = n - 1;
        }
        else
        {
            p--;
        }
    }
    return 0;
}

void output(int a[], int n, int r)
{
    for (int j = n; j >= 0; j--)
    {
        if (a[j] == 1)
        {
            cout << j + 1;
        }
    }
    cout << endl;
}