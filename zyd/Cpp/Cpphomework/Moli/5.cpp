#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1;
    cin >> s1;
    char a[200], b[200];
    int count = 0, n = 1, t = 0;
    strcpy(a, s1.c_str());
    for (int k = 0; k < strlen(a) - 1; k++)
    {
        if (a[k] == a[k + 1])
        {
            count++;
        }
    }
    if (count == 0)
    {
        cout << s1;
    }
    else
    {
        b[0] = a[0];
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] == b[t])
            {
                if (n >= 2)
                {
                    b[t + 1] = n + '0';
                }
                n++;
            }
            else
            {
                if (b[t + 1] >= '2' && b[t + 1] <= '9')
                {
                    t = t + 2;
                    b[t] = a[i];
                    n = 1;
                }
                else
                {
                    t = t + 1;
                    b[t] = a[i];
                    n = 1;
                }
            }
        }
    }
    cout << b;
}