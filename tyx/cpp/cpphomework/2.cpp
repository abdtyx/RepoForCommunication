#include <bits/stdc++.h>
using namespace std;

double CtoF(double Celsius);

int main() {
    double Celsius;
    cin >> Celsius;
    cout << "Fahrenheit temperature is " << CtoF(Celsius) << " degree";
    return 0;
}

double CtoF(double Celsius) {
    return 1.8 * Celsius + 32.0;
}