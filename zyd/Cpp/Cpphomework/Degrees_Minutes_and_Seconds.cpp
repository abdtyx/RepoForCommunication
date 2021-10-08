#include <iostream>
using namespace std;
int main()
{
    float D, M, S, Sum;
    cin >> D >> M >> S;
    cout << D << " degrees, " << M << " minutes, " << S << " seconds = " << D + M / 60.0 + S / 3600.0 << " degrees" << endl;
}