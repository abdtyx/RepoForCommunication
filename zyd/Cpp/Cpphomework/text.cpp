#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[20];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    int m, num = n;
    cin >> m;
    while (num)
    {
        if (m == a[num])
        {
            break;
        }
        num--;
    }
    return 0;
}