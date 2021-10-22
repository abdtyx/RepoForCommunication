#include <iostream>
using namespace std;
int main()
{
    int a, b, Sum = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        Sum = Sum + i;
    }
    cout << Sum << endl;
}