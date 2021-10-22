#include <iostream>

using namespace std;
int main()
{
    int a, b, GCD, LCM;
    cin >> a >> b;
    GCD = a;
    LCM = b;
    while (GCD % a != 0 || GCD % b != 0)
    {
        GCD++;
    }
    while (b % LCM != 0 || a % LCM != 0)
    {
        LCM--;
    }
    cout << LCM << " " << GCD;
}
