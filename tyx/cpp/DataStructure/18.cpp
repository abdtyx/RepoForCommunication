#include <iostream>
#include <vector>

using namespace std;

class Double {
    public:
        long long sig;
        long long integer;
        long long numerator;  // numerator / denominator
        long long denominator;
    Double() {
        numerator = integer = 0;
        denominator = sig = 1;
    }
    Double(long long n, long long d) {
        if (n < 0) {
            n = -n;
            sig = -1;
        }
        else if (d < 0) {
            d = -d;
            sig = -1;
        }
        else sig = 1;
        integer = n / d;
        n = n % d;
        long long g = gcd(n, d);
        n /= g;
        d /= g;
        numerator = n;
        denominator = d;
    }
    static long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    static long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }
    friend Double& operator+(Double& a, Double& b) {
        Double* c = new Double;
        c->integer = a.integer * a.sig + b.integer * b.sig;
        long long deno = c->lcm(a.denominator, b.denominator);
        long long nume = deno / a.denominator * a.numerator * a.sig + deno / b.denominator * b.numerator * b.sig + c->integer * deno;
        c->integer = 0;
        if (nume == 0) {
            c->numerator = 0;
            c->integer = 0;
            c->denominator = a.denominator;
            return *c;
        }
        if (nume < 0) {
            nume = -nume;
            c->sig = -1;
        }
        long long g = c->gcd(nume, deno);
        c->denominator = deno / g;
        c->numerator = nume / g;
        if (c->numerator >= c->denominator) {
            c->integer += c->numerator / c->denominator;
            c->numerator = c->numerator % c->denominator;
        }
        return *c;
    }
    friend ostream& operator<<(ostream& os, Double& d) {
        if (d.integer != 0) {
            os << d.sig * d.integer;
        }
        if (d.numerator != 0 && d.integer != 0) {
            os << ' ' << d.numerator << '/' << d.denominator;
        }
        else if (d.numerator != 0) {
            os << d.numerator * d.sig << '/' << d.denominator;
        }
        if (d.numerator == 0 && d.integer == 0) {
            os << '0';
        }
        return os;
    }
};

int main() {
    long long n;
    cin >> n;
    char abd = getchar();
    vector<Double> v;
    for (long long i = 0; i < n; i++) {
        // long long nume = 0, deno = 0, sig = 1;
        // char ch = getchar();
        // while (ch != '/') {
        //     if (ch == '-') {sig = -1;}
        //     else {nume = nume * 10 + ch - '0';}
        //     ch = getchar();
        // }
        // ch = getchar();
        // while (ch != '\n') {
        //     deno = deno * 10 + ch - '0';
        //     ch = getchar();
        // }
        // Double d(nume * sig, deno);
        // v.push_back(d);
        long long nume, deno;
        cin >> nume >> abd >> deno;
        Double d(nume, deno);
        v.push_back(d);
    }
    Double s = v[0];
    for (long long i = 1; i < v.size(); i++) {
        s = s + v[i];
    }
    cout << s;
    return 0;
}