#include <bits/stdc++.h>
#define PI 3.14

using namespace std;

class Circle {
    public:
        double radius;
        double perimeter();
        double area();
        Circle(double r = 0);
        ~Circle();
        Circle (const Circle& obj);
};

double Circle::perimeter() {
    return 2 * PI * radius;
}

double Circle::area() {
    return PI * radius * radius;
}

Circle::Circle(double r) {
    this->radius = r;
}

Circle::~Circle() {
    this->radius = 0;
}

Circle::Circle(const Circle& obj) {
    radius = obj.radius;
}

int main() {
    Circle c;
    cin >> c.radius;
    cout << c.radius << ' ' << c.perimeter() << ' ' << c.area();
    return 0;
}