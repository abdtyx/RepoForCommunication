#include <iostream>
#include <cstring>

using namespace std;

class largeInt
{
private:
    char n[1000];

public:
    largeInt();
    largeInt(char a[]);
    friend largeInt operator+(largeInt &a, largeInt &b);
    friend ostream &operator<<(ostream &ot, const largeInt &a);
};

largeInt::largeInt()
{
    n[0] = 0;
}

largeInt::largeInt(char a[])
{
    strcpy(n, a);
}

largeInt operator+(largeInt &a, largeInt &b)
{
    largeInt t;
    int len1 = strlen(a.n);
    int len2 = strlen(b.n);
    if (len1 <= len2)
    {
        largeInt c;
        strcpy(c.n, a.n);
        strcpy(a.n, b.n);
        strcpy(b.n, c.n);
    }
    len1 = strlen(a.n);
    len2 = strlen(b.n);
    int num = 0;
    int x = 0;
    for (int i = len2 - 1; i >= 0; i--)
    {
        if ((a.n[len1 - len2 + i] + b.n[i] - '0' - '0' < 9) || (a.n[len1 - len2 + i] + b.n[i] - '0' - '0' == 9 && x == 0))
        {
            t.n[num] = a.n[len1 - len2 + i] - '0' + b.n[i] + x;
            x = 0;
            num++;
        }
        else if ((a.n[len1 - len2 + i] + b.n[i] - '0' - '0' > 9) || (a.n[len1 - len2 + i] + b.n[i] - '0' - '0' == 9 && x == 1))
        {

            t.n[num] = a.n[len1 - len2 + i] - '0' + b.n[i] + x - 10;
            x = 1;
            num++;
        }
    }
    for (int i = len1 - len2 - 1; i >= 0; i--)
    {
        (x == 1 && i == len1 - len2 - 1) ? t.n[num] = a.n[i] + x : t.n[num] = a.n[i];
        num++;
    }
    int len3 = strlen(t.n);
    for (int i = 0, j = len3 - 1; i < j; i++, j--)
    {
        char c = t.n[i];
        t.n[i] = t.n[j];
        t.n[j] = c;
    }
    t.n[len3] = 0;
    return t;
}

ostream &operator<<(ostream &ot, const largeInt &a)
{
    int len = strlen(a.n);
    for (int i = 0; i < len; i++)
    {
        ot << a.n[i];
    }
    return ot;
}

int main(int argc, const char * argv[])
{
    char tmp1[1000], tmp2[1000];
    cin >> tmp1;
    cin >> tmp2;
    largeInt int1(tmp1), int2(tmp2);
    cout << int1 + int2 << endl;
    return 0;
}