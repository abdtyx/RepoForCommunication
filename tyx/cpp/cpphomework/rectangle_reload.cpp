#include <bits/stdc++.h>

using namespace std;

class rectangle {
	public:
        int operator+(rectangle a) {
            return a.perimeter() + this->perimeter();
        }
        int operator*(rectangle a) {
            return a.area() + this->area();
        }
		rectangle(int a, int b, int c, int d) {
			this->lct1.first = a;
			this->lct1.second = b;
			this->lct2.first = c;
			this->lct2.second = d;
			this->edge1 = c - a;
			this->edge2 = d - b;
		}
		// ~rectangle();
		int perimeter();
		int area();
	private:
		pair<int, int> lct1, lct2;
		int edge1, edge2;
};

// rectangle::rectangle(int a, int b, int c, int d) {
// 	this->lct1.first = a;
// 	this->lct1.second = b;
// 	this->lct2.first = c;
// 	this->lct2.second = d;
// 	this->edge1 = c - a;
// 	this->edge2 = d - b;
// }

int rectangle::perimeter() {
	return 2 * (edge1 + edge2);
}

int rectangle::area() {
	return edge1 * edge2;
}

int main() {
	// rectangle rec = new rectangle;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	rectangle rec1(a, b, c, d);
	cin >> a >> b >> c >> d;
	rectangle rec2(a, b, c, d);
	// cout << rec.perimeter() << " " << rec.area();
	cout << rec1 + rec2 << ' ' << rec1 * rec2;
	return 0;
}
