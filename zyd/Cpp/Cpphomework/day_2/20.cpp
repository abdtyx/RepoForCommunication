#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num = 0, row = 0;

    for (int i = 2; i <= 1000; i++)
    {
        for (int n = 1; n <= i; n++)
        {
            if (i % n == 0)
            {
                num++;
            }
        }
        if (num == 2)
        {
            cout << setw(5) << i;
            row++;
        }
        if (row == 5)
        {
            cout << endl;
            row = 0;
        }
        num = 0;
    }
}