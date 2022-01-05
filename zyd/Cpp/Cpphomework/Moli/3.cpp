#include <bits/stdc++.h>
using namespace std;

char checkout(char a[], char b[]);
void bubble(char a[]);

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    char a[100], b[100];
    strcpy(a, s1.c_str());
    strcpy(b, s2.c_str());
    cout << checkout(a, b) << endl;
}

char checkout(char a[], char b[])
{
    int len;
    bubble(a);
    bubble(b);
    strlen(a) < strlen(b) ?  len = strlen(a) : len = strlen(b);
    for (int n = 0; n<len;n++)
    {
        if (a[n]!=b[n])
        {
            return a[n];
        }
    }
    return strlen(a) < strlen(b) ? b[len]:a[len];
}

void bubble(char a[])
{
    char c;
    for (int i = 0; i < strlen(a) - 1; i++)
    {
        for (int k = 0; k < strlen(a) - 1 - i; k++)
        {
            if (a[k] > a[k + 1])
            {
                c = a[k];
                a[k] = a[k + 1];
                a[k + 1] = c;
            }
        }
    }
}