#include <bits/stdc++.h>
using namespace std;
class Point
{
    friend int calcH(const Point &, const Point &);
    friend int calcV(const Point &, const Point &);

private:
    int x, y;

public:
    Point(int i = 0, int j = 0)
    {
        this->x = i;
        this->y = j;
    }
};

int calcH(const Point &t1, const Point &t2)
{
    return abs(t1.x - t2.x);
}

int calcV(const Point &t1, const Point &t2)
{
    return abs(t1.y - t2.y);
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Point t1(a, b);
    Point t2(c, d);
    cout << calcH(t1, t2) << " " << calcV(t1, t2) << endl;
}