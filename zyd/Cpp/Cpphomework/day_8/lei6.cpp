#include <iostream>

using namespace std;

class Circle
{
private:
    double r;

public:
    Circle(double _r = 0.0) : r(_r){};
    void cinr()
    {
        cin >> r;
    }
    double getr()
    {
        return r;
    }
    double getC()
    {
        double C1;
        C1 = 2 * 3.14 * r;
        return C1;
    }
    double getS()
    {
        double S1;
        S1 = 3.14 * r * r;
        return S1;
    }
    Circle circle(double b)
    {
        r = b;
    }
    Circle copyCircle(const Circle &c)
    {
        r = c.r;
    }
};

int main()
{
    Circle c;
    c.cinr();
    cout << c.getr() << " " << c.getC() << " " << c.getS() << endl;
}