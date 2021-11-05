#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, sum = 1;
    cin >> m;
    for (int i = 0; i < m-1; i++)
    {
        if (sum > 1000000)
        {
            sum = sum % 1000000;
        }
        sum = sum * 2 + 1;
    }
    cout<<sum;
}