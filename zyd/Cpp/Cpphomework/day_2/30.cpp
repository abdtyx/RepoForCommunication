#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    for (int j = 7; j >= 0; j--)
    {
        j == 7 ? cout << a[j] : cout << " " << a[j];
    }
}