#include <bits/stdc++.h>
using namespace std;

void change(char a[], int left, int right)
{
    int t = a[left];
    if (left == right)
    {
        return;
    }
    change(a, left + 1, right);
    for (int i = left; i < right; i++)
    {
        a[i] = a[i + 1];
    }
    a[right] = t;
}

int main()
{
    string s;
    char a[100];
    getline(cin, s);
    strcpy(a, s.c_str());
    int left = 0, right = strlen(a);
    change(a, left, right);
    int j = 1;
    for (; j < right + 1; j++)
    {
        if (a[j] != '0')
        {
            break;
        }
    }
    if (j == right + 1)
    {
        cout << "0";
        return 0;
    }
    for (; j < right + 1; j++)
    {
        cout << a[j];
    }
}