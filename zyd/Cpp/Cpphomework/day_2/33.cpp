#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[100];
    char c;
    int n = 0;
    //
    scanf("%[^\n] %c", a, &c);
    for (int i = 0; i < strlen(a); i++)
    {
        if (c == a[i])
        {
            n = i + 1;
            break;
        }
    }
    printf("%d", n);
}