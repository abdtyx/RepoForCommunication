#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N;
    cin >> M;
    N = M;
    int flag = 0;
    while (1)
    {
        for (int i = 2; i < N; i++)
        {
            if (N % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
        N--;
        flag = 0;
    }
    int N1;
    if (N < 2)
    {
        N1 = 2;
        cout << N1 << " " << N1 - M;
        return 0;
    }
    else
    {
        N1 = N;
        N = M + 1;
        flag = 0;
    }

    flag = 0;
    while (1)
    {
        for (int i = 2; i < N; i++)
        {
            if (N % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
        N++;
        flag = 0;
    }
    int N2 = N;
    (N2 - M) < (M - N1) ? cout << N2 << " " << N2 - M : cout << N1 << " " << M - N1;
}