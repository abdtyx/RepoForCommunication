#include <bits/stdc++.h>
using namespace std;

void info(int a[][3]);
void calculate(int a[][3], int b[][3], int c[][3]);
void output(int c[][3]);

int main()
{
    int a[3][3], b[3][3], c[3][3];
    info(a);
    info(b);
    calculate(a, b, c);
    output(c);
}

void info(int a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
}

void calculate(int a[][3], int b[][3], int c[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
        }
    }
}

void output(int c[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            j == 0 ? cout << c[i][j] : cout << " " << c[i][j];
        }
        cout << endl;
    }
}