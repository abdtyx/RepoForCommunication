#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k = 1;
    cin >> n;
    int a[100][100];
    int x = n - 1, y = n - 1, z = 0, m = 0;
    while (m <= x && z <= y)
    {
        for (i = m; i <= y; i++)
        {
            a[i][x] = k;
            k++;
        }
        for (j = y - 1; j > z; j--)
        {
            a[x][j] = k;
            k++;
        }
        for (i = y; i > m; i--)
        {
            a[i][z] = k;
            k++;
        }
        for (j = m; j < x; j++)
        {
            a[m][j] = k;
            k++;
        }
        m++;
        z++;
        x--;
        y--;
    }
    for (int g = 0; g < n; g++)
    {
        for (int h = 0; h < n; h++)
        {
            h == 0 ? cout << a[g][h] : cout << " " << a[g][h];
        }
        cout << endl;
    }
}