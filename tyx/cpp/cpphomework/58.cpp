#include <iostream>
// #include "complex0.h"

using namespace std;

class complex {
    private:
        double Re, Im;
    public:
        complex(double re = 0, double im = 0) {
            Re = re;
            Im = im;
        };
        ~complex() {
            bool debug = false;
            if (debug) {
                cout << "helloworld" << endl;
            }
        };
        // void operator<<(complex c) {
        //     cout << '(' << Re << ',' << Im << "i)" << endl;
        // }
        // void operator>>(complex c) {
        //     cout << "real:";
        //     cin >> Re;
        //     cout << "imaginary:";
        //     cin >> Im;
        // }
        friend ostream &operator<<(ostream &output, const complex &c) {
            output << '(' << c.Re << ',' << c.Im << "i)";
            return output;
        }
        friend istream &operator>>(istream &input, complex &c) {
            // static int flag = 0;
            // if (flag) {
            //     input >> c.Re;
            //     return input;
                // if (input.peek() == 'q') {
                //     input >> c.Re;
                //     return input;
                // }
                // else {
                //     cout << "real:";
                //     input >> c.Re;
                //     cout << "imaginary:";
                //     input >> c.Im;
                // }
            // }
            // else {
            cout << "real:";
            input >> c.Re;
            if (c.Re == '\0')
                return input;
            cout << "imaginary:";
            input >> c.Im;
            // }
            // flag++;
            return input;
        }
        complex operator~() {
            complex cc(this->Re, -this->Im);
            return cc;
        }
        complex operator+(complex c) {
            complex cc(this->Re + c.Re, this->Im + c.Im);
            return cc;
        }
        complex operator-(complex c) {
            complex cc(this->Re - c.Re, this->Im - c.Im);
            return cc;
        }
        complex operator*(complex c) {
            complex cc(this->Re * c.Re - this->Im * c.Im, this->Re * c.Im + this->Im * c.Re);
            return cc;
        }
        friend complex operator*(double x, complex c) {
            complex cc(c.Re * x, c.Im * x);
            return cc;
        }
        // complex operator*(double x) {
        //     complex cc(this->Re * x, this->Im * x);
        //     return cc;
        // }
};

int main()
{
    complex a(3.0, 4.0); // initialize to (3,4i)
    complex c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n'; cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}