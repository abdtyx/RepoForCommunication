#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);
int mod_reverse1(int a, int b, int divisor);

int main() {
    int a = 3, b = 5, c = 7;
    int x, y, z;
    cin >> x >> y >> z;
    int tmp = x * mod_reverse1(b, c, a) + y * mod_reverse1(a, c, b) + z * mod_reverse1(a, b, c);
    int ans = tmp % lcm(lcm(a, b), c);
    if (ans >= 10 && ans <= 100)
        cout << ans;
    else 
        cout << "No answer";
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int mod_reverse1(int a, int b, int divisor) {
    int multiples = lcm(a, b);
    int n = 1, sum = multiples;
    while (sum % divisor != 1) {
        n++;
        sum = n * multiples;
    }
    return sum;
}