#include <bits/stdc++.h>

using namespace std;

class rectangle {
	public:
		double length;
		double width;
	// public:
		// rectangle();
		double area();
};

class cuboid : public rectangle {
	public:
		double height;
	// public:
		// cuboid();
		double vol();
};

double rectangle::area() {
	return length * width;
}

double cuboid::vol() {
	return area() * height;
}

int main() {
	rectangle r1;
	cuboid c1;
	cin >> r1.length >> r1.width >> c1.length >> c1.width >> c1.height;
	cout << r1.area() << ' ' << c1.vol();
	return 0;
}
