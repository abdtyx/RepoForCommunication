#include <bits/stdc++.h>
using namespace std;

int Fibo(int n);

int main()
{
    int n;
    cin >> n;
    cout << Fibo(n);
}

int Fibo(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
       return Fibo(n - 1) + Fibo(n - 2);
    }
}