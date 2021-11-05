#include <bits/stdc++.h>
using namespace std;

typedef struct _Code
{
    char m[30] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', ';', 'w', 'o', 'y', 'z', 'n'};
    char n[30] = {'d', 'w', 'k', ';', 'i', 'h', 'm', 'o', 'a', 'z', 'b', 'n', 'y', 'c', 'e', 'f', 'g', 'j', 'l'};
} Code;

int main()
{
    Code code;
    string s;
    getline(cin, s);
    char a[100];
    strcpy(a, s.c_str());
    for (int i = 0; i < strlen(a); i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (a[i] == code.n[j])
            {
                a[i] = code.m[j];
                break;
            }
        }
    }
    cout << a;
}