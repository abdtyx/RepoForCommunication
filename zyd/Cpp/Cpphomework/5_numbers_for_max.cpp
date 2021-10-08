#include <bits/stdc++.h>
using namespace std;
int main()
{
    long a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    sort(a, a + 5);
    cout << a[0] << " " << a[4];
}