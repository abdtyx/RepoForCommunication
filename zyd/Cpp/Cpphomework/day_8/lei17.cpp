#include <iostream>

using namespace std;

class Rectangle
{
protected:
    double length;
    double high;

public:
    Rectangle(double a = 0.0, double b = 0.0) : length(a), high(b){};
    double area();
    void getR();
};

double Rectangle::area()
{
    return length * high;
}

void Rectangle::getR()
{
    cin >> length >> high;
}

class Cuboid : public Rectangle
{
private:
    double height;

public:
    Cuboid(double c = 0.0) : height(c){};
    double Vol();
    void getC();
};

double Cuboid::Vol()
{
    return height * length * high;
}

void Cuboid::getC()
{
    cin >> length >> height >> high;
}

int main()
{
    Rectangle c1;
    Cuboid c2;
    c1.getR();
    c2.getC();
    double a = c1.area();
    double b = c2.Vol();
    cout << a << " " << b;
}