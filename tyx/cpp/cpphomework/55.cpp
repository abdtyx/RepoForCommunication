#include <bits/stdc++.h>

using namespace std;

class Point {
    friend int calH(const Point&, const Point&);
    friend int calV(const Point&, const Point&);
    private:
        int x, y;
    public:
        void abd();
        Point(int i = 0, int j = 0) {
            this->x = i;
            this->y = j;
        }
};

int calH(const Point& a, const Point& b) {
    return abs(a.x - b.x);
}

int calV(const Point& a, const Point& b) {
    return abs(a.y - b.y);
}

int main() {
    int a, b;
    cin >> a >> b;
    Point point_a(a, b);
    cin >> a >> b;
    Point point_b(a, b);
    cout << calH(point_a, point_b) << ' ' << calV(point_a, point_b);
    return 0;
}