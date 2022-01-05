#include <bits/stdc++.h>

using namespace std;

class Move {
    private:
        double x;
        double y;
    public:
        Move(double a = 0, double b = 0); // sets x, y to a, b;
        void showmove() const; // shows current x, y valus
        Move add(const Move& m) const;
        /* this function adds x of m to x of invoking object to get new x, adds y of m to 
        y of invoking object to get new y, creates a new Move object initialized to new x
        , y values and returns it*/
        void reset(double a = 0, double b = 0); // resets x, y to a, b;
};

Move::Move(double a, double b) {
    this->x = a;
    this->y = b;
}

void Move::showmove() const {
    cout << this->x << ',' << this->y << endl;
}

Move Move::add(const Move& m) const {
    Move mv(this->x + m.x, this->y + m.y);
    return mv;
}

void Move::reset(double a, double b) {
    this->x = a;
    this->y = b;
}

int main() {
    Move move1;
    move1.showmove();
    double x, y;
    char tmp;
    cin >> x >> tmp >> y;
    Move move2(x, y);
    move2.showmove();
    Move move3 = move1.add(move2);
    move1 = move3;
    move1.showmove();
    move2.reset();
    move2.showmove();
    return 0;
}