#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[20], b;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &b);
    for (int i = 0; i < 10; i++)
    {
        if (b == a[i])
        {
            cout << b << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}