#include <iostream>
using namespace std;

long long Factorial(long long x) {
    return x ? x * Factorial(x - 1) : 1;
}

int main()
{
    int x, sum = 1;
    cin >> x;
    cout << Factorial(x);
}

