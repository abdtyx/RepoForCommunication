#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int j = 0;
    char c;
    getline(cin, s);
    char a[10000], b[10000];
    b[0] = 0;
    strcpy(a, s.c_str());
    for (int i = 0; i < strlen(a); i++)
    {
        c = a[i];
        if (c == b[j] + 1 || c == b[j] + 2)
        {
            b[j] = 0;
            if (j != 0)
            {
                j--;
            }
        }
        else
        {
            if (b[j] != 0)
            {
                j++;
            }
            b[j] = c;
        }
    }
    if (b[0] == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}