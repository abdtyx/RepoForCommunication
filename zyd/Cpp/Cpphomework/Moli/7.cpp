#include <bits/stdc++.h>
using namespace std;

void Reverse(char *s)
{
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void swap(char **p1, char **p2)
{
    char *a;
    a = *p1;
    *p1 = *p2;
    *p2 = a;
}

void jisuan(char *tmp1, char *tmp2, char *tmp3)
{
    char **p;
    if (strlen(tmp1) > strlen(tmp2))
    {
        swap(&tmp1, &tmp2);
    }
    char *p1, *p2;
    int n = 0, t = 0, m = 0;
    p1 = &tmp1[strlen(tmp1) - 1];
    p2 = &tmp2[strlen(tmp2) - 1];
    int len = strlen(tmp1);
    for (int i = 0; i < len; i++)
    {
        if (*p1 + *p2 - '0' - '0' < 9 || (*p1 + *p2 - '0' - '0' == 9 && t == 0))
        {
            tmp3[n] = *p1 + *p2 - '0' + t;
            p1--;
            p2--;
            n++;
            t = 0;
        }
        else if (*p1 + *p2 - '0' - '0' > 9 || (*p1 + *p2 - '0' - '0' == 9 && t == 1))
        {
            tmp3[n] = *p1 + *p2 - (10 + '0') + t;
            p1--;
            p2--;
            n++;
            t = 1;
        }
    }
    int len2 = strlen(tmp2) - strlen(tmp1);
    if (t == 0)
    {
        for (int i = len2 - 1; i >= 0; i--)
        {
            tmp3[n] = tmp2[i];
            n++;
        }
        tmp3[n] = 0;
        Reverse(tmp3);
        // strrev(tmp3);
    }
    else
    {
        for (int i = len2 - 1; i >= 0; i--)
        {
            i == len2 - 1 ? tmp3[n] = tmp2[i] + t : tmp3[n] = tmp2[i];
            n++;
        }
        tmp3[n] = 0;
        Reverse(tmp3);
        // strrev(tmp3);
        // 实在是不想想了。。
    }
}

int main(int argc, const char *argv[])
{
    char tmp1[200], tmp2[200], tmp3[300];
    std::cin >> tmp1;
    std::cin >> tmp2;
    jisuan(tmp1, tmp2, tmp3);
    std::cout << tmp3 << std::endl;
    return 0;
}