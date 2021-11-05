#include <bits/stdc++.h>
using namespace std;

int fun(int a[], int b, int c, int d);

int main()
{
    int a[20], b, c = 0, d = 9;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &b);
    printf("%d", fun(a, b, c, d));
}

int fun(int a[], int b, int c, int d)
{
    int n = (c + d) / 2;
    if (c <= d)
    {
        if (b < a[n])
        {
            return fun(a, b, c, n - 1);
        }
        else if (b > a[n])
        {
            return fun(a, b, n + 1, d);
        }
        else
        {
            return n;
        }
    }
    else
    {
        return -1;
    }
}