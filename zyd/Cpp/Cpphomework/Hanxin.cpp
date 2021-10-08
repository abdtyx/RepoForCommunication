#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num = 0, a, b, c;
    cin >> a >> b >> c;
    for (int i = 10; i <= 100; i++)
    {
        if (i % 3 == a && i % 5 == b && i % 7 == c)
        {
            num = i;
            break;
        }
    }
    num == 0 ? cout << "No answer" : cout << num;
}