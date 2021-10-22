#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    sort(a, a + 10, greater<double>());
    for (int i = 0; i < 10; i++)
    {
        i == 0 ? cout << a[i] : cout << " " << a[i];
    }
}