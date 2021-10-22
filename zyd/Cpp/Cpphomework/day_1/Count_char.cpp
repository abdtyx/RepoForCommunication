#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int main()
{
    char a[100];
    cin.getline(a,100);
    int len = strlen(a);
    int D = 0, L = 0, B = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] <='9' && a[i] >= '0')
        {
            D++;
        }
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
        {
            L++;
        }
        if (a[i] == ' ')
        {
            B++;
        }
    }
    printf("%d %d %d", D, L, B);
    return 0;
}