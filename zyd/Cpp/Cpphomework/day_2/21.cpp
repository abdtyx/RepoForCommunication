#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double h = b * b - 4 * a * c;
    if (a != 0)
    {
        if (h < 0)
        {
            cout << "no root";
        }
        else if (h == 0)
        {

            -b / (2 * a) != 0 ? cout << -b / (2 * a) << endl : cout << "0" << endl;
        }
        else
        {
            cout << (-b - sqrt(h)) / (2 * a) << " " << (-b + sqrt(h)) / (2 * a) << endl;
        }
    }
    else
    {
        if (b == 0)
        {
            cout << "no root" << endl;
        }
        else
        {
            cout << -c / b << endl;
        }
    }
}