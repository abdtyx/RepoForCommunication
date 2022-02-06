#include <iostream>
#include <cstring>
using namespace std;

class complex
{
private:
    double rl;
    double im;

public:
    complex(double i = 0, double j = 0) : rl(i), im(j) {}
    complex operator~();
    complex operator+(const complex &t);
    complex operator-(const complex &t);
    complex operator*(const complex &t);
    complex operator*(int &x);
    friend ostream &operator<<(ostream &out, const complex &t);
    friend istream &operator>>(istream &in, complex &t);
    // void show()
    // {
    //     cout << "real:" << rl << endl
    //          << "imaginary:" << im << endl;
    // }
};

complex complex::operator~()
{
    complex c;
    c.rl = rl;
    c.im = -im;
    return c;
}

complex complex::operator+(const complex &t)
{
    complex c;
    c.rl = this->rl + t.rl;
    c.im = this->im + t.im;
    return c;
}

complex complex::operator-(const complex &t)
{
    complex c;
    c.rl = this->rl - t.rl;
    c.im = this->im - t.im;
    return c;
}

complex complex::operator*(const complex &t)
{
    complex c;
    c.rl = this->rl * t.rl - this->im * t.im;
    c.im = this->rl * t.im + this->im * t.rl;
    return c;
}

complex complex::operator*(int &x)
{
    complex c;
    c.rl = x * this->rl;
    c.im = x * this->im;
    return c;
}

ostream &operator<<(ostream &out, const complex &t)
{
    out << "(" << t.rl << "," << t.im << "i"
        << ")";
    return out;
}

istream &operator>>(istream &in, complex &t)
{
    // string s1, s2;
    // char c1[100], c2[100], c3[10], c4[10];
    double a, b;
    cout << "real:";
    in >> a;
    if (a == '\0')
    {
        return in;
    }
    cout<<"imaginary:";
    in >> b;
    // in >> s1;
    // in >> s2;
    // strcpy(c1, s1.c_str());
    // strcpy(c2, s2.c_str());
    // for (int i = 5; i <= strlen(c1); i++)
    // {
    //     c3[i - 5] = c1[i];
    // }
    // for (int i = 10; i <= strlen(c2); i++)
    // {
    //     c4[i - 10] = c2[i];
    // }
    // a = (double)atof(c3);
    // b = (double)atof(c4);
    t.rl = a;
    t.im = b;
    return in;
    // }
}

int main()
{
    complex a(3.0, 4.0); // initialize to (3,4i)
    complex c;
    // char b;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        int t = 2;
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << c * t << '\n';
        cout << "Enter a complex number (q to quit):\n";
        // cin << b;
        // if (b == 'q')
        // {
        //     break;
        // }
    }
    cout << "Done!\n";
    return 0;
}