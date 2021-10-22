#include <bits/stdc++.h>
using namespace std;
int main()
{
    char dst[100];
    char src[100];
    int a = 0;
    scanf("%[^\n]%*c", dst);
    scanf("%[^\n]%*c", src);
    for (int i = 0; i < strlen(dst); i++)
    {
        if (dst[i] != src[i])
        {
            a = i + 1;
            break;
        }
    }
    for (int i = 0; i < strlen(src); i++)
    {
        if (dst[i] != src[i])
        {
            a = i + 1;
            break;
        }
    }
    printf("%d", a);
}