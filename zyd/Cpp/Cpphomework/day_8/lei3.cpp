#include <bits/stdc++.h>
using namespace std;
class Move
{
private:
    double x;
    double y;

public:
    Move(double a = 0, double b = 0)
    {
        this->x = a;
        this->y = b;
    };                     // sets x, y to a, b
    void showmove() const; // shows current x, y values
    Move add(const Move &m) const;
    // this function adds x of m to x of invoking object to get new x, adds y of m to y of invoking object to get new y, creates a new Move object initialized to new x, y values and returns it
    void reset(double a = 0, double b = 0)
    {
        this->x = a;
        this->y = b;
    }; // resets x,y to a, b
};

void Move::showmove() const
{
    cout << this->x << "," << this->y << endl;
}

Move Move::add(const Move &m) const
{
    Move n;
    n.x = this->x + m.x;
    n.y = this->y + m.y;
    return n;
}

int main()
{
    double t1, t2;
    char a;
    // cin >> t1;
    // cin >> a;
    // cin >> t2;
    Move move1;
    move1.showmove();
    cin >> t1;
    cin >> a;
    cin >> t2;
    Move move2(t1, t2);
    move2.showmove();
    move1 = move1.add(move2);
    move1.showmove();
    move2.reset();
    move2.showmove();
}
