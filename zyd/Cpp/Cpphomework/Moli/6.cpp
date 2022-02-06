#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    sort(a, a + 8);
    for (int i = 0; i < 8; i++)
    {
        i == 0 ? cout << a[i] : cout << " " << a[i];
    }
}