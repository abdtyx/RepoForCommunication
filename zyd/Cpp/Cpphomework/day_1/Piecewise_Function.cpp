#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x;
    if (x == 0)
    {
        cout << 0;
    }
    else if (x > 0)
    {
        cout << 3 * x + 1;
    }
    else
    {
        cout << x * x - 1;
    }
    return 0;
}