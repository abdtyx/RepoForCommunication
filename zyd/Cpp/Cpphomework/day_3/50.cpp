#include <bits/stdc++.h>
using namespace std;

typedef struct _asdf
{
    string s1;
    int num = 0;
} asdf;

void bubble(asdf a[], int j);

int main()
{
    int N, j = 1;
    string s;
    asdf a[10000];
    a[0].s1 = "0";
    cin >> N;
    while (N--)
    {
        int i;
        cin >> s;
        for (i = 0; i < j; i++)
        {
            if (a[i].s1 == s)
            {
                a[i].num++;
                break;
            }
        }
        if (i == j)
        {
            a[j - 1].s1 = s;
            a[j - 1].num++;
            j++;
        }
    }
    bubble(a, j);
    cout << a[0].s1 << " " << a[0].num << endl;
}

void bubble(asdf a[], int j)
{
    asdf b;
    for (int i = 0; i < j - 1; i++)
    {
        for (int k = 0; k < j - i + 1; k++)
        {
            if (a[k].num < a[k + 1].num)
            {
                b = a[k];
                a[k] = a[k + 1];
                a[k + 1] = b;
            }
        }
    }
}